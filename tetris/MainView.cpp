#include "MainView.h"

MainView::MainView(QWidget *parent)
    : QWidget(parent)
{   
    board = new TetrixBoard;

    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);

    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);

    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);

}

QLabel *MainView::createLabel(const QString &text)
{   
    /* Function simply creates a new label on the heap, gives it an 
     * appropriate alignment, and returns it to the caller.
     * Since each label will be used in the widget's layout, 
     * it will become a child of the TetrixWindow widget and, 
     * as a result, it will be deleted when the window is deleted.*/
    
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}

void MainView::setConnections()
{
    // connect(startButton,  &QPushButton::clicked, this->board, &TetrixBoard::start);
    // connect(pauseButton,  &QPushButton::clicked, this->board, &TetrixBoard::pause);
    connect(quitButton,  &QPushButton::clicked, qApp, &QApplication::quit);

    //connect(bRnd, SIGNAL(clicked ()), this, SLOT (setValue()));
    //connect(timer, SIGNAL(timeout()), lifeWgt, SLOT(newGeneration()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(updateLabels()));

    // connect(bQuit, SIGNAL(clicked()), this, SLOT(quit()));
    // connect(bStart, SIGNAL(clicked()), this, SLOT (StartMyThread()));
    // connect(bQuit, SIGNAL(clicked()), &app, SLOT(quit()));
    // connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

}

MainView::~MainView()
{

}
