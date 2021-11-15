#include <iostream>
#include <fstream>
#include <cstdio>

#include "Grafo.h"
#include <vector>
#include <string>

using namespace std;


void modificarArchivo(string nombreArchivo);


int main(int argc, char** argv) {
	vector<string> listavertices;
	listavertices.push_back("A");
	listavertices.push_back("B");
	listavertices.push_back("C");
	listavertices.push_back("E");
	
	modificarArchivo("aristas.txt");
	/*
	Grafo *g = new Grafo("aristas.txt",' ', true, true);
	
	
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			if (x != y) {
	 			Vertice *v1 = new Vertice(listavertices[x],0);
				Vertice *v2 = new Vertice(listavertices[y],0);
				cout << v1->getIdentificador() << " -> "  << v2->getIdentificador() << " = " << g->conectividad(v1,v2) << endl;
			}	
		}
	}
	*/
		

	
//	cout << g->getNumeroVertices() << endl;
//	g->imprimirListaAdyacencia();
	return 0;
}

void modificarArchivo(string nombreArchivo){
	string nombreArchivoAux = "archivo_aux.txt";
	fstream archivo(nombreArchivo, ios::in), nuevoArchivo(nombreArchivoAux, ios::out);
	string linea;
	int i = 0;
	
	if (archivo.fail())
		cout << "Error al abrir el archivo arbol.txt" << endl;
	else 
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			nuevoArchivo << linea[0] << " " << linea[3] << " " << linea[5];
			
			if (!archivo.eof())
				nuevoArchivo << endl;
		}

	archivo.close();
	nuevoArchivo.close();	
	remove(&nombreArchivo[0]);
	rename(&nombreArchivoAux[0], &nombreArchivo[0]);
}
