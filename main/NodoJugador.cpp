#include "NodoJugador.h"
NodoJugador::NodoJugador(Jugador* j) {
	this->setInfo(j);
	this->sig = NULL;
}
NodoJugador::NodoJugador(Jugador* info, NodoJugador* sig) {
	this->info = info;
	this->sig = sig;
}

NodoJugador::~NodoJugador() {
	//delete info;
}

void NodoJugador::setInfo(Jugador* info) {
	this->info = info;
}

void NodoJugador::setSig(NodoJugador* sig) {
	this->sig = sig;
}

Jugador* NodoJugador::getInfo() {
	return info;
}

NodoJugador* NodoJugador::getSig() {
	return sig;
}

string NodoJugador::toStringNodo() {
	return info->toString();
}
