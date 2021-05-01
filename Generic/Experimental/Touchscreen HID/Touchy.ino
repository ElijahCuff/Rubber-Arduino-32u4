#define BUTTON 2

#include "Touch.h"

void setup() {
  // initialize touch
  Touch.begin();

  // setup pins
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    int16_t x = 5000;
    int16_t y = 5000;

    for (; x <= 6000; x+=4) {
      for (int i = 0; i < 10; i++) {
        Touch.moveFingerTo(i, x + i * 100, y + i * 100);
      }
    }
    
    for (; y <= 6000; y+=4) {
      for (int i = 0; i < 10; i++) {
        Touch.moveFingerTo(i, x + i * 100, y + i * 100);
      }
    }
    
    for (; x >= 5000; x-=4) {
      for (int i = 0; i < 10; i++) {
        Touch.moveFingerTo(i, x + i * 100, y + i * 100);
      }
    }
    
    for (; y >= 5000; y-=4) {
      for (int i = 0; i < 10; i++) {
        Touch.moveFingerTo(i, x + i * 100, y + i * 100);
      }
    }

    for (int i = 0; i < 10; i++) {
      Touch.releaseFinger(i);
    }
  }
}
