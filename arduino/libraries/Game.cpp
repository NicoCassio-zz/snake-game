#include "Game.h"

//  Métodos públicos
void Game::begin() {
	generate();
	plotMatrix();
}
void Game::play() {
	if(s.isAlive()) {
		s.move();
		if(s.getXPos(0)==f.getXPos() & s.getYPos(0)==f.getYPos()) {
			s.eat();
			generate();
		}
		plotMatrix();
	}
}
void Game::generate() {
	byte xPos;
	byte yPos;
	bool p;
	do {
		p = false;
		randomSeed(analogRead(A0));
		xPos = byte(random(8));
		yPos = byte(random(8));
		for(byte i=0; i<s.getSize(); i++) {
			if(xPos==s.getXPos(i) && yPos==s.getYPos(i)) {
				p = true;
				break;
			}
		}
	} while(p);
	f.setXPos(xPos);
	f.setYPos(yPos);
}
void Game::plotMatrix() {
	m.clear();
	m.setAllLines(s.toBinary());
	byte bit = m.getLine(f.getYPos());
	bitSet(bit, f.getXPos());
	m.setLine(f.getYPos(), bit); 
}
void Game::handleDirection(byte direction) {
	getSnake()->setDirection(direction);
	play();
}
//  Métodos especiais
Snake* Game::getSnake() {return &(this->s);}
void Game::setSnake(Snake s) {this->s = s;}
Food Game::getFood() {return this->f;}
void Game::setFood(Food f) {this->f = f;}
Matrix Game::getMatrix() {return this->m;}
void Game::setMatrix(Matrix m) {this->m = m;}
