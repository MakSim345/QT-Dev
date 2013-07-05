#ifndef WAVEFORMS_MESSAGE_H
#define WAVEFORMS_MESSAGE_H
#include <string>

struct Waveform
{
  std::string name;
  int data[10];

  template <typename Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar & name;
    ar & data;
  }
};

struct WaveformsMessage
{
  int seq_id;
  Waveform paw;
  Waveform vol;
  Waveform flow;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar & seq_id;
    ar & paw;
    ar & vol;
	ar & flow;
  }
};

#endif