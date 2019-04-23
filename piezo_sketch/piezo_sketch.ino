#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

const int MIDI_CHANNEL = 10;
const int TRIGGERS[7] = {A1,A2,A3,A4,A5,A6,A7};
const int NUMSENSORS = 7;

const int threshold = 100;
int sensors[7] = {0,0,0,0,0,0,0};

void setup()
{
   Serial.begin(9600); 
   MIDI.begin(1);
}

void loop()
{
    for (int sensor = 0; sensor < NUMSENSORS; sensor++) {
        sensors[sensor] = analogRead(TRIGGERS[sensor]);
        Serial.println(sensors[sensor] + ' ' + sensor);
    }
    delay(100);

    // MIDI.sendNoteOn(52,127,1);  // Send a Note (pitch 52, velo 127 on channel 1)
    // MIDI.sendNoteOff(40,127,1); // Stop the note
}
