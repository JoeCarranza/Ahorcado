#include "NodoChar.h"
NodoChar::NodoChar(Caracter* info, NodoChar* sig) {
	this->info = info;
	this->sig = sig;
}

NodoChar::~NodoChar() {
	// revisar, depende de la relacion
}

void NodoChar::setInfo(Caracter* info) {
	this->info = info;
}

void NodoChar::setSig(NodoChar* sig) {
	this->sig = sig;
}

Caracter* NodoChar::getInfo() {
	return info;
}

NodoChar* NodoChar::getSig() {
	return sig;
}

string NodoChar::toStringNodo() {
	return info->toString();
}
