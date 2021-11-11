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

string nombreArchivo = "arbol.txt";

int numeroDeRegistros();
void cargarArboles(ArbolBB<string> ListaArbolitos[]);


int main(int argc, char** argv) {
	int cantidadArbolitos = numeroDeRegistros();
	
	if(cantidadArbolitos <= 0)
		return 0;
		
	ArbolBB<string> listaArbolitos[cantidadArbolitos];
	cargarArboles(listaArbolitos);
	
	for (int i = 0; i < cantidadArbolitos; i++) {
		cout << "Arbol " << i + 1 << ":" << endl;
		listaArbolitos[i].imprimir(3);
		cout << "Altura: " << listaArbolitos[i].AlturaArbol();
		cout << endl << "------------------" << endl;		
	}
	
	return 0;
}


int numeroDeRegistros() {
	fstream file(nombreArchivo, ios::in);
	string line;
	int i = 0;
	
	if (file.fail())
		cout << "Error al abrir el archivo arbol.txt" << endl;
	else 
		while (getline(file,line)) 
			i++;
	
	return i;
}


void cargarArboles(ArbolBB<string> listaArbolitos[]) {
	fstream file(nombreArchivo, ios::in);
	string line;
	char *split;
	int i = 0;
	
	if (file.fail())
		cout << "Error al abrir el archivo arbol.txt" << endl;
	else {
		while (getline(file,line)) {
			split = strtok(&line[0], " ");
			split = strtok(NULL, " ");
			while (split) {
				listaArbolitos[i].Anadir(split);
				split = strtok(NULL, " ");	
			}
			i++;
		}
	}
}