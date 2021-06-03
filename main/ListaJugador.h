#ifndef LISTAJUGADOR_H
#define LISTAJUGADOR_H
#include <iostream>
#include "NodoJugador.h"


using namespace std;


class ListaJugador {
public:
	ListaJugador();
	~ListaJugador();

	void insertarOrdenado(Jugador*);
	string mostrar();
	int retornaMayor();

private:

	NodoJugador* primero;
	NodoJugador* actual;

};

#endif
