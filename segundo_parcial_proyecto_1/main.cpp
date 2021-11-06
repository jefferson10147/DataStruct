#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

#include "ListaEnlazada.h"
#include "Colas_dinamicas.h"
#include "Bicola.h"
#include "Pilas_dinamicas.h"
#include "Pila_Array.h"

using namespace std;

ListaEnlazada<char*> miLista;
Colas_dinamicas<char*> colaDinamica;
Bicola<char> bicolaPalabras;
Pilas_dinamicas<char*> pilaDinamica;
Pila_Array<char*> pila;

void verificarInfeccion(){
	
}

void cargarDiccionario(){
	// Las letras ñ fueron reemplazadas por nh
	ifstream archivo;
	int MAX_CARACTERES = 10000;
	char contenido[MAX_CARACTERES];
	
	archivo.open((char*)"palabras.txt");
	if(!archivo.is_open()){
		system("cls");
		cout << "Ha ocurrido un error tratando de leer el archivo infectado..." << endl;
		system("pause");
		exit(1);
	}
	
	int i = 0;
	char c;
	while(!archivo.eof()){
		archivo.get(c);
		if (c == '\n')
			contenido[i] = ' ';
		else
			contenido[i] = c;
		i ++;
	}
	contenido[i - 1] = '\0';
	
	// cout << "contenido-." << contenido << endl;
	char *ptr;
    ptr = strtok(contenido, " ");  
    while (ptr != NULL){  
		miLista.AnadirFinal(ptr); 
        ptr = strtok(NULL, " ");  
    }  
	archivo.close();
}

void cargarPalabrasOrdenadasEnLaPila(char *nombreArchivo){
	int MAX_CARACTERES_POR_PALABRA = 70;
	char contenido[MAX_CARACTERES_POR_PALABRA];
	int i = 0;
	
	while(!bicolaPalabras.isEmpty()){
		contenido[i] = bicolaPalabras.pop_front();
		i ++;	
	}
	
	char *punteroAux;
	punteroAux = strtok(contenido, " ");  
    while (punteroAux != NULL){ 
		colaDinamica.AnadirFinal(punteroAux);
		//pilaDinamica.AnadirFinal(punteroAux);
		punteroAux = strtok(NULL, " ");  
    }
    
    colaDinamica.invert();
    ofstream archivo(nombreArchivo);
    
    if(!archivo.is_open()){
		system("cls");
		cout << "Ha ocurrido un error tratando de guardar la informacion en un nuevo archivo" << endl;
		system("pause");
		exit(1);
	}
	
    while(!colaDinamica.isVacia()){
	    archivo << colaDinamica.Leer();
	    
	    if(colaDinamica.getNumeroElementos() > 0)
	    	archivo << " ";
	}
}

void cargarPalabrasBicola(){
	int MAX_CARACTERES_POR_PALABRA = 50;
	char pAux[MAX_CARACTERES_POR_PALABRA];
	int n = 0;
	
	strcpy(pAux, "");
	while(!colaDinamica.isVacia()){
		strcat(pAux, colaDinamica.Leer());
		strcat(pAux, " ");
	}
	pAux[strlen(pAux) - 1] = '\0';
	
	char *ptr;
	ptr = strtok(pAux, " ");  
    while (ptr != NULL){ 
		n = strlen(ptr);
		for(int i = n - 1; i >= 0 ; i--)
			bicolaPalabras.push_back(ptr[i]);
		
        ptr = strtok(NULL, " ");  
		if (ptr != NULL) bicolaPalabras.push_back(' ');
    }	
}

void leerArchivo(char *nombre){
	ifstream archivo;
	int MAX_CARACTERES = 500;
	char contenido[MAX_CARACTERES];
	
	archivo.open(nombre);
	if(!archivo.is_open()){
		system("cls");
		cout << "Ha ocurrido un error tratando de leer el archivo infectado..." << endl;
		system("pause");
		exit(1);
	}
	
	int i = 0;
	char c;
	
	while(!archivo.eof()){
		archivo.get(c);
		if (c == '\n')
			contenido[i] = ' ';
		else
			contenido[i] = c;
		i ++;
	}
	contenido[i - 1] = '\0';
	
	char *ptr;
    ptr = strtok(contenido, " ");  
    while (ptr != NULL){  
		colaDinamica.AnadirFinal(ptr); 
        ptr = strtok(NULL, " ");  
    }  
	archivo.close();
}


int main(int argc, char** argv) {
	
	
	
	
	leerArchivo((char*)"archivo_prueba.txt");
	

	
	cargarPalabrasBicola();

	
	cargarPalabrasOrdenadasEnLaPila((char*)"archivo_prueba.txt");

	cargarDiccionario();

	//miLista.Imprimir();	
	system("pause");
	return 0;
}