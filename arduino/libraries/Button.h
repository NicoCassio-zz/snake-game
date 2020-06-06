#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
	private:
		byte pin;
		byte state;
		byte lastState;
		byte auxLastState;
		unsigned long lastDebouncingTime;
		const unsigned long debouncingTime = 50;
	public:
		//  Métodos públicos
		void begin();
		byte update();
		byte pressed();
		byte isPressed();
		//  Métodos especiais
		Button(byte pin);
		byte getPin();
		void setPin(byte pin);
		byte getState();
		void setState(byte state);
		byte getLastState();
		void setLastState(byte lastState);
		byte getAuxLastState();
		void setAuxLastState(byte auxLastState);
};

#endif
