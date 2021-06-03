#include <iostream>
#include <Windows.h>
#include "Lista.h"
#include "Jugador.h"
#include "ListaChar.h"
#include "Palabras.h"
#include "Administrador.h"
#include "ListaJugador.h"
#define DELIMITA_CAMPO "\n"

int main() {
	string palabra;
	int opc = 0;
	string password;
	Administrador ad;
	Lista* l = new Lista();
	ListaJugador* lj = new ListaJugador();
	ifstream entrada;//ARCHIVO DE ENTRADA (LEER) DE TEXTO PARA LAS PALABRAS
	ofstream salida;//ARCHIVO DE SALIDA (ESCRIBIR) DE TEXTO PARA LAS PALABRAS

	ifstream entradaJ;//ARCHIVO DE ENTRADA (LEER) DE TEXTO PARA LOS JUGADORES
	ofstream salidaJ;//ARCHIVO DE SALIDA (ESCRIBIR) DE TEXTO PARA LOS JUGADORES
	//-------------------------------------------------------------------
	ListaChar* lChar = new ListaChar();
	//-------------------------------------------------------------------
	Palabras* a = new Palabras();
	//aqui cargar todas las palabras que hay en el archivo y los mete a la lista al inicio del programa
	entrada.open("Palabras.txt", ios::in);
	Palabras* b = NULL;
	while (entrada.good())
	{
		b = Palabras::autoLeer(entrada);
		if (b != NULL) { l->insertarInicio(b); }
	}
	entrada.close();

	//aqui cargar todas las palabras que hay en el archivo y los mete a la lista al inicio del programa
	entrada.open("Jugadores.txt", ios::in);
	Jugador* c = NULL;
	while (entrada.good())
	{
		c = Jugador::autoLeer(entrada);
		if (c != NULL) { lj->insertarOrdenado(c); }
	}
	entrada.close();



	do {
		system("cls");
		cout << "------------------Bienvenido------------------- \n"
			<< "-------------------AhorcadoGame-----------------\n"
			<< "Digite una de las siguiente opciones: \n"
			<< "1-Ingresar como Administrador. \n"
			<< "2-Jugar una partida. \n"
			<< "3-Cerrar juego. \n";
		cin >> opc;

		switch (opc) {
		case 1:
			system("cls");
			cout << "Bienvenido administrador, por favor digite su contraseña:" << endl;
			cout << "Password" << endl;
			cin >> password;
			if (ad.Ingresar(password) == 0) {
				cout << "ContraseÃ±a incorrecta, por favor intentelo de nuevo" << endl;
			}
			else if (ad.Ingresar(password) == 1) {
				int opc2;
				system("cls"); //LIMPIA LA PANTALLA
				cout << "Bienvenido/a, digite la opcion que desea realizar" << endl;
				cout << "[1]. Ingresar palabras. \n"
					<< "[2]. Visualizar las palabras. \n"
					<< "[3]. Modificar alguna palabra. \n"
					<< "[4]. Eliminar alguna palabra. \n"
					<< "[5]. Salir." << endl;
				cin >> opc2;
				switch (opc2) {
				case 1: {
					system("cls");
					//INTRODUCE PALABRA
					cout << endl << "Ingrese los datos:" << endl;
					salida.open("Palabras.txt", ios::out | ios::app);
					cout << "Palabra: ";
					cin >> palabra;
					cout << endl;
					Palabras* pala = new Palabras(palabra);
					pala->autoGuardar(salida);
					l->insertarInicio(pala);
					salida.close();
					cout << " ---->Listo...." << endl;
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					//METODO PARA MOSTRAR LAS PALABRAS DE LA LISTA
					cout << l->toString();
					system("pause");
					break;
				}
				case 3: {
					system("cls");
					//METODO PARA MODIFICAR LAS PALABRAS DE LA LISTA Y DEL ARCHIVO
					l->ModificarPalabra(entrada);
					system("pause");
					break;
				}
				case 4: {
					system("cls");
					//METODO PARA ELIMINAR LAS PALABRAS DE LA LISTA Y DEL ARCHIVO
					l->Eliminar(entrada);
					system("pause");
					break;
				}
				case 5: {
					system("cls");
					//METODO PARA SALIR
					cout << "Saliendo..." << endl;
					system("pause");
					break;
				}
				default:
					break;
				}
				break;
			}
			//FIN DEL PRIMER CASE DEL PRIMER STWICH
			system("pause");
			break;
		case 2: {// JUGADOR
			// CASE 2 DONDE COMIENZA LA PARTIDA DE AHORCADO
			system("cls");
			//MUESTRA A LOS 6 JUGADORES QUE TIENEN MAYOR PUNTAJE EN EL JUEGO
			cout << "CON USTEDES LOS MEJORES 6 JUGADORES" << endl;
			cout << lj->mostrar();
			system("pause");
			system("cls");

			int opc = 0;
			string iniciales1 = "";
			string iniciales2 = "";
			int puntaje1 = 0;
			int puntaje2 = 0;
			//ingresar dos jugadores primero 

			do {
				cout << "Desea iniciar un nuevo juego? " << endl;
				cout << "1- Si" << endl;
				cout << "2- No" << endl;
				cin >> opc;
				system("cls");
				if (opc == 2) {
					break;
					system("pause");
				}
				cout << "Bienvenido jugador 1, por favor digite los siguientes datos: " << endl;
				cout << "Iniciales: " << endl;
				cin >> iniciales1;

				system("cls");

				cout << "Bienvenido jugador 2, por favor digite los siguientes datos: " << endl;
				cout << "Iniciales: " << endl;
				cin >> iniciales2;
				// SE CREAN LOS DOS JUGADORES CON SUS RESPECTIVOS ATRIBUTOS
				Jugador* player1 = new Jugador(iniciales1);
				player1->toString();

				Jugador* player2 = new Jugador(iniciales2);
				player1->toString();

				system("pause");
				system("cls");

				string palabra = "";
				string aux = "";
				palabra = l->retornaNodo();// ESTE METODO RETORNA UNA PALANA RANDOM
				aux = palabra;

				lChar->jugar(palabra, aux, player1, player2);// ESTE METODO LE MANDA LOS DOS JUGADORES Y LOS PONE A JUGAR

				salidaJ.open("Jugadores.txt", ios::out | ios::app); // SE CREA EL ARCHIVO DE TXT DE JUGADORES
				player1->autoGuardar(salidaJ);
				player2->autoGuardar(salidaJ);
				//LOS GUARDA A LOS DOS EN EL ARCHIVO
				int valor = 0;
				valor = lj->retornaMayor();//ESTE METODO TIENE EL MAYOR PUNTAJE PARA SABER SI SUPERO EL RECORD
				lj->insertarOrdenado(player1);
				lj->insertarOrdenado(player2);
				//INGRESA A LOS DOS JUGADORES EN LA LISTA ORDENADOS POR MAYOR PUNTAJE
				//Y LOS IFS QUE SIGUEN COMPRUEBAN SI ALGUNO DE LOS DOS SUPERO EL RECORD
				if (valor > player1->getPuntos()) {
					cout << "Felicidades, tienes el record de puntaje" << endl;
					system("pause");
					system("cls");
				}
				else if (valor > player2->getPuntos()) {
					cout << "Felicidades, tienes el record de puntaje" << endl;
					system("pause");
					system("cls");
				}
				salidaJ.close();
				system("cls");
				//AL FINAL DEL PROGRAMA SE MUESTRA LOS 6 JUGADORES CON MAYOR PUNTAJE DEL JUEGO
				cout << "CON USTEDES LOS MEJORES 6 JUGADORES" << endl;
				cout << lj->mostrar();//METODO PARA MOSTRAR LOS JUGADORES
				cout << endl;

				lChar->eliminaContenido();//ELIMINA LA PALABRA RANDOM PARA LIBERAR MEMORIA EN LA PARTIDA
				cout << endl;
				cout << endl;
			} while (opc != 2);
			break;

		}
		case 3:
			//CASE PARA SALIR DEL PROGRAMA
			exit(0);
			//LLAMA A LOS DESTRUCTORES DE LA MEMORIA QUE SE HA CREADO PARA LIBERAR MEMORIA
			delete l;
			delete a;

			l->~Lista();
			lChar->~ListaChar();
			break;

		default:
			break;
		}
	} while (opc != 3);// INDICA QUE SI NO ES UNA OPCION DENTRO DEL WHILE ES UNA OPCION INVALIDA

	//LLAMA A LOS DESTRUCTORES DE LA MEMORIA QUE SE HA CREADO PARA LIBERAR MEMORIA
	delete l;
	delete a;

	l->~Lista();
	lChar->~ListaChar();

	return 0;
}