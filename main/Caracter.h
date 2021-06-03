#pragma once
#ifndef CARACTER_H
#define CARACTER_H
#include <iostream>
#include <sstream>
#include "Lista.h"

using namespace std;

class Caracter {
public:
	Caracter(char);
	~Caracter();
	void setCaracter(char);
	char getCaracter();
	string toString();
private:
	char caracter;
};

#endif