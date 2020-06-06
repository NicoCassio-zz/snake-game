#include "Button.h"

//  Métodos públicos
void Button::begin() {pinMode(getPin(), INPUT);}
byte Button::update() {
	byte newState = digitalRead(getPin());
	if(newState!=getAuxLastState()) {
		if((millis()-lastDebouncingTime)>debouncingTime) {setState(newState);}
		lastDebouncingTime = millis();
	}
	setAuxLastState(newState);
	return getState();
}
byte Button::pressed() {
	update();	
	if(getState()!=getLastState()) {
		setLastState(getState());	
		if(getState()) {return HIGH;}
	}
	return LOW;
}
byte Button::isPressed() {
	update();
	return getState();
}
//  Métodos especiais
Button::Button(byte pin) {
	setPin(pin);
	setState(LOW);
	setLastState(LOW);
	setAuxLastState(LOW);
	lastDebouncingTime = 0;
}
byte Button::getPin() {return this->pin;}
void Button::setPin(byte pin) {this->pin = pin;}
byte Button::getState() {
	return this->state;
}
void Button::setState(byte state) {
	setLastState(getState());	
	this->state = state;
}
byte Button::getLastState() {return this->lastState;}
void Button::setLastState(byte lastState) {this->lastState = lastState;}
void Button::setAuxLastState(byte auxLastState) {this->auxLastState = auxLastState;}
byte Button::getAuxLastState() {return this->auxLastState;}
