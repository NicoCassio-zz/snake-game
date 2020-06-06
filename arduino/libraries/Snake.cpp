#include "Snake.h"

//  Métodos públicos
void Snake::move() {
	if(!checkCollision()) {
		for(byte i=getSize(); i>0; i--) {
			setXPos(i, getXPos(i-1));
			setYPos(i, getYPos(i-1));
		}
		switch(getDirection()) {
			case 0:
				setYPos(0, getYPos(0)+1);
				break;
			case 1:
				setYPos(0, getYPos(0)-1);
				break;
			case 2:
				setXPos(0, getXPos(0)+1);
				break;
			case 3:
				setXPos(0, getXPos(0)-1);
				break;
		}
	}
}
void Snake::eat() {setSize(getSize()+1);}
bool Snake::checkCollision() {
	for(byte i=getSize(); i>0; i--) {
		if((i>=4) && (getXPos(0) == getXPos(i)) && (getYPos(0) == getYPos(i))) {
			setAlive(false);
			return true;
		}
	}
	return false;
}
//  Métodos especiais
Snake::Snake() {
	setSize(3);
	for(byte i=0; i<getSize(); i++) {
		setXPos(i, 2-i);
		setYPos(i, 2);
	}
	setDirection(2);
	setAlive(true);
}
byte Snake::getXPos(byte i) {return this->xPos[i];}
void Snake::setXPos(byte i, byte xPos) {
	if(xPos >= 0 && xPos < 8) {this->xPos[i] = xPos;}
	else {setAlive(false);}
}
byte Snake::getYPos(byte i) {return this->yPos[i];}
void Snake::setYPos(byte i, byte yPos) {
	if(yPos >= 0 && yPos < 8) {this->yPos[i] = yPos;}
	else {setAlive(false);}
}
byte Snake::getSize() {return this->size;}
void Snake::setSize(byte size) {this->size = size;}
byte Snake::getDirection() {return this->direction;}
void Snake::setDirection(byte direction) {
	if(
		(direction==0 && !(getDirection()==1)) ||
		(direction==1 && !(getDirection()==0)) ||
		(direction==2 && !(getDirection()==3)) ||
		(direction==3 && !(getDirection()==2))
	) {this->direction = direction;}
}
bool Snake::isAlive() {return this->alive;}
void Snake::setAlive(bool alive) {this->alive = alive;}
byte * Snake::toBinary() {
	for(byte i=0; i<8; i++) {m[i]=0;}
	for(byte i=0; i<8; i++) {
		for(byte j=0; j<getSize(); j++) {
			if(getYPos(j)==i) {bitSet(m[i], getXPos(j));}
		}
	}
	return m;
}
