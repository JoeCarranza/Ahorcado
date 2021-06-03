#pragma once
#ifndef NODO_H
#define NODOH
#include "Palabras.h"
class Nodo
{
private:
	Palabras* info;
	Nodo* sig;
public:
	Nodo(Palabras*, Nodo*);
	~Nodo();
	void setInfo(Palabras*);
	Palabras* getInfo();
	void setSig(Nodo*);
	Nodo* getSig();
	string toStringNodo();
};



#endif // !NODO_H