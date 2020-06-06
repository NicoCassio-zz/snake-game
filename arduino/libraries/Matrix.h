#ifndef MATRIX_H
#define MATRIX_H

#include <Arduino.h>

class Matrix {
	private:
		//  Variáveis
		byte m[8];
	public:
		//  Métodos públicos
		void clear();
		//  Métodos especiais
		byte getLine(byte i);
		void setLine(byte i, byte line);
		byte* getAllLines();
		void setAllLines(byte m[]);
};

#endif
