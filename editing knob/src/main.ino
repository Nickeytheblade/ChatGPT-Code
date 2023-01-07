#include <Arduino.h>
#include <Keyboard.h>

const int rotaryPinA = A2; // pin for rotary switch A
const int rotaryPinB = A1; // pin for rotary switch B

int lastPosition = 0; // last position of the rotary switch

void setup() {
  // initialize the keyboard
  Keyboard.begin();
  // set up the rotary switch pins as inputs
  pinMode(rotaryPinA, INPUT);
  pinMode(rotaryPinB, INPUT);
}

void loop() {
  // read the state of the rotary switch
  int position = digitalRead(rotaryPinA) | (digitalRead(rotaryPinB) << 1);

  // check if the rotary switch has moved
  if (position != lastPosition) {
    // debounce the switch by waiting a short time before checking again
    delay(10);
    position = digitalRead(rotaryPinA) | (digitalRead(rotaryPinB) << 1);

    // check if the rotary switch has moved in a clockwise or counterclockwise direction
    if (position > lastPosition) {
      // moved in a clockwise direction
      Keyboard.write(KEY_RIGHT_ARROW);
    } else if (position < lastPosition) {
      // moved in a counterclockwise direction
      Keyboard.write(KEY_LEFT_ARROW);
    }

    // update the last position
    lastPosition = position;
  }
}
