#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>


using namespace std;

class Administrador {
private:
	string nombre;
	string password;
public:
	Administrador();
	Administrador(string nombre, string password);
	~Administrador();
	void setNombre(string);
	string getNombre();
	void setPassword(string password);
	string getPassword();
	int Ingresar(string password);
};

#endif