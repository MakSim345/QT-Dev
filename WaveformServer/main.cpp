#include <QCoreApplication>
#include "WaveformsServer.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	WaveformsServer server;
    int port_number = 5050;
    QString ip_addr = "127.0.0.1";
	if (argc < 3) 
    {
		std::cout << "Usage: WaveformServer <host_ip> <port_number>" << std::endl;
		std::cout << "Default values: WaveformServer 127.0.0.1 5050" << std::endl;
	}
    else
    {
	    std::cout << "In main, started listening to host: " << argv[1] << ":" <<argv[2] << std::endl;
        //port_number = argv[1];
        //ip_addr = argv[2];
    }
	
    // server.startListening(argv[1], atoi(argv[2]));
    server.startListening(ip_addr, port_number);

	return a.exec();
}
