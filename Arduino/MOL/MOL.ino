#include "MOL.h"
#include <Bounce2.h>

Bounce * joyButtDebouncer = new Bounce[NUM_JOY_BTNS]; // Create Bounce objects for each button.
Bounce * buttDebouncer = new Bounce[NUM_BTNS]; // Create Bounce objects for each button.

elapsedMillis msec = 0;

void setup() {

  for (int b = 0; b < NUM_POTS; b++) {
    potPrevs[0][b] = -1;
  } // set all previous pot values to -1 at startup

  for (int b = 0; b < NUM_JOYPOTS; b++) {
    joyPotPrevs[0][b] = -1;
  } // set all previous joystick potentiometer values to -1 at startup

  for (int b = 0; b < NUM_JOYPOTS; b++) {
    int read1 = analogRead(JOYPOTS[b]) / 8;
    delay(5);
    int read2 = analogRead(JOYPOTS[b]) / 8;
    delay(5);
    int read3 = analogRead(JOYPOTS[b]) / 8;
    delay(5);
    int read4 = analogRead(JOYPOTS[b]) / 8;
    delay(5);
    joyPotCenters[b] = (read1 + read2 + read3 + read4) / 4;
  } // read all current (center) values from the joy pots

  for (int b = 0; b < NUM_JOY_BTNS; b++) {
    pinMode(JBTNS[b], INPUT_PULLUP);
    joyButtDebouncer[b].attach(JBTNS[b]);
    joyButtDebouncer[b].interval(5);
  } //set up button pins and attach them to Bounce objects and set time interals


  for (int b = 0; b < NUM_BTNS; b++) {
    pinMode(BTNS[b], INPUT_PULLUP);
    buttDebouncer[b].attach(BTNS[b]);
    buttDebouncer[b].interval(5);
  } //set up button pins and attach them to Bounce objects and set time interals

  usbMIDI.setHandleNoteOff(OnNoteOff); //OnNoteOff function below
  usbMIDI.setHandleNoteOn(OnNoteOn);  //OnNoteOn function below

}

void buttonInput() {

  for (int b = 0; b < NUM_JOY_BTNS; b++) {
    joyButtDebouncer[b].update();
    if (joyButtDebouncer[b].fallingEdge()) {
      usbMIDI.sendNoteOn(JBTNCCs[b], 127, channel);
    }
    if (joyButtDebouncer[b].risingEdge()) {
      usbMIDI.sendNoteOff(JBTNCCs[b], 0, channel);
    }
  }


  for (int b = 0; b < NUM_BTNS; b++) {
    buttDebouncer[b].update();
    if (buttDebouncer[b].fallingEdge()) {
      usbMIDI.sendNoteOn(BTNCCs[b], 127, channel);
    }
    if (buttDebouncer[b].risingEdge()) {
      usbMIDI.sendNoteOff(BTNCCs[b], 0, channel);
    }
  }

}

void potInput() {

  if (msec >= 20) {
    msec = 0;


    for (int b = 0; b < NUM_POTS; b++) {
      int f = analogRead(POTS[b]) / 8;
      //      if ( (f != potPrevs[b]) ) {
      if (((f + potPrevs[0][b] + potPrevs[1][b] + potPrevs[2][b]) / 4) != potSends[b])  {
        usbMIDI.sendControlChange(POTCCs[b], 127 - ((f + potPrevs[0][b] + potPrevs[1][b] + potPrevs[2][b]) / 4), channel);
        potSends[b] = (f + potPrevs[0][b] + potPrevs[1][b] + potPrevs[2][b]) / 4;
        potPrevs[2][b] = potPrevs[1][b];
        potPrevs[1][b] = potPrevs[0][b];
        potPrevs[0][b] = f;
      }
    } // read the pots



    for (int b = 0; b < NUM_JOYPOTS; b++) {
      int f = analogRead(JOYPOTS[b]) / 8;

      if (((f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4) != joyPotSends[b]) {
        if (f <= joyPotCenters[b]) {

          f = map(f, 0, joyPotCenters[b], 0, 64);
          if ( (b % 2) == 1 ) {
            usbMIDI.sendControlChange(JOYCCs[b], (f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4, channel);
          }
          if ( (b % 2) == 0 ) {
            usbMIDI.sendControlChange(JOYCCs[b], 127 - ((f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4), channel);
          }
          joyPotSends[b] = ((f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4);
          joyPotPrevs[2][b] = joyPotPrevs[1][b];
          joyPotPrevs[1][b] = joyPotPrevs[0][b];
          joyPotPrevs[0][b] = f;
        }



        if (f > joyPotCenters[b]) {

          f = map(f, joyPotCenters[b], 127, 65, 127);
          if ( (b % 2) == 1 ) {
            usbMIDI.sendControlChange(JOYCCs[b], (f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4, channel);
          }
          if ( (b % 2) == 0 ) {
            usbMIDI.sendControlChange(JOYCCs[b], 127 - ((f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4), channel);
          }
          joyPotSends[b] = ((f + joyPotPrevs[0][b] + joyPotPrevs[1][b] + joyPotPrevs[2][b]) / 4);
          joyPotPrevs[2][b] = joyPotPrevs[1][b];
          joyPotPrevs[1][b] = joyPotPrevs[0][b];
          joyPotPrevs[0][b] = f;
        }
      }
    }
  }
}

void OnNoteOn(byte channel, byte note, byte velocity)
{

  for (int b = 0; b < NUM_LEDS; b++) {
    if (note == LEDCCs[b]) {
      analogWrite(LEDS[b], velocity * 2);
    }
  }

}

void OnNoteOff(byte channel, byte note, byte velocity)
{

  for (int b = 0; b < NUM_LEDS; b++) {
    if (note == LEDCCs[b]) {
      analogWrite(LEDS[b], 0);
    }
  }

}

void loop() {

  //---------for sending midi---------
  //process buttons
  buttonInput();

  //process pots
  potInput();

  //--------for receiving midi---------


  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  usbMIDI.read();
}
