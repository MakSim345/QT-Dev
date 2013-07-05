#ifndef WAVEFORMS_SERVER_H
#define WAVEFORMS_SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "WaveformsMessage.h"

class WaveformsServer: public QObject
{
Q_OBJECT
public:
  WaveformsServer(QObject * parent = 0);
  ~WaveformsServer();
  void startListening(const QString host, const int port);
  void sendMessage(const QString message);

signals:
  void messageReceived(QString);

public slots:
  void sendWaveforms();
  void acceptConnection();
  void clientDisconnected();
  void startRead();

private:
  WaveformsMessage simWaveformsMessage;
  Waveform simFlowWaveforms[10];
  Waveform simPawWaveforms[10];
  Waveform simVolWaveforms[10];
  QTcpServer server;
  QTcpSocket* client;
  quint16 blockSize;
  QString receivedMessage;
  bool connected;
  QTimer *waveformTimer;
  int seq_count;
};
#endif
