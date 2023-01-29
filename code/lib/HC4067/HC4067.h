#ifndef HC4067_h
#define HC4067_h
#endif

#include <Arduino.h>

#define HC4067_CHANNEL_0 0
#define HC4067_CHANNEL_1 1
#define HC4067_CHANNEL_2 2
#define HC4067_CHANNEL_3 3
#define HC4067_CHANNEL_4 4
#define HC4067_CHANNEL_5 5
#define HC4067_CHANNEL_6 6
#define HC4067_CHANNEL_7 7
#define HC4067_CHANNEL_8 8
#define HC4067_CHANNEL_9 9
#define HC4067_CHANNEL_10 10
#define HC4067_CHANNEL_11 11
#define HC4067_CHANNEL_12 12
#define HC4067_CHANNEL_13 13
#define HC4067_CHANNEL_14 14
#define HC4067_CHANNEL_15 15

class HC4067
{
public:
  void begin(uint8_t en, int8_t sig, int8_t s0, int8_t s1, int8_t s2, int8_t s3);
  void enable();
  void disable();
  int16_t read(int8_t chan_pin);

private:
  uint8_t enable_pin;
  uint8_t sig_pin;

  uint8_t s0;
  uint8_t s1;
  uint8_t s2;
  uint8_t s3;

  void setChannel(int8_t chan_pin);
};
