#include <QtCore>
#include <QApplication>
#include "MyThread.h"
#include "HasherWidget.h"

HasherWidget::HasherWidget(QWidget *parent)
     : QWidget(parent)
     , fileNameStr("Thread_Hasher.sdf")
{
    // = QTime::currentTime();
    timeStamp.start();
    // timeStamp.elapsed()
    
    prb = new QProgressBar();
    prb->setAlignment(Qt::AlignHCenter);
    prb->setMaximum(1000);
    filenameEdit = new QLineEdit(fileNameStr);
    resultEdit = new QLineEdit();

    QLabel *lblFileName = new QLabel("File to hash:");
    QLabel *lblHashResult = new QLabel("File hash:");

    _exit_button = new QPushButton("Exit");
    _hash_button = new QPushButton("Calculate Hash");
    _hash_button->setMinimumSize(150, 50);
    _exit_button->setMinimumSize(150, 50);
    // _counter = new Counter();    
    
    vlayout = new QVBoxLayout();
    QHBoxLayout *hlayoutFile = new QHBoxLayout();
    QHBoxLayout *hlayoutHash = new QHBoxLayout();

    QHBoxLayout *hlayoutButtons = new QHBoxLayout();
    
    hlayoutFile->addWidget(lblFileName);
    hlayoutFile->addWidget(filenameEdit);

    vlayout->addLayout(hlayoutFile);    
    
    hlayoutHash->addWidget(lblHashResult);
    hlayoutHash->addWidget(resultEdit);

    vlayout->addLayout(hlayoutHash);

    hlayoutButtons->addWidget(_hash_button);
    hlayoutButtons->addWidget(_exit_button);
    vlayout->addWidget(prb);
    vlayout->addLayout(hlayoutButtons);
    
    setLayout(vlayout);
    
    hasher = new HasherThread( this );

    this->setConnections();     
}

void HasherWidget::setConnections()
{   
    connect(_exit_button, SIGNAL(clicked()), this, SLOT (close()) );
    connect(hasher, SIGNAL(progress(int)), prb, SLOT(setValue(int)) );
    connect(_hash_button, SIGNAL(clicked()), SLOT(hashPressed()) );
    connect(hasher, SIGNAL(completed(const QString &)), resultEdit, SLOT(setText(const QString &)) );
    connect(hasher, SIGNAL(error(const QString &)), resultEdit, SLOT(setText(const QString &)) );
}


void HasherWidget::hashPressed()
{
    if (filenameEdit->text().isEmpty())
        return;

    hasher->setFilename(filenameEdit->text());
    hasher->setAlgorithm(QCryptographicHash::Md5);
    /*
    switch(algorithmCombo->currentIndex() ) 
    {
    case 0:
        hasher->setAlgorithm( QCryptographicHash::Sha1 );
        break;
    case 1:
        hasher->setAlgorithm( QCryptographicHash::Md5 );
        break;
    case 2:
        hasher->setAlgorithm( QCryptographicHash::Md4 );
        break;
    }
    */
    resultEdit->setText( QString("Working...") );
    hasher->start();
}
