#include "Matrix.h"

//  Metodos públicos
void Matrix::clear() {
	byte m[8] = {0,0,0,0,0,0,0,0};
	setAllLines(m);
}
//  Métodos especiais
byte Matrix::getLine(byte i) {return this->m[i];}
void Matrix::setLine(byte i, byte line) {this->m[i] = line;}
byte* Matrix::getAllLines() {return this->m;}
void Matrix::setAllLines(byte m[]) {for(byte i=0; i<8; i++) {setLine(i, m[i]);}}
