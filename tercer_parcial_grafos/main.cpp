/*
	Realizado por: Jefferson S. Montilla Mendoza C.I 26493551
	Tercer Parcial - Segundo Proyecto
	Estructuras de datos - UNET
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>

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
	return 0;
}


void modificarArchivo(string nombreArchivo, string nombreArchivoAux) {
	/*
		Esta funcion lee los datos del archivo aristas.txt y los guarda en un archivo 
		auxiliar, ya que luego este será usado por la libreria que grafo. De igual modo
		guarda una referencia de los nodos del grafo dentro de un vector auxiliar.
	*/
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
	/*
		Esta funcion busca de manera lineal a través del vector auxiliar 
		para ver si un elemento ya fue insertado.
	*/
    for (int i = 0; i < v.size(); i++)
    	if(v[i] == &busqueda[0])
    		return true;
    		
    return false;
}


bool chequearGrafoConexo(vector<string> listaVertices, Grafo *g) { 
	/*
		Busca verificar si el grafo cargado en la memoria es Conexo o no. 
		Para ello va iterando sobre canda nodo del grafo, y va comparando con el
		resto de nodos si estos pueden llegar a conectarse.
	*/
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
	/*
		Verifica los nodos que son pozos y los que son fuentes dentro del grafo
		Si el grafo es Conexo, no realiza el proceso.
	*/
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
	/*
		Aplica el algoritmo de Dijkstra para ver cual es la ruta
		minima entre dos vertices. Se debe ingresar un determinado valor del
		nodo a través de teclado.
	*/
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
	/*
		Elimina un determinado nodo que el usuario indique.
	*/
	string vertice; 
	cout << "Ingrese el elemento que desea eleminar: "; 
	cin.sync();
	getline(cin, vertice);	
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
	/*
		Menú del usuario, retorna la opción elegida por el usuario.
	*/
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
