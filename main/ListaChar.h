#ifndef LISTACHAR_H
#define LISTACHAR_H
#include "NodoChar.h"
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Jugador.h"

using namespace std;

class ListaChar {
public:

	ListaChar();
	~ListaChar();

	void insertarChar(Caracter*);  // inserta cada caracter de la palabra random escogida para el juego.
	string mostrar();
	void eliminaContenido();
	void jugar(string, string, Jugador*, Jugador*);
	//sin metodos por ahora

private:

	NodoChar* primero;
	NodoChar* actual;
	Lista* l;

};

#endif

