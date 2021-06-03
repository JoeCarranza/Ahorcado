#ifndef NODOJUGADOR_H
#define NODOJUGADOR_H
#include <iostream>
#include "Jugador.h"

using namespace std;

class NodoJugador {
public:
	NodoJugador(Jugador*);
	NodoJugador(Jugador*, NodoJugador*);
	~NodoJugador();

	void setInfo(Jugador*);
	void setSig(NodoJugador*);

	Jugador* getInfo();
	NodoJugador* getSig();

	string toStringNodo();

private:

	Jugador* info;
	NodoJugador* sig;

};

#endif
