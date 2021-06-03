#include "Caracter.h"

Caracter::Caracter(char caracter) {
	this->caracter = caracter;
}

Caracter::~Caracter() {

}

void Caracter::setCaracter(char caracter) {
	this->caracter = caracter;
}

char Caracter::getCaracter() {
	return caracter;
}

string Caracter::toString() {
	stringstream s;

	s << caracter << " ";

	return s.str();
}

