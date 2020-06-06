#ifndef FOOD_H
#define FOOD_H

#include <Arduino.h>

class Food {
	private:
		//  Variáveis
		byte xPos;
		byte yPos;
	public:
		//  Métodos espeicias
		byte getXPos();
		void setXPos(byte xPos);
		byte getYPos();
		void setYPos(byte yPos);
};

#endif
