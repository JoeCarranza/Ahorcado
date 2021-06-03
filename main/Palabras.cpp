#include "Palabras.h"
# define DELIMITA_CAMPO "\n"
Palabras::Palabras()
{
	palabra = "";
}

Palabras::Palabras(string palabra)
{
	this->palabra = palabra;
}

Palabras::~Palabras()
{
//DESTRUCTOR
}

void Palabras::setPalabra(string palabra)
{
	this->palabra = palabra;
}

string Palabras::getPalabra()
{
	return palabra;
}

string Palabras::toString()
{
	stringstream s;

	s << palabra<<endl;
	return s.str();
}

void Palabras::autoGuardar(ofstream& salida)
{
	salida << palabra <<DELIMITA_CAMPO;		
}

Palabras* Palabras::autoLeer(ifstream& entrada)
{
	string pal;
	if (!(entrada >> pal)) { return NULL; }
	return new Palabras(pal);
}

void Palabras::Eliminar(ifstream& entrada)
{
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
			}
			else {
				aux << palabra << DELIMITA_CAMPO;
			}
			entrada >> palabra;
		}
		entrada.close();
		aux.close();
		remove("Palabras.txt");
		rename("auxiliar.txt", "Palabras.txt");
	}
	
}
void Palabras::ModificarPalabra(ifstream& entrada)
{
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
				aux << nuevapalabra << DELIMITA_CAMPO;
			}
			else {
				aux << palabra << DELIMITA_CAMPO;
			}
			entrada >> palabra;
		}
		entrada.close();
		aux.close();
		remove("Palabras.txt");
		rename("auxiliar.txt", "Palabras.txt");
	}
}