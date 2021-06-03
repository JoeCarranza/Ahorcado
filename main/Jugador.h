#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "Utiles.h"

using namespace std;

class Jugador { //metodo burbuja para insertar puntajes o jugares ordenado , y si no un insertar ordenado
public:

	Jugador(string); // constructor de jugador
	Jugador(string, int);
	~Jugador(); // destructor

	void setIniciales(string);
	void setPuntos(int);

	string getIniciales();
	int getPuntos();

	void autoGuardar(ofstream&);
	static Jugador* autoLeer(ifstream&);

	string toString();

private:

	string iniciales; // variable para guardar las Iniciales de cada jugador
	// int intentos; //declarar alguna variable local en el metodo 
	int puntos;
};

#endif
