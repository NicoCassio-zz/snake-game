#include "LedControl.h"
#include "Game.h"
#include "Button.h"

#define DIN 12
#define CLK 11
#define CS 10
#define BUTTON 9

const unsigned long playTime = 300;
const unsigned long debounceTime = 50;
unsigned long lastPlayTime = 0;
unsigned long lastDebounceTime = 0;
byte state = LOW;
byte d = 2; // direction

void plotLedMatrix();

LedControl ledMatrix = LedControl(DIN, CLK, CS, 1);
Game g = Game();
Button button = Button(BUTTON);

void setup() {

  ledMatrix.shutdown(0, false);
  ledMatrix.setIntensity(0, 8);
  ledMatrix.clearDisplay(0);

  g.begin();
  button.begin();

  plotLedMatrix();

}

void loop() {

  unsigned long currentTime = millis();
  byte newState = digitalRead(BUTTON);

  if (button.pressed()) {
    lastPlayTime = currentTime;
    switch (d) {
      case 0:
        d = 2;
        break;
      case 1:
        d = 3;
        break;
      case 2:
        d = 1;
        break;
      case 3:
        d  = 0;
        break;
    }
    g.handleDirection(d);
    plotLedMatrix();
  }

  if (currentTime - lastPlayTime >= playTime) {
    g.play();
    plotLedMatrix();
    lastPlayTime = currentTime;
  }

}

void plotLedMatrix() {
  for (byte i = 0; i < 8; i++) {
    ledMatrix.setColumn(0, (7 - i), g.getMatrix().getLine(i));
  }
}
