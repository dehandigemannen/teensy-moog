#include "HC4067.h"

const int truthTable[16][4] = {
    {0, 0, 0, 0}, // 0
    {1, 0, 0, 0}, // 1
    {0, 1, 0, 0}, // 2
    {1, 1, 0, 0}, // 3
    {0, 0, 1, 0}, // 4
    {1, 0, 1, 0}, // 5
    {0, 1, 1, 0}, // 6
    {1, 1, 1, 0}, // 7
    {0, 0, 0, 1}, // 8
    {1, 0, 0, 1}, // 9
    {0, 1, 0, 1}, // 10
    {1, 1, 0, 1}, // 11
    {0, 0, 1, 1}, // 12
    {1, 0, 1, 1}, // 13
    {0, 1, 1, 1}, // 14
    {1, 1, 1, 1}, // 15
};

void HC4067::begin(uint8_t en, int8_t sig, int8_t input_s0, int8_t input_s1, int8_t input_s2, int8_t input_s3)
{
  enable_pin = en;
  sig_pin = sig;

  pinMode(enable_pin, OUTPUT);
  pinMode(sig_pin, INPUT);

  pinMode(input_s0, OUTPUT);
  pinMode(input_s1, OUTPUT);
  pinMode(input_s2, OUTPUT);
  pinMode(input_s3, OUTPUT);

  s0 = input_s0;
  s1 = input_s1;
  s2 = input_s2;
  s3 = input_s3;
}

void HC4067::enable()
{
  digitalWrite(enable_pin, LOW);
}

void HC4067::disable()
{
  digitalWrite(enable_pin, HIGH);
}

int16_t HC4067::read(int8_t channel_pin)
{
  HC4067::setChannel(channel_pin);
  return analogRead(sig_pin);
}

void HC4067::setChannel(int8_t channel_pin)
{
  digitalWrite(s0, truthTable[channel_pin][0]);
  digitalWrite(s1, truthTable[channel_pin][1]);
  digitalWrite(s2, truthTable[channel_pin][2]);
  digitalWrite(s3, truthTable[channel_pin][3]);
}
