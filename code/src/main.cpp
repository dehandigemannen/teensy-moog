#include <Arduino.h>
#include <HC4067.h>

#define MUX_1_COM 35
#define MUX_1_ENABLE 8

#define MUX_2_COM 36
#define MUX_2_ENABLE 7

#define MUX_3_COM 37
#define MUX_3_ENABLE 6

#define MUX_S0 32
#define MUX_S1 31
#define MUX_S2 30
#define MUX_S3 29

HC4067 mux1;
HC4067 mux2;
HC4067 mux3;

void setup()
{
  Serial.begin(115200);

  mux1.begin(MUX_1_ENABLE, MUX_1_COM, MUX_S0, MUX_S1, MUX_S2, MUX_S3);
  mux2.begin(MUX_2_ENABLE, MUX_2_COM, MUX_S0, MUX_S1, MUX_S2, MUX_S3);
  mux3.begin(MUX_3_ENABLE, MUX_3_COM, MUX_S0, MUX_S1, MUX_S2, MUX_S3);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);

  mux1.enable();
  Serial.println(mux1.read(HC4067_CHANNEL_1));
  Serial.println(mux1.read(HC4067_CHANNEL_2));
  Serial.println(mux1.read(HC4067_CHANNEL_3));
  Serial.println(mux1.read(HC4067_CHANNEL_4));
  Serial.println(mux1.read(HC4067_CHANNEL_5));
  Serial.println(mux1.read(HC4067_CHANNEL_6));
  Serial.println(mux1.read(HC4067_CHANNEL_7));
  Serial.println(mux1.read(HC4067_CHANNEL_8));
  Serial.println(mux1.read(HC4067_CHANNEL_9));
  Serial.println(mux1.read(HC4067_CHANNEL_10));
  Serial.println(mux1.read(HC4067_CHANNEL_11));
  Serial.println(mux1.read(HC4067_CHANNEL_12));
  Serial.println(mux1.read(HC4067_CHANNEL_13));
  Serial.println(mux1.read(HC4067_CHANNEL_14));
  Serial.println(mux1.read(HC4067_CHANNEL_15));
  Serial.println(mux1.read(HC4067_CHANNEL_16));
  mux1.disable();
  Serial.println("--------");

  mux2.enable();
  Serial.println(mux2.read(HC4067_CHANNEL_1));
  Serial.println(mux2.read(HC4067_CHANNEL_2));
  Serial.println(mux2.read(HC4067_CHANNEL_3));
  Serial.println(mux2.read(HC4067_CHANNEL_4));
  Serial.println(mux2.read(HC4067_CHANNEL_5));
  Serial.println(mux2.read(HC4067_CHANNEL_6));
  Serial.println(mux2.read(HC4067_CHANNEL_7));
  Serial.println(mux2.read(HC4067_CHANNEL_8));
  Serial.println(mux2.read(HC4067_CHANNEL_9));
  Serial.println(mux2.read(HC4067_CHANNEL_10));
  Serial.println(mux2.read(HC4067_CHANNEL_11));
  Serial.println(mux2.read(HC4067_CHANNEL_12));
  Serial.println(mux2.read(HC4067_CHANNEL_13));
  Serial.println(mux2.read(HC4067_CHANNEL_14));
  Serial.println(mux2.read(HC4067_CHANNEL_15));
  Serial.println(mux2.read(HC4067_CHANNEL_16));
  mux2.disable();
  Serial.println("--------");

  mux3.enable();
  Serial.println(mux3.read(HC4067_CHANNEL_1));
  Serial.println(mux3.read(HC4067_CHANNEL_2));
  Serial.println(mux3.read(HC4067_CHANNEL_3));
  Serial.println(mux3.read(HC4067_CHANNEL_4));
  Serial.println(mux3.read(HC4067_CHANNEL_5));
  Serial.println(mux3.read(HC4067_CHANNEL_6));
  Serial.println(mux3.read(HC4067_CHANNEL_7));
  Serial.println(mux3.read(HC4067_CHANNEL_8));
  Serial.println(mux3.read(HC4067_CHANNEL_9));
  Serial.println(mux3.read(HC4067_CHANNEL_10));
  Serial.println(mux3.read(HC4067_CHANNEL_11));
  Serial.println(mux3.read(HC4067_CHANNEL_12));
  Serial.println(mux3.read(HC4067_CHANNEL_13));
  Serial.println(mux3.read(HC4067_CHANNEL_14));
  Serial.println(mux3.read(HC4067_CHANNEL_15));
  Serial.println(mux3.read(HC4067_CHANNEL_16));
  mux3.disable();
  Serial.println("--------");

  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
