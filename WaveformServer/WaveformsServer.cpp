#include "WaveformsServer.h"
#include <iostream>
#include <ostream>
#include <sstream>
using namespace std;

WaveformsServer::WaveformsServer(QObject* parent): QObject(parent)
{
	std::cout << "in Server ctor" << std::endl;
	connected = false;
	
	connect(&server, SIGNAL(newConnection()),
		this, SLOT(acceptConnection()));

	simPawWaveforms[0].name = "Paw";
	simPawWaveforms[1].name = "Paw";
	simPawWaveforms[2].name = "Paw";
	simPawWaveforms[3].name = "Paw";
	simPawWaveforms[4].name = "Paw";
	simPawWaveforms[5].name = "Paw";
	simPawWaveforms[6].name = "Paw";
	simPawWaveforms[7].name = "Paw";
	simPawWaveforms[8].name = "Paw";
	simPawWaveforms[9].name = "Paw";

	simFlowWaveforms[0].name = "Flow";
	simFlowWaveforms[1].name = "Flow";
	simFlowWaveforms[2].name = "Flow";
	simFlowWaveforms[3].name = "Flow";
	simFlowWaveforms[4].name = "Flow";
	simFlowWaveforms[5].name = "Flow";
	simFlowWaveforms[6].name = "Flow";
	simFlowWaveforms[7].name = "Flow";
	simFlowWaveforms[8].name = "Flow";
	simFlowWaveforms[9].name = "Flow";

	simVolWaveforms[0].name = "Vol";
	simVolWaveforms[1].name = "Vol";
	simVolWaveforms[2].name = "Vol";
	simVolWaveforms[3].name = "Vol";
	simVolWaveforms[4].name = "Vol";
	simVolWaveforms[5].name = "Vol";
	simVolWaveforms[6].name = "Vol";
	simVolWaveforms[7].name = "Vol";
	simVolWaveforms[8].name = "Vol";
	simVolWaveforms[9].name = "Vol";

    int pawData[] = {400,490,580,670,760,850,940,1030,1120,1210,2200,2290,2380,2470,2560,2650,2740,2830,2920,3010,3100,3190,3280,3370,3460,3550,3640,3730,3820,3910,2229,2096,1969,1849,1734,1625,1521,1423,1329,1240,1155,1074,997,924,855,789,726,666,609,555,109,79,51,24,-1,-25,-48,-70,-91,-111,-130,-148,-165,-182,-197,-212,-226,-239,-252,-264,-364,-370,-377,-383,-388,-394,-399,-404,-408,-413,-417,-421,-425,-429,-432,-435,-438,-441,-444,-447,-500,-410,-320,-230,-140,-50,40,130,220,310};
	int flowData[] = {70000,66586,63338,60249,57311,54516,51857,49328,46922,44633,42457,40386,38416,36543,34760,33065,31453,29919,28459,27071,15619,14857,14132,13443,12787,12164,11570,11006,10469,9959,9473,9011,8571,8153,7756,7377,7018,6675,6350,6040,3485,3315,3153,2999,2853,2714,2581,2455,2336,2222,2113,2010,1912,1819,1730,1646,1565,1489,1416,1347,777,739,703,669,636,605,576,547,521,495,0,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000,-70000};
	int volData[] = {0,0,0,0,0,0,0,0,0,0,5000,10000,15000,20000,25000,30000,35000,40000,45000,50000,160000,170000,180000,195000,210000,225000,240000,255000,270000,285000,300000,310000,320000,330000,340000,350000,360000,370000,380000,390000,475000,480000,485000,490000,495000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000,470000,465000,460000,455000,450000,440000,430000,420000,410000,400000,390000,380000,370000,360000,350000,340000,330000,320000,310000,300000,150000,140000,130000,120000,110000,100000,90000,80000,70000,60000,50000,45000,40000,35000,30000,25000,20000,15000,10000,5000};



	for (int i=0; i < 10; i++) {
		simPawWaveforms[0].data[i] = pawData[i];
		simPawWaveforms[1].data[i] = pawData[i+10];
		simPawWaveforms[2].data[i] = pawData[i+20];
		simPawWaveforms[3].data[i] = pawData[i+30];
		simPawWaveforms[4].data[i] = pawData[i+40];
		simPawWaveforms[5].data[i] = pawData[i+50];
		simPawWaveforms[6].data[i] = pawData[i+60];
		simPawWaveforms[7].data[i] = pawData[i+70];
		simPawWaveforms[8].data[i] = pawData[i+80];
		simPawWaveforms[9].data[i] = pawData[i+90];
		simFlowWaveforms[0].data[i] = flowData[i];
		simFlowWaveforms[1].data[i] = flowData[i+10];
		simFlowWaveforms[2].data[i] = flowData[i+20];
		simFlowWaveforms[3].data[i] = flowData[i+30];
		simFlowWaveforms[4].data[i] = flowData[i+40];
		simFlowWaveforms[5].data[i] = flowData[i+50];
		simFlowWaveforms[6].data[i] = flowData[i+60];
		simFlowWaveforms[7].data[i] = flowData[i+70];
		simFlowWaveforms[8].data[i] = flowData[i+80];
		simFlowWaveforms[9].data[i] = flowData[i+90];
		simVolWaveforms[0].data[i] = volData[i];
		simVolWaveforms[1].data[i] = volData[i+10];
		simVolWaveforms[2].data[i] = volData[i+20];
		simVolWaveforms[3].data[i] = volData[i+30];
		simVolWaveforms[4].data[i] = volData[i+40];
		simVolWaveforms[5].data[i] = volData[i+50];
		simVolWaveforms[6].data[i] = volData[i+60];
		simVolWaveforms[7].data[i] = volData[i+70];
		simVolWaveforms[8].data[i] = volData[i+80];
		simVolWaveforms[9].data[i] = volData[i+90];
	}

	simWaveformsMessage.flow = simFlowWaveforms[0];
	simWaveformsMessage.paw = simPawWaveforms[0];
	simWaveformsMessage.vol = simVolWaveforms[0];
	simWaveformsMessage.seq_id = 0;

	//create the waveform timer but dont start it yet
	waveformTimer = new QTimer(this);
    connect(waveformTimer, SIGNAL(timeout()), this, SLOT(sendWaveforms()));
	seq_count = 0;
}

WaveformsServer::~WaveformsServer()
{
	std::cout << "in Server close()" << std::endl;
	server.close();
}

void WaveformsServer::clientDisconnected() {
	waveformTimer->stop();
	connected = false;
}

void WaveformsServer::startListening(QString host, int port) {
	std::cout << "in Server startListening" << std::endl;
	blockSize = 0;
	server.listen(QHostAddress(host), port);
}

void WaveformsServer::sendMessage(QString message) {
	std::cout << "in Server sendMessage" << message.toStdString() << std::endl;

	/*messageEvent = new MessageEvent("Server",message.toStdString());

	std::ostringstream archive_stream;
	boost::archive::text_oarchive archive(archive_stream);
	archive << messageEvent;
	char * outbound_data = archive_stream.str();
	//boost::asio::async_write(socket_, 
    //boost::asio::buffer(outbound_data_), handler);
	*/
	//std::stringstream ss;
	//boost::archive::text_oarchive archive(ss);
	//archive << simWaveformsMessage;

	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
	client->write(block);
}

void WaveformsServer::acceptConnection()
{
  std::cout << "in Server acceptConnection" << std::endl;
  if (!connected) {
	client = server.nextPendingConnection();
	connected = true;
	connect(client, SIGNAL(readyRead()),
			this, SLOT(startRead()));
	connect(client, SIGNAL(disconnected()),
		this, SLOT(clientDisconnected()));

	//now start the timer that sends waveforms
    waveformTimer->start(200);
  }
}

void WaveformsServer::sendWaveforms()
{
	seq_count++;
	if (seq_count > 999) {
		//reset the seq number
		seq_count = 0;
	}
	simWaveformsMessage.seq_id = seq_count;
	simWaveformsMessage.flow = simFlowWaveforms[seq_count%10];
	simWaveformsMessage.paw = simPawWaveforms[seq_count%10];
	simWaveformsMessage.vol = simVolWaveforms[seq_count%10];

	std::stringstream ss;
	boost::archive::text_oarchive archive(ss);
	archive << simWaveformsMessage;

	QString tmpString;
	tmpString = tmpString.fromStdString(ss.str());
	std::cout << "in WaveformsServer sendWaveforms" << ss.str() << std::endl;

	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
	out << tmpString;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
	client->write(block);
}

void WaveformsServer::startRead()
{
	std::cout << "in Server startRead" << std::endl;
 	QDataStream in(client);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0) {
		if (client->bytesAvailable() < (int)sizeof(quint16)) {
			std::cout << "bytes available " << client->bytesAvailable() << " is less than quint16 size  " << (int)sizeof(quint16)<< std::endl;
            return;
		}
        in >> blockSize;
		std::cout << "blocksize " << blockSize << std::endl;
    }
	    
	//blockSize = 19;
	if (client->bytesAvailable() < blockSize) {
		std::cout << "bytes available " << client->bytesAvailable() << " is less than blocksize " << blockSize << std::endl;
        return;
	}
	blockSize = 0;
    //QString nextMessage;
	//TODO should I free the old memory for receivedMessage?
	receivedMessage = "";
    in >> receivedMessage;
	std::cout << "received message [" << receivedMessage.toStdString() << "]" << std::endl;

	//tell our listeners
	emit messageReceived(receivedMessage);

	// allow the client to disconnect
	if (receivedMessage == "disconnect" ||
		receivedMessage == "exit") {
			client->disconnect();
	}
}
