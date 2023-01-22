#include <Arduino.h>
#include <HC4067.h>

HC4067 mux1;

void setup()
{
  Serial.begin(115200);

  mux1.begin(1, A1, 3, 4, 5, 6);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  mux1.enable();
  Serial.println(mux1.read(HC4067_CHANNEL_1));
  Serial.println(mux1.read(HC4067_CHANNEL_2));
  Serial.println(mux1.read(HC4067_CHANNEL_3));
  Serial.println(mux1.read(HC4067_CHANNEL_4));
  Serial.println(mux1.read(HC4067_CHANNEL_5));
  mux1.disable();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
