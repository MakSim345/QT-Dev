#ifndef WAVEFORMCLIENT_H
#define WAVEFORMCLIENT_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QtNetwork/QTcpSocket>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <iostream>
#include <sstream>

#include "WaveformsMessage.h"

class WaveformClient : public QWidget
{
	Q_OBJECT

public:
	WaveformClient(QWidget *parent = 0);
	~WaveformClient();

private:
	std::string getPawString(int y);

public slots:
	void readMessage();
	void sendMessage();
	void appendMessage();
	void connectToServer();
	void serverDisconnected();

private:
	QPushButton *sendButton;
	QPushButton *connectButton;
	QLineEdit *hostLine;
	QLineEdit *portLine;
    QLineEdit *sendLine;
    QTextEdit *receivedText;
    WaveformsMessage receivedMessage;
	QTcpSocket *tcpSocket;
	quint16 blockSize;
};

#endif // WAVEFORMCLIENT_H
