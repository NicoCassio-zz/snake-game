#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

#include "Snake.h"
#include "Food.h"
#include "Matrix.h"

class Game {
	private:
		//  Variáveis
		Snake s;
		Food f;
		Matrix m;
	public:
		//  Metódos públicos
		void begin();
		void play();
		void generate();
		void plotMatrix();
		void handleDirection(byte direction);
		//  Métodos especiais
		Snake* getSnake();
		void setSnake(Snake s);
		Food getFood();
		void setFood(Food f);
		Matrix getMatrix();
		void setMatrix(Matrix m);
};

#endif
