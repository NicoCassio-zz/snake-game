#ifndef SNAKE_H
#define SNAKE_H

#include <Arduino.h>

class Snake {
	private:
		//  Variáveis
		byte xPos[64];
		byte yPos[64];
		byte size;
		byte direction;
		bool alive;
		byte m[8];
	public:
		//  Métodos públicos
		void move();
		void eat();
		bool checkCollision();
		//  Métodos especiais
		Snake();
		byte getXPos(byte i);
		void setXPos(byte i, byte xPos);
		byte getYPos(byte i);
		void setYPos(byte i, byte yPos);
		byte getSize();
		void setSize(byte size);
		byte getDirection();
		void setDirection(byte direction);
		bool isAlive();
		void setAlive(bool alive);
		byte* toBinary();
};

#endif
