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
	// miLista.Anadir("hola");
	// miLista.Anadir("chao");
	// miLista.Imprimir();
	
	/*//COLAS
	colaDinamica.Anadir("holaa");
	colaDinamica.Anadir("chao");
	cout << colaDinamica.Leer();
	cout << endl;
	cout << colaDinamica.Leer();
	cout << "imprimeindo la cola jeje" << endl;
	colaDinamica.Imprimir();
	*/
	
	 // BICOLA PARA LAS PALABRAS
	/*char primera = 'a';
	char segunda = 'b';
	char tercera = 'c';
	bicolaPalabras.push_front(primera);
	bicolaPalabras.push_front(segunda);
	bicolaPalabras.push_front(tercera);
	
	cout << "primera " << bicolaPalabras.pop_front() << endl;
	cout << "segunda " << bicolaPalabras.pop_front() << endl;
	cout << "tercera " << bicolaPalabras.pop_front() << endl;
	*/
	 /*
	char primero = 'A';
	for(int i = 0; i < 10; i++){
		bicolaPalabras.push_front(primero);
	}
	
	while(!bicolaPalabras.isEmpty())
		cout << bicolaPalabras.pop_front() << endl;
	*/
	//PILA PARA ORDENAR EL ARCHIVO
	/*char *str = "";
	char *str3 = "primero en la pila, deberia ser el ultimo en salir";
	str = str3;
	cout << "direccion 1 " << &str << " direccion 2 " << &str3 << endl;
	pilaDinamica.Anadir(str);
	char *str4 = "segundo en la pila, deberia ser el segundo en salir";
	str = str4;
	pilaDinamica.Anadir(str);
	cout << "direccion 1 " << &str << " direccion 2 " << &str4 << endl;
	pilaDinamica.Anadir("ultimo en la pila, deberia ser el primero en salir");
	cout << pilaDinamica.Leer() << endl;
	cout << pilaDinamica.Leer() << endl;
	cout << pilaDinamica.Leer() << endl;*/
	
	
	
	leerArchivo((char*)"archivo_prueba.txt");
	
	/*cout << "CONTENIDO EN LA COLA " << endl;
	colaDinamica.Imprimir();
	cout << endl;
	cout << "Numero de elementos en la cola " << colaDinamica.getNumeroElementos() << endl;
	cout << endl << endl;
	pila.setTamano(colaDinamica.getNumeroElementos());*/
	
	cargarPalabrasBicola();
	/*cout << "CONTENIDO DE LA BICOLA " << endl;
	bicolaPalabras.print();
	cout << "\nNumero de elementos en la bicola " << bicolaPalabras.getNumeroElementos() << endl;*/
	
	//while(!bicolaPalabras.isEmpty())
	//	cout << bicolaPalabras.pop_front();
	//cout << endl << endl;
	
	cargarPalabrasOrdenadasEnLaPila((char*)"archivo_prueba.txt");
	//pila.Imprimir();
	// pilaDinamica.Imprimir();
	// cout << pilaDinamica.Leer();
	// cout << pilaDinamica.Leer();
	cout << endl << endl; 
	
	
	/*
	char *str = "hola";
	char *str2 = "chao";
	pila.Anadir(str);
	pila.Anadir(str2);
	int i = 0;
	pila.Imprimir();
	char *str3 = "";
	cout << endl << endl;
	cout << pila.Leer(str3) << str3 << endl;
	cout << pila.Leer(str3) << str3 << endl;
	*/
	return 0;
}