#include "Nodo.h"
Nodo::Nodo(Palabras* e, Nodo* s) {
	info = e;
	sig = s;
}
Nodo:: ~Nodo() {
	delete info;
}
void Nodo::setInfo(Palabras* e) { info = e; }
Palabras* Nodo::getInfo() { return info; }
void Nodo::setSig(Nodo* s) { sig = s; }
Nodo* Nodo::getSig() { return sig; }

string Nodo::toStringNodo() {
	return  info->toString();
}

