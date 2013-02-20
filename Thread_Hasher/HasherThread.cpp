#include <QtCore>
#include "HasherThread.h"


HasherThread::HasherThread(QObject *parent) :
    QThread(parent)
{
    hasher = new QCryptographicHash( QCryptographicHash::Sha1 );
}
    

HasherThread::~HasherThread()
{
    delete hasher;
}

void HasherThread::setFilename( const QString &filename )
{
    this->filename = filename;
}

void HasherThread::setAlgorithm( QCryptographicHash::Algorithm alg )
{
    delete hasher;
    hasher = new QCryptographicHash( alg );
}

void HasherThread::run()
{
    QFile f( filename );
    if ( !f.open(QIODevice::ReadOnly) ) 
    {
        emit error( QString("Unable to open file %1").arg(filename) );
        return;
    }

    hasher->reset();

    char buffer[16*1024];
    qint64 count;
    qint64 summator = 0;
    int _progress = 0;
    do {
        count = f.read( buffer, sizeof(buffer) );
        summator += count;
        _progress = (int)((float(summator)/f.size()) * 1000);
        //qDebug() << "HasherThread::run " << count;
        // qDebug() << "HasherThread::run " << f.size() << " - " << summator << " - " << float(summator)/f.size();
        // qDebug() << "HasherThread::progress " << _progress;
        emit  progress(_progress);

        if ( count == -1 ) 
        {
            emit error( QString("Read error") );
            break;
        }
        hasher->addData( buffer, count );

    } while( !f.atEnd() );

    emit completed( hasher->result().toHex() );
}
