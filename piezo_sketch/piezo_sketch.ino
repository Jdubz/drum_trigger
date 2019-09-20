#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

const int LEDPIN = 2;
const int MIDI_CHANNEL = 10;
const int NUMSENSORS = 20;
// const int NUMSENSORS = 1;
const float upthreshold = 30.0;
const int debounce = 30;

int sensors[NUMSENSORS] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A15,A16,A17,A18,A19,A20};
// int sensors[NUMSENSORS] = {A8};
bool isUp[NUMSENSORS];
float thresholds[NUMSENSORS];

float floors[NUMSENSORS];
void findFloor(int sensor, float amp) {
  if (amp > floors[sensor]) {
    Serial.println(String(sensor) + " : " + String(amp));
    floors[sensor] = amp;
  }
}

void setup()
{
  for (int sensor = 0; sensor < NUMSENSORS; sensor++) {
    isUp[sensor] = false;
    floors[sensor] = 0.0;
    thresholds[sensor] = 30.0;
  }

  thresholds[12] = 10.0;
  thresholds[19] = 35.0;
  
   Serial.begin(9600); 
//   MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
  for (int sensor = 0; sensor < NUMSENSORS; sensor++) {
    float amp = analogRead(sensors[sensor]);
    findFloor(sensor, amp);
//    int noteNumber = 60 + sensor;
    if (amp > upthreshold) {
      Serial.println(String(sensor) + " ---- " + String(amp));
    }
//    if (amp > upthreshold && !isUp[sensor]) {
//      float velocity = (amp / 1024.0) * 127.0;
//      // Serial.println(amp);
////      MIDI.sendNoteOn(noteNumber, velocity, MIDI_CHANNEL);
//      sensors[sensor] = true;
//      Serial.println(String(noteNumber) + " : " + String(amp) + " on");
//    } else if (amp < downthreshold && isUp[sensor]) {
////      MIDI.sendNoteOff(noteNumber, 127, MIDI_CHANNEL);
//      Serial.println(String(noteNumber) + " : " + String(amp) + " off");
//      sensors[sensor] = false;
//    }
  }
}
