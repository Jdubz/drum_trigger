#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();


const int MIDI_CHANNEL = 10;
const int TRIGGERS[8] = {A0,A1,A2,A3,A4,A5,A6,A7};
const int trigger = 1;
const int NUMSENSORS = 8;

const int threshold = 100;
int sensors[8] = {0,0,0,0,0,0,0,0};

void setup()
{
//   Serial.begin(9600); 
   MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
  for (int sensor = 0; sensor < NUMSENSORS; sensor++) {
    float amp = analogRead(TRIGGERS[sensor]);
    int noteNumber = 60 + sensor;
    if (amp > threshold && sensors[sensor] == 0) {
      int velocity = (amp / 1024.0) * 127.0;
      MIDI.sendNoteOn(noteNumber, velocity, MIDI_CHANNEL);
      sensors[sensor] = 1;
      // Serial.println(String(noteNumber) + " : " + String(velocity));
    } else if (amp < threshold && sensors[sensor] == 1) {
      MIDI.sendNoteOff(noteNumber, 127, MIDI_CHANNEL);
      sensors[sensor] = 0;
    }
  }
}
