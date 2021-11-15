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
string nombreArchivo = "aristas.txt";
string nombreArchivoAux = "archivo_aux.txt";

void modificarArchivo(string nombreArchivo, string nombreArchivoAux);
bool existeEnVector(vector<string> v, string busqueda);
bool chequearGrafoConexo(vector<string> v, Grafo *g);
void imprimirFuentesYPozos(vector<string> v, Grafo *g);
void aplicarDijkstra(Grafo *g);
void eliminarElemento(Grafo *g);
int menu();


int main(int argc, char** argv) {
	modificarArchivo(nombreArchivo, nombreArchivoAux);
	Grafo *g = new Grafo(nombreArchivoAux,' ', true, true);
	
	int opcionMenu;
	while(opcionMenu = menu()){
		switch(opcionMenu){
			case 1:
				g->imprimirListaAdyacencia();
				break;
			
			case 2:
				if (chequearGrafoConexo(listaVertices, g))
					cout << "El grafo es conexo :D" << endl;
				break;
				
			case 3:
				imprimirFuentesYPozos(listaVertices, g);
				break;
				
			case 4:
				eliminarElemento(g);
				break;
				
			case 5:
				aplicarDijkstra(g);
				break;	
		}
		system("pause");
		system("cls");
	}

	// imprimirFuentesYPozos(listaVertices, g);
	// aplicarDijkstra(g);
	// eliminarElemento(g);
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


void modificarArchivo(string nombreArchivo, string nombreArchivoAux) {
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


void imprimirFuentesYPozos(vector<string> listaVertices, Grafo *g) {
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


void aplicarDijkstra(Grafo *g) {
	string vertice1, vertice2;
	
	cout << "Ingrese el vertice 1: "; 
	cin.sync();
	getline(cin, vertice1);	
	cout << "Ingrese el vertice 2: ";
	cin.sync();
	getline(cin, vertice2);
	
	vertice1 = toupper(vertice1[0]);
	vertice2 = toupper(vertice2[0]);
	
	Vertice *v1 = new Vertice(vertice1, 0);
	Vertice *v2 = new Vertice(vertice2, 0);
	
	if(g->buscarCaminos_MinMaxLongitud_Vertices(v1, v2))
		g->imprimirListaCaminos();
	else
		cout << "Ha ocurrido un error :(" << endl;
	
	cout << endl;
}


void eliminarElemento(Grafo *g) {
	string vertice; 
	cout << "Ingrese el elemento que desea eleminar: "; 
	getline(cin, vertice);	
	cin.sync();
	vertice = toupper(vertice[0]);
	
	Vertice *v1 = new Vertice(vertice, 0);
	
	if(g->lista_adyacencia->eliminar(0, v1))
		cout << "Se pudo eliminar el elemento. :D" << endl;
	else
		cout << "No se pudo eliminar el elemento." << endl;
		
	system("pause");
	g->imprimirListaAdyacencia();	
}


int menu(){
	int opcion;
	
	cout << "=================================================" << endl;
	cout << "1. Imprimir Grafo." << endl;
	cout << "2. Determinar si el Grafo es conexo." << endl;
	cout << "3. Determinar nodos fuentes y pozos dentro del grafo." << endl;
	cout << "4. Eliminar nodo." << endl;
	cout << "5. Aplicar Dijkstra para la ruta minima entre dos vertices." << endl;
	cout << "0. Salir." << endl;
	cout << "\nIngrese la opcion: ";
	cin >> opcion; 
	
	return opcion;
}
