#include "Administrador.h"
Administrador::Administrador() {
	nombre = "";
	password = "";
}
Administrador::Administrador(string nombre, string password) {
	this->nombre = nombre;
	this->password = password;
}

Administrador::~Administrador() {
	//DESTRUCTOR
}

void Administrador::setPassword(string password) {
	this->nombre = nombre;
}

string Administrador::getPassword()
{
	return password;
}
//METODOS
int Administrador::Ingresar(string password) {
	if (password != "admin") {
		return 0;
	}
	else {
		return 1;
	}
}
void Administrador::setNombre(string nombre) {
	this->nombre = nombre;
}

string Administrador::getNombre() {
	return nombre;
}