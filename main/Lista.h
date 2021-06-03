#pragma once
#ifndef  LISTA_H
#define LISTA_H
#include "Nodo.h"
#include<time.h>
#include<stdlib.h>
class Lista
{
private:
	Nodo* primero;
	Nodo* actual;
public:
	Lista();
	void insertarInicio(Palabras*);
	string toString();
	int cuentaNodos();
	string retornaNodo();
	void eliminarNodo(string x);
	void Modificar(string x, string y);
	void Eliminar(ifstream&);
	void ModificarPalabra(ifstream&);
	void ModificarLista(Palabras* datos, string pal);
	~Lista();//FALTA
};

#endif // ! LISTA_H


