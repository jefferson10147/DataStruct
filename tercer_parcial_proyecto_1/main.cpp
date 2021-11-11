/*
	Realizado por: Jefferson S. Montilla Mendoza C.I 26493551
	Tercer Parcial
	Estructuras de datos
*/

#include <iostream>
#include <cstring>
#include <fstream>

#include "ArbolBB.h"

using namespace std;

string nombreArchivo = "arbol.txt";

int numeroDeRegistros();
void cargarArboles(ArbolBB<string> listaArbolitos[]);
void imprimirArboles(ArbolBB<string> listaArbolitos[], int cantidadArbolitos);


int main(int argc, char** argv) {
	int cantidadArbolitos = numeroDeRegistros();
	
	if(cantidadArbolitos <= 0)
		return 0;
		
	ArbolBB<string> listaArbolitos[cantidadArbolitos];
	cargarArboles(listaArbolitos);
	imprimirArboles(listaArbolitos, cantidadArbolitos);
	
	system("pause");
	return 0;
}


int numeroDeRegistros() {
	/*Esta función obtiene el numero de lineas que hay en el archivo arbol.txt*/
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
	/*Lee cada linea que hay en el archivo arbol.txt carga los arboles en la lista de arbolitos*/
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


void imprimirArboles(ArbolBB<string> listaArbolitos[], int cantidadArbolitos) {
	/*Recorre cada elemento de la lista de arbolitos, los imprime en post orden, imprime la altura,
	chequea si el arbol está equilibrado, imprime todos los nodos que son hojas*/
	ArbolBB<string> aux;
	int cont = 0;
	
	for (int i = 0; i < cantidadArbolitos; i++) {
		cout << "Arbol " << i + 1 << ":" << endl;
		listaArbolitos[i].imprimir(3);
		
		cout << endl << "Altura: " << listaArbolitos[i].AlturaArbol() << endl;
		
		aux = listaArbolitos[i];
		cont = 0;
		if (aux.EsAVL(cont, true) == 0)
			cout << endl << "Es un arbol equilibrado!" << endl;
		else
			cout << endl << "No es un arbol equilibrado!" << endl;
			
		cout << endl << "Los nodos hojas son: " << endl;
		listaArbolitos[i].ImprimirHojas();
			
		cout << endl << "------------------" << endl;		
	}
}

