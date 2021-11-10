/*
	Realizado por: Jefferson S. Montilla Mendoza C.I 26493551
	Tercer Proyecto
	Estructuras de datos
*/

#include <iostream>
#include <cstring>
#include <fstream>

#include "ArbolBB.h"

using namespace std;

void cargarArboles(ArbolBB<string> ListaArbolitos[]);

int main(int argc, char** argv) {
	
	int cantidadArbolitos = 10;
	ArbolBB<string> listaArbolitos[cantidadArbolitos];
	
	cargarArboles(listaArbolitos);
	
	return 0;
}

void cargarArboles(ArbolBB<string> listaArbolitos[]) {
	fstream file("arbol.txt", ios::in);
	string line;
	char *split;
	int i = 0;
	
	if (file.fail())
		cout << "Error al abrir el archivo arbol.txt" << endl;
	else {
		while (getline(file,line)) {
			split = strtok(&line[0], " ");
			while (split) {
				// ListaArbolitos[i].Anadir(atoi(split));
				cout << split << endl;
				split = strtok(NULL, " ");	
			}
			i++;
		}
	}
	
}