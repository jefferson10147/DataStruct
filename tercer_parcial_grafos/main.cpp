#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#include "Grafo.h"
#include "ListaD.h"
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

vector<string> listaVertices;


void modificarArchivo(string nombreArchivo);
bool existeEnVector(vector<string> v, string busqueda);
bool chequearGrafoConexo(vector<string> v, Grafo *g);
void imprimirFuentesYPozos(vector<string> v, Grafo *g);
void aplicarDijkstra(Grafo *g);
bool eliminarElemento(Grafo *g);


int main(int argc, char** argv) {
	modificarArchivo("aristas.txt");
	
	Grafo *g = new Grafo("aristas.txt",' ', true, true);

	// imprimirFuentesYPozos(listaVertices, g);
	aplicarDijkstra(g);
	
	/*
	for(int x = 0; x < 4; x++) {
		for(int y = 0; y < 4; y++) {
			if (x != y) {
	 			Vertice *v1 = new Vertice(listaVertices[x],0);
				Vertice *v2 = new Vertice(listaVertices[y],0);
				cout << v1->getIdentificador() << " -> "  << v2->getIdentificador() << " = " << g->conectividad(v1,v2) << endl;
			}	
		}
	}
	
	*/
	
	/*ListaD<Vertice>* lista_adyacencia = g->lista_adyacencia;
	Nodo<Vertice>* recorrido = lista_adyacencia->getCab();
	
	
	while( recorrido ) {
		cout << *recorrido->getInfo() << "-> en el main" << endl; // imprimo vertice
		recorrido->getInfo()->vertices_adyacentes->imprimir(); 
		
		cout << endl;
		
		string informacion = recorrido->getInfo()->getIdentificador();
		
		Nodo<Vertice>* segundoRecorrido = lista_adyacencia->getCab();
		while(segundoRecorrido) { 
			string segundaInformacion = segundoRecorrido->getInfo()->getIdentificador();
			
			
			if (!(informacion == segundaInformacion)){
				cout << informacion << "->" << segundaInformacion << " = " << g->conectividad(recorrido->getInfo(), segundoRecorrido->getInfo()) << endl;
			}
			
			segundoRecorrido = segundoRecorrido->getLink_suc(); // recor ser� su sucesor
		}
		
		recorrido = recorrido->getLink_suc(); // recor ser� su sucesor
	} 
	
	*/
//	cout << g->getNumeroVertices() << endl;
	//g->imprimirListaAdyacencia();
	return 0;
}


void modificarArchivo(string nombreArchivo){
	string nombreArchivoAux = "archivo_aux.txt";
	fstream archivo(nombreArchivo, ios::in), nuevoArchivo(nombreArchivoAux, ios::out);
	string linea;
	int i = 0;
	string aux;
	
	if (archivo.fail())
		cout << "Error al abrir el archivo arbol.txt" << endl;
	else 
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			nuevoArchivo << linea[0] << " " << linea[3] << " " << linea[5];
			
			aux = linea[0];
			if(!existeEnVector(listaVertices, aux))
				listaVertices.push_back(aux);
				
			aux = linea[3];
			if(!existeEnVector(listaVertices, aux))
				listaVertices.push_back(aux);
			
			if (!archivo.eof())
				nuevoArchivo << endl;
		}

	archivo.close();
	nuevoArchivo.close();	
	remove(&nombreArchivo[0]);
	rename(&nombreArchivoAux[0], &nombreArchivo[0]);
}


bool existeEnVector(vector<string> v, string busqueda) {
    for (int i = 0; i < v.size(); i++)
    	if(v[i] == &busqueda[0])
    		return true;
    		
    return false;
}


bool chequearGrafoConexo(vector<string> listaVertices, Grafo *g) { 
	int contadorDeGrafosConectados;
	for(int x = 0; x < listaVertices.size(); x++) {
		contadorDeGrafosConectados = 0;
		for(int y = 0; y < listaVertices.size(); y ++){
			if (x != y) {
	 			Vertice *v1 = new Vertice(listaVertices[x], 0);
				Vertice *v2 = new Vertice(listaVertices[y], 0);
				
				if(g->conectividad(v1,v2))
					contadorDeGrafosConectados ++;	
			}	
		}
		
		if(contadorDeGrafosConectados < (g->getNumeroVertices() - 1)){
			cout << "Este grafo no es conexo." << endl;
			return false;
		}
	}
	
	return true;
}


void imprimirFuentesYPozos(vector<string> listaVertices, Grafo *g){
	if(chequearGrafoConexo(listaVertices, g)){
		cout << "El grafo es conexo." << endl;
		return;
	}
		
	int numeroFuentes, numeroPozo;
	for(int x = 0; x < listaVertices.size(); x++) {
		numeroFuentes = 0;
		numeroPozo = 0;
		for(int y = 0; y < listaVertices.size(); y ++){
			if (x != y) {
	 			Vertice *v1 = new Vertice(listaVertices[x], 0);
				Vertice *v2 = new Vertice(listaVertices[y], 0);
				
				if(g->conectividad(v1,v2))
					numeroFuentes ++;
				else 
					numeroPozo ++;	
			}	
			
		}
		
		if(numeroFuentes == (g->getNumeroVertices() - 1))
			cout << "El nodo " << listaVertices[x] << " es una fuente." << endl;
		else if(numeroPozo == (g->getNumeroVertices() - 1))
			cout << "El nodo " << listaVertices[x] << " es un pozo." << endl; 	
	}
}


void aplicarDijkstra(Grafo *g){
	string vertice1, vertice2;
	
	cout << "Ingrese el vertice 1: "; 
	getline(cin, vertice1);	
	cout << "Ingrese el vertice 2: ";
	getline(cin, vertice2);
	
	vertice1 = toupper(vertice1[0]);
	vertice2 = toupper(vertice2[0]);
	
	Vertice *v1 = new Vertice(vertice1, 0);
	Vertice *v2 = new Vertice(vertice2, 0);
	
	if(g->buscarCaminos_MinMaxLongitud_Vertices(v1, v2))
		g->imprimirListaCaminos();
	else
		cout << "Ha ocurrido un error :(" << endl;
	
}
