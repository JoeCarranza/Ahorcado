#include "Jugador.h"
#define DELIMITA_CAMPO "\n"

Jugador::Jugador(string iniciales) {
	this->iniciales = iniciales;
	puntos = 0;
}

Jugador::Jugador(string iniciales, int puntos) {
	this->iniciales = iniciales;
	this->puntos = puntos;
}

Jugador::~Jugador() {

}

void Jugador::setIniciales(string iniciales) {
	this->iniciales = iniciales;
}

string Jugador::getIniciales() {
	return iniciales;
}

string Jugador::toString() {

	stringstream s;

	s << "Datos del Jugador: " << endl;
	s << "Iniciales: " << getIniciales() << endl;
	s << "Puntaje: " << getPuntos() << endl;

	return s.str();

}

void Jugador::setPuntos(int puntos) {
	this->puntos = puntos;
}

int Jugador::getPuntos() {
	return puntos;
}

void Jugador::autoGuardar(ofstream& salidaJ)
{
	salidaJ << iniciales << DELIMITA_CAMPO;
	salidaJ << puntos << DELIMITA_CAMPO;
}

Jugador* Jugador::autoLeer(ifstream& entradaJ)
{
	string inici, pts;
	if (!(entradaJ >> inici)) { return NULL; }
	if (!(entradaJ >> pts)) { return NULL; }

	int ptos = convertirInt(pts);

	return new Jugador(inici, ptos);
}

