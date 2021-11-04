#include <iostream>

#include "ListaEnlazada.h"

using namespace std;

ListaEnlazada<int> miLista;

int main(int argc, char** argv) {
	cout << "init..." << endl;
	miLista.Anadir(5);
	miLista.Anadir(4);
	miLista.Anadir(3);
	
	miLista.Imprimir();
	
	cout << endl;
	int valor = 4;
	miLista.Eliminar(valor);
	cout << "El valor es " << valor << endl;
	miLista.Imprimir();
	return 0;
}