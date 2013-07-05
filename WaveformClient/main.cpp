#include "waveformclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	WaveformClient waveformClient;
	waveformClient.show();
	return app.exec();
}