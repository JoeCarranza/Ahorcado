#include "ListaJugador.h"

ListaJugador::ListaJugador() {
	actual = primero = NULL;
}


ListaJugador::~ListaJugador() {
	while (primero != NULL) { //eliminamos siempre el primero
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void ListaJugador::insertarOrdenado(Jugador* info) {
	// insertar ordenado, si no intentar ordenarlo con el metodo burbuja

	NodoJugador* Auxiliar = new NodoJugador(info);

	if ((primero == NULL) || (Auxiliar->getInfo()->getPuntos() > primero->getInfo()->getPuntos())) {
		Auxiliar->setSig(primero); // AUXILIAR APUNTA A CABEZA
		primero = Auxiliar; // CABEZA SE MUEVE A AUXILIAR
	}
	else {
		actual = primero;

		while ((actual->getSig() != NULL) && (actual->getSig()->getInfo()->getPuntos() > Auxiliar->getInfo()->getPuntos())) {
			actual = actual->getSig();
		}

		Auxiliar->setSig(actual->getSig());
		actual->setSig(Auxiliar);

	}
}

string ListaJugador::mostrar() {
	// hacer validacion para que muestre unicamente los primeros 6 jugadores y su puntaje
	int contador = 0;
	actual = primero;
	if (primero == NULL) {
		cout << "LISTA VACIA" << endl;
	}
	stringstream s;
	while ((actual != NULL) && (contador < 6))
	{
		s << actual->toStringNodo();
		actual = actual->getSig();
		contador++;
	}

	return s.str();
}

int ListaJugador::retornaMayor() {
	int valor = 0;
	actual = primero;
	while (actual != NULL) {
		if (valor < actual->getInfo()->getPuntos()) {
			valor = actual->getInfo()->getPuntos();
		}
		actual = actual->getSig();
	}
	return valor;
}