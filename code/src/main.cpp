#include <Arduino.h>
#include <HC4067.h>
#include <Helpers.h>

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

int tune = 0;
int glide = 0;
int filter_eg = 0; // switch

int mod_mix = 0;
int modulation = 0; // switch
int noise_lfo = 0;  // switch

int osc_1_rang = 0;
int osc_2_rang = 0;
int osc_3_fr = 0;

int osc_3_control = 0; // switch
int osc_2_fr = 0;
int osc_3_range = 0;

int osc_1_wave = 0;
int osc_2_wave = 0;
int osc_3_wave = 0;

int osc_1_vol = 0;
int osc_2_vol = 0;
int osc_3_vol = 0;

int noise_color = 0; // switch
int ext_vol = 0;
int noise_vol = 0;

int filter_mod = 0;   // switch
int keyboard_c_1 = 0; // switch
int keyboard_c_2 = 0; // switch

int cutoff = 0;
int attack_time = 0;
int mod_attack_time = 0;

int emphasis = 0;
int decay_time = 0;
int mod_decay_time = 0;

int amount_of_contour = 0;
int sustain = 0;
int mod_sustain = 0;

int lfo_rate = 0;
int decay = 0;        // switch
int glide_switch = 0; // switch

int main_vol = 0;

void logInput(String label, int value)
{
  Serial.print(label);
  Serial.print(": ");
  Serial.println(value);
}

void updateMux1Values()
{
  mux1.enable();

  tune = mux1.read(HC4067_CHANNEL_7);
  glide = mux1.read(HC4067_CHANNEL_6);
  filter_eg = mux1.read(HC4067_CHANNEL_5); // switch

  mod_mix = mux1.read(HC4067_CHANNEL_4);
  modulation = mux1.read(HC4067_CHANNEL_2); // switch
  noise_lfo = mux1.read(HC4067_CHANNEL_1);  // switch

  osc_1_rang = mux1.read(HC4067_CHANNEL_0);
  osc_2_rang = mux1.read(HC4067_CHANNEL_8);
  osc_3_fr = mux1.read(HC4067_CHANNEL_14);

  osc_3_control = mux1.read(HC4067_CHANNEL_3); // switch
  osc_2_fr = mux1.read(HC4067_CHANNEL_13);
  osc_3_range = mux1.read(HC4067_CHANNEL_9);

  osc_1_wave = mux1.read(HC4067_CHANNEL_12);
  osc_2_wave = mux1.read(HC4067_CHANNEL_11);
  osc_3_wave = mux1.read(HC4067_CHANNEL_10);

  mux1.disable();
}

void updateMux2Values()
{
  mux2.enable();

  osc_1_vol = mux2.read(HC4067_CHANNEL_7);
  osc_2_vol = mux2.read(HC4067_CHANNEL_6);
  osc_3_vol = mux2.read(HC4067_CHANNEL_5);

  noise_color = mux2.read(HC4067_CHANNEL_4); // switch
  ext_vol = mux2.read(HC4067_CHANNEL_3);
  noise_vol = mux2.read(HC4067_CHANNEL_2);

  filter_mod = mux2.read(HC4067_CHANNEL_15);   // switch
  keyboard_c_1 = mux2.read(HC4067_CHANNEL_14); // switch
  keyboard_c_2 = mux2.read(HC4067_CHANNEL_13); // switch

  cutoff = mux2.read(HC4067_CHANNEL_12);
  attack_time = mux2.read(HC4067_CHANNEL_11);
  mod_attack_time = mux2.read(HC4067_CHANNEL_10);

  mux2.disable();
}

void updateMux3Values()
{
  mux3.enable();

  emphasis = mux3.read(HC4067_CHANNEL_7);
  decay_time = mux3.read(HC4067_CHANNEL_6);
  mod_decay_time = mux3.read(HC4067_CHANNEL_5);

  amount_of_contour = mux3.read(HC4067_CHANNEL_15);
  sustain = mux3.read(HC4067_CHANNEL_14);
  mod_sustain = mux3.read(HC4067_CHANNEL_13);

  lfo_rate = mux3.read(HC4067_CHANNEL_10);
  decay = mux3.read(HC4067_CHANNEL_11);        // switch
  glide_switch = mux3.read(HC4067_CHANNEL_12); // switch

  main_vol = mux3.read(HC4067_CHANNEL_9);

  mux3.disable();
}

void logInputInfo()
{
  logInput("tune", tune);
  logInput("glide", glide);
  logInput("filter_eg", filter_eg);

  logInput("mod_mix", mod_mix);
  logInput("modulation", modulation);
  logInput("noise_lfo", noise_lfo);

  logInput("osc_1_rang", osc_1_rang);
  logInput("osc_2_rang", osc_2_rang);
  logInput("osc_3_fr", osc_3_fr);

  logInput("osc_3_control", osc_3_control);
  logInput("osc_2_fr", osc_2_fr);
  logInput("osc_3_range", osc_3_range);

  logInput("osc_1_wave", osc_1_wave);
  logInput("osc_2_wave", osc_2_wave);
  logInput("osc_3_wave", osc_3_wave);

  logInput("osc_1_vol", osc_1_vol);
  logInput("osc_2_vol", osc_2_vol);
  logInput("osc_3_vol", osc_3_vol);

  logInput("noise_color", noise_color);
  logInput("ext_vol", ext_vol);
  logInput("noise_vol", noise_vol);

  logInput("filter_mod", filter_mod);
  logInput("keyboard_c_1", keyboard_c_1);
  logInput("keyboard_c_2", keyboard_c_2);

  logInput("cutoff", cutoff);
  logInput("attack_time", attack_time);
  logInput("mod_attack_time", mod_attack_time);

  logInput("emphasis", emphasis); // BROKEN?
  logInput("decay_time", decay_time);
  logInput("mod_decay_time", mod_decay_time);

  logInput("amount_of_contour", amount_of_contour);
  logInput("sustain", sustain);
  logInput("mod_sustain", mod_sustain);

  logInput("lfo_rate", lfo_rate);
  logInput("decay", decay);
  logInput("glide_switch", glide_switch);

  logInput("main_vol", main_vol);
}

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

  updateMux1Values();
  updateMux2Values();
  updateMux3Values();

  Serial.println("---------");

  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
