#include "ListaChar.h"

ListaChar::ListaChar() {
	actual = primero = NULL;
}

ListaChar::~ListaChar() {
	while (primero != NULL) { //eliminamos siempre el primero
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void ListaChar::eliminaContenido() {
	while (primero != NULL) { //eliminamos siempre el primero
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void ListaChar::jugar(string palabra, string aux, Jugador* p1, Jugador* p2) {
	char palabraAux;
	char letra;
	int contador1 = 0;
	int contador2 = 0;
	int turno = 2;
	bool bandera = false;
	bool ganador1 = false;
	bool ganador2 = false;
	int puntaje1 = 0;
	int puntaje2 = 0;
	for (unsigned i = 0; i < palabra.size(); i++) {
		palabraAux = palabra[i];

		Caracter* c = new Caracter(palabraAux);
		insertarChar(c);
	}

	for (unsigned i = 0; i < aux.length(); i++) {
		aux[i] = '_';
	}
	for (unsigned i = 0; i < aux.length(); i++) {

		cout << aux[i] << " ";

	}

	do {
		system("cls");

		cout << endl;
		for (unsigned i = 0; i < aux.length(); i++) {

			cout << aux[i] << " ";
		} cout << endl;


		if (turno % 2 == 0) {
			int opcP = 0;
			cout << "Jugador 1, desea adivinar toda la palabra?" << endl;
			cout << "1. SI " << endl;
			cout << "2. NO " << endl;
			cin >> opcP;
			cout << mostrar() << endl;
			if (opcP == 1) {
				string palabraAd = "";
				cout << "Digite la palabra" << endl;
				cin >> palabraAd;
				if (palabra == palabraAd) {
					int guiones = 0;
					ganador1 = true;
					for (unsigned i = 0; i < aux.length(); i++) {
						if (aux[i] == '_') {
							guiones++;
						}
					}
					puntaje1 += guiones * 2;
					cout << "Felicidades, ha ganado el juego!, PUNTAJE : " << puntaje1 << endl;
				}
			}if (opcP == 2) {
				cout << "\n\n	Ingrese una letra, jugador 1: " << p1->getIniciales() << endl;
				cin >> letra;
				cout << endl;

				for (unsigned i = 0; i < aux.length(); i++) {
					if (palabra[i] == letra) {
						aux[i] = palabra[i];
						cout << "Has acertado una letra, sigue asi :)" << endl;
						bandera = true;
						puntaje1 += 2;
						if ((puntaje1 == 30 || puntaje1 == 60 || puntaje1 == 90) && contador1 < 6) {
							contador1++;
						}

						system("pause");
					}
				}
				if (!bandera) {
					contador1++;
					cout << "Letra erronea." << endl;

					cout << "	Intentos restantes: " << 3 - contador1 << endl;
					puntaje2--;
				}
				if (palabra == aux) {
					ganador1 = true;
					cout << "Felicidades, ha ganado el juego!" << endl;
					system("pause");
				}
			}
		}

		//termina el jugador 1

		else if (turno % 2 != 0) {
			int opcP2 = 0;
			cout << "Jugador 2, desea adivinar toda la palabra?" << endl;
			cout << "1. SI " << endl;
			cout << "2. NO " << endl;
			cin >> opcP2;
			cout << mostrar() << endl;
			if (opcP2 == 1) {
				string palabraAd2 = "";
				cout << "Digite la palabra" << endl;
				cin >> palabraAd2;
				if (palabra == palabraAd2) {
					int guiones2 = 0;
					ganador2 = true;
					for (unsigned i = 0; i < aux.length(); i++) {
						if (aux[i] == '_') {
							guiones2++;
						}
					}
					puntaje2 += guiones2 * 2;
					cout << "Felicidades, ha ganado el juego!" << endl;
				}
			}if (opcP2 == 2) {

				cout << "\n\n	Ingrese una letra, jugador 2: " << p2->getIniciales() << endl;
				cin >> letra;
				cout << endl;

				for (unsigned i = 0; i < aux.length(); i++) {
					if (palabra[i] == letra) {
						aux[i] = palabra[i];
						cout << "Has acertado una letra, sigue asi :)" << endl;
						bandera = true;
						puntaje2 += 2;
						if ((puntaje2 == 30 || puntaje2 == 60 || puntaje2 == 90) && contador2 < 6) {
							contador2++;
						}
						system("pause");
					}
				}
				if (!bandera) {
					contador2++;
					cout << "Letra erronea." << endl;

					cout << "	Intentos restantes: " << 3 - contador2 << endl;
					puntaje2--;
				}
				if (palabra == aux) {
					ganador2 = true;

					cout << "Felicidades, ha ganado el juego!" << endl;
					system("pause");
				}
			}
		}
		//termina jugador 2

		if (!bandera) {
			turno++;
			system("pause");

		}

		bandera = false;

	} while ((ganador1 == false && ganador2 == false) && ((contador1 < 3) || (contador2 < 3)));
	p1->setPuntos(puntaje1);
	p2->setPuntos(puntaje2);
	if (ganador1 == false && ganador2 == false) {
		cout << "Limite de intentos alcanzados, mas suerte para la proxima" << endl;
	}
}

void ListaChar::insertarChar(Caracter* info) {

	actual = primero;
	if (actual == NULL) {
		primero = new NodoChar(info, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new NodoChar(info, NULL));
	}
}

string ListaChar::mostrar() {

	actual = primero;
	if (primero == NULL) {
		cout << "LISTA VACIA" << endl;
	}
	stringstream s;
	while (actual != NULL)
	{
		s << actual->toStringNodo();
		actual = actual->getSig();
	}

	return s.str();
}
