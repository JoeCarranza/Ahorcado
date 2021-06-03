#pragma once
#ifndef  PALABRAS_H
#define PALABRAS_H
#include<fstream>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;
class Palabras{
private:
	string palabra;

public:
	Palabras();
	Palabras(string palabra);
	~Palabras();
	
	void setPalabra(string palabra);
	string getPalabra();
	string toString();
	void autoGuardar(ofstream&);
	static Palabras* autoLeer(ifstream&);
	void Eliminar(ifstream&);
	void ModificarPalabra(ifstream&);

};

#endif // ! PALABRAS_H



