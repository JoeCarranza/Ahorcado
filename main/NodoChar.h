#pragma once
#ifndef NODOCHAR_H
#define NODOCHAR_H
#include "Caracter.h"
#include <iostream>
#include <sstream>

using namespace std;

class NodoChar {
public:

	NodoChar(Caracter*, NodoChar*); //constructor
	~NodoChar(); // destructor

	void setInfo(Caracter*);
	void setSig(NodoChar*);

	Caracter* getInfo();
	NodoChar* getSig();

	string toStringNodo(); //  depende del toString de la clase caracter

private:

	Caracter* info; // esta parte del Nodo va a contener la info de un Caracter
	NodoChar* sig; // Nodo siguiente con defecto

};

#endif

