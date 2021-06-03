#include "Lista.h"
Lista::Lista() {
	primero = NULL;
	actual = NULL;
}

void Lista::insertarInicio(Palabras* e)
{
	primero = new Nodo(e, primero);
}
string Lista::toString() {
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

int Lista::cuentaNodos()
{
	actual = primero;
	
	int contador = 0;
	while (actual != NULL) {
		contador++;
		actual = actual->getSig();
	}
	return contador;
}

string Lista::retornaNodo()
{
	int can = cuentaNodos();
	int num = 0;
	int cont = 0;

	srand(time(NULL));
	num = rand() % can;

	if (primero == NULL) {
		cout << "LISTA VACIA" << endl;
	}
	actual = primero;
	while (actual != NULL) {
		if (cont == num) {
			string palabra = "";
			palabra = actual->getInfo()->getPalabra();
			return palabra;
	   }
		cont++;
		actual = actual->getSig();
	}
	return "ERROR";
}

void Lista::eliminarNodo(string x)
{
	Nodo* panterior = NULL;
	actual = primero;
	if (primero==NULL) {
		cout << "LISTA VACIA" << endl;
	}
	if (primero->getInfo()->getPalabra() == x) // si es el primero
	{
		actual = actual->getSig();
		delete primero;
		primero = actual;
		cout << "SE ELIMINO CORRECTAMENTE AL INICIO" << endl;
	}

	//Si no es el primero, hay que avanzar para buscarlo
	while (actual != NULL && actual->getInfo()->getPalabra() != x) {
		panterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) { cout << "Palabra no encontrada" << endl; }//Si no lo encontro	
	else {// el nodo fue encontrado
		panterior->setSig(actual->getSig());
		delete actual;
		cout << "Palabra encontrada, eliminando... " << endl;
	}
	cout << "No cumple con ninguna condicion, palabra no encontrada" << endl; // si no cumple con ninguno de los IF, entonces no se encontro
	
}

void Lista::Modificar(string x, string y)
{
	actual = primero;
	if (primero == NULL) {
		cout << "LISTA VACIA" << endl;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getPalabra() == x);
			actual->getInfo()->setPalabra(y);
		}
		actual = actual->getSig();
	}
	
}

Lista::~Lista() {
	while (primero != NULL) { //eliminamos siempre el primero
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}

}
void Lista::Eliminar(ifstream& entrada) {
	string palabra;
	string palabraaux;
	entrada.open("Palabras.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (entrada.is_open()) {
		cout << "Palabra a eliminar" << endl;
		cin >> palabraaux;
		entrada >> palabra;
		while (!entrada.eof()) {

			if (palabra.compare(palabraaux) == 0) {
				cout << "Palabra eliminada" << endl;
				eliminarNodo(palabraaux);
			}
			else {
				aux << palabra << "\n";
			}
			entrada >> palabra;
		}
		entrada.close();
		aux.close();
		remove("Palabras.txt");
		rename("auxiliar.txt", "Palabras.txt");
	}
}
void Lista::ModificarLista(Palabras* datos, string pal) {

	if (primero == NULL) {
		cout << "Lista vacia" << endl;
	}
	else {
		actual = primero;
		bool n = true;
		while ((actual != NULL) && (n == true)) {
			if (actual->getInfo()->getPalabra() == pal) {
				actual->setInfo(datos);
				n = false;
				cout << "Se ha modificado la palabra" << endl;
			}
			actual = actual->getSig();
		}

		if (n == true) {
			cout << "Palabra no encontrada" << endl;
		}
	}

}
void Lista::ModificarPalabra(ifstream& entrada) {
	string palabra;
	string palabraaux;
	string nuevapalabra;
	entrada.open("Palabras.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (entrada.is_open()) {
		cout << "Palabra a modificar" << endl;
		cin >> palabraaux;
		entrada >> palabra;
		while (!entrada.eof()) {

			if (palabra.compare(palabraaux) == 0) {
				cout << "Nueva palabra: " << endl;
				cin >> nuevapalabra;
				aux << nuevapalabra << "\n";
				Palabras* paux = new Palabras(nuevapalabra);
				ModificarLista(paux, palabraaux);
			}
			else {
				aux << palabra << "\n";
			}
			entrada >> palabra;
		}
		entrada.close();
		aux.close();
		remove("Palabras.txt");
		rename("auxiliar.txt", "Palabras.txt");
	}
}

