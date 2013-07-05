#include "waveformclient.h"

WaveformClient::WaveformClient(QWidget *parent)
	: QWidget(parent)
{
	std::cout << "in WaveformClient ctor()" << std::endl;
	QLabel *hostLabel = new QLabel(tr("Host:"));
     hostLine = new QLineEdit;
	 hostLine->setText("localhost");

	 QLabel *portLabel = new QLabel(tr("Port:"));
     portLine = new QLineEdit;
	 portLine->setText("5050");

	 QLabel *sendLabel = new QLabel(tr("Send:"));
     sendLine = new QLineEdit;
     //sendLine->setReadOnly(true);

     QLabel *receivedLabel = new QLabel(tr("Received:"));
     receivedText = new QTextEdit;
     receivedText->setReadOnly(true);

     sendButton = new QPushButton(tr("&Send"));
     sendButton->show();

	 connectButton = new QPushButton(tr("&Connect"));
     connectButton->show();
	 connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));

     connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
	 connect(sendLine, SIGNAL(returnPressed()), this, SLOT(sendMessage()));

     QGridLayout *mainLayout = new QGridLayout;
	 mainLayout->addWidget(hostLabel, 0, 0, Qt::AlignTop);
     mainLayout->addWidget(hostLine, 0, 1);
	 mainLayout->addWidget(portLabel, 1, 0, Qt::AlignTop);
     mainLayout->addWidget(portLine, 1, 1);
	 mainLayout->addWidget(connectButton, 1, 2);
	 mainLayout->addWidget(receivedLabel, 2, 0, Qt::AlignTop);
     mainLayout->addWidget(receivedText, 2, 1);
     mainLayout->addWidget(sendLabel, 3, 0);
     mainLayout->addWidget(sendLine, 3, 1);
     mainLayout->addWidget(sendButton, 3, 2);
     //mainLayout->addLayout(buttonLayout2, 3, 1);
     setLayout(mainLayout);
     setWindowTitle(tr("Simple Waveform Client"));
}

WaveformClient::~WaveformClient()
{

}

void WaveformClient::serverDisconnected() {
	connectButton->setEnabled(true);
}

void WaveformClient::appendMessage() {
	std::cout << "in WaveformClient appendText()" << std::endl;
	QString tmpQStr;
	//std::stringstream ss;
	//ss << "Sequence Id:" << receivedMessage.seq_id << "Flow:" << receivedMessage.flow.data << std::endl;
	//tmpQStr = tmpQStr.fromStdString(ss.str());
	//receivedText->append(tmpQStr);
	for (int i=0; i < 10; i++) {
		tmpQStr = tmpQStr.fromStdString(getPawString(receivedMessage.paw.data[i]));
		receivedText->append(tmpQStr);
	}
}

std::string WaveformClient::getPawString(int y) {
	std::string returnString;
	y = y + 1000; // remove negatives
	int height = y / 200; 
	for (int i = 0; i < height; i++) {
		returnString = returnString + "*";
	}
	return returnString;
}

void WaveformClient::connectToServer() {
	std::cout << "in WaveformClient connect to server" << std::endl;
	blockSize = 0;
	try {
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
		connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
		tcpSocket->connectToHost(hostLine->text(),portLine->text().toInt());

		connectButton->setEnabled(false);
	}
	catch (std::exception& e)
	{
	    std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "finished connect to server" << std::endl;
}

void WaveformClient::readMessage () {
	std::cout << "in WaveformClient readMessage" << std::endl;
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16)) {
			std::cout << "bytes available " << tcpSocket->bytesAvailable() << " is less than quint16 size  " << (int)sizeof(quint16)<< std::endl;
            return;
		}
        in >> blockSize;
		std::cout << "blocksize " << blockSize << std::endl;
    }
    
	if (tcpSocket->bytesAvailable() < blockSize) {
		std::cout << "bytes available " << tcpSocket->bytesAvailable() << " is less than blocksize " << blockSize << std::endl;
        return;
	}
	blockSize = 0;


	QString tmpString;
    in >> tmpString;

	std::stringstream ss;
	ss << tmpString.toStdString();
	boost::archive::text_iarchive archive(ss);
	archive >> receivedMessage;

	std::cout << "received message [" << tmpString.toStdString() << "]" << std::endl;
	std::cout << "received message [" << receivedMessage.seq_id << "]" << std::endl;

	QTimer::singleShot(0, this, SLOT(appendMessage()));
}

 void WaveformClient::sendMessage()
 {
	QString message = sendLine->text();
	std::cout << "in sendMessage line " << message.toStdString() << std::endl;
	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
	tcpSocket->write(block);
 }
