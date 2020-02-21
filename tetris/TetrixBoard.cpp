#include "TetrixBoard.h"

TetrixBoard::TetrixBoard(QWidget *parent)
    : QFrame(parent)
{
    this->setFrameStyle(QFrame::Panel || QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    isStarted = false;
    isPaused = false;
    this->clearBoard();

    nextPiece.setRandomShape();
}

void TetrixBoard::setNextPieceLabel(QLabel *label)
{
    nextPieceLabel = label;
}

QSize TetrixBoard::sizeHint() const
{
    return QSize(BoardWidth * 15 + frameWidth() * 2,
        BoardHeight * 15 + frameWidth() * 2);
}

QSize TetrixBoard::minimumSizeHint() const
{
    return QSize(BoardWidth * 5 + frameWidth() * 2,
        BoardHeight * 5 + frameWidth() * 2);
}

void TetrixBoard::start()
{
    if (isPaused)
        return;

    isStarted = true;
    isWaitingAfterLine = false;
    numLinesRemoved = 0;
    numPiecesDropped = 0;
    score = 0;
    level = 1;
    clearBoard();

    emit linesRemovedChanged(numLinesRemoved);
    emit scoreChanged(score);
    emit levelChanged(level);

    newPiece();
    timer.start(timeoutTime(), this);
}

void TetrixBoard::pause()
{
    if (!isStarted)
        return;

    isPaused = !isPaused;
    if (isPaused) 
    {
        timer.stop();
    } 
    else 
    {
        timer.start(timeoutTime(), this);
    }
    update();
}

void TetrixBoard::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();
    int boardTop = rect.bottom() - BoardHeight*squareHeight();

    for (int i = 0; i < BoardHeight; ++i) 
    {
        for (int j = 0; j < BoardWidth; ++j) 
        {
            TetrixShape shape = shapeAt(j, BoardHeight - i - 1);
            if (shape != NoShape)
            {
                drawSquare(painter, rect.left() + j * squareWidth(), 
                                    boardTop + i * squareHeight(), shape);
            }
        }
    }

    if (curPiece.shape() != NoShape) 
    {
        for (int i = 0; i < 4; ++i) 
        {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            drawSquare(painter, rect.left() + x * squareWidth(),
                        boardTop + (BoardHeight - y - 1) * squareHeight(), curPiece.shape());
        }
    }
}

void TetrixBoard::keyPressEvent(QKeyEvent *event)
{
    if (!isStarted || isPaused || curPiece.shape() == NoShape) 
    {
        QFrame::keyPressEvent(event);
        return;
    }
    
    switch (event->key()) 
    {
    case Qt::Key_Left:
        tryMove(curPiece, curX - 1, curY);
        break;
    case Qt::Key_Right:
        tryMove(curPiece, curX + 1, curY);
        break;
    case Qt::Key_Down:
        tryMove(curPiece.rotatedRight(), curX, curY);
        break;
    case Qt::Key_Up:
        tryMove(curPiece.rotatedLeft(), curX, curY);
        break;
    case Qt::Key_Space:
        dropDown();
        break;
    case Qt::Key_D:
        oneLineDown();
        break;
    default:
        QFrame::keyPressEvent(event);
    }
}

void TetrixBoard::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) 
    {
        if (isWaitingAfterLine) 
        {
            isWaitingAfterLine = false;
            newPiece();
            timer.start(timeoutTime(), this);
        } 
        else 
        {
            oneLineDown();
        }
    } 
    else 
    {
        QFrame::timerEvent(event);
    }
}

void TetrixBoard::clearBoard()
{
    for (int i = 0; i < BoardHeight * BoardWidth; ++i)
    {
        board[i] = NoShape;
    }
}