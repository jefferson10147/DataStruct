#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

#include "ListaEnlazada.h"
#include "Colas_dinamicas.h"
#include "Bicola.h"

using namespace std;

ListaEnlazada<char*> miLista;
Colas_dinamicas<char*> colaDinamica;
Bicola<char> bicolaPalabras;

bool verificarInfeccion(char *nombre){
	ifstream archivo;
	int MAX_CARACTERES = 500;
	float CRITERIO_INFECCION = 0.9;
	char contenido[MAX_CARACTERES];
	
	archivo.open(nombre);
	if(!archivo.is_open()){
		system("cls");
		cout << "Ha ocurrido un error tratando de verificar la infeccion..." << endl;
		system("pause");
		exit(1);
	}
	
	int i = 0;
	char c;
	
	while(!archivo.eof()){
		archivo.get(c);
		if (c == '\n'){
			contenido[i] = ' ';	
			i ++;
		} else if(!ispunct(c)){
			contenido[i] = c;
			i ++;
		}
	}

	char *ptr;
    ptr = strtok(contenido, " "); 
	int numeroPalabrasEnDiccionario = 0, numeroPalabrasEncontradas = 0;
	 
    while (ptr != NULL){  
		if(miLista.BuscarPalabra(ptr))
			numeroPalabrasEncontradas ++;
		
		numeroPalabrasEnDiccionario ++;
		ptr = strtok(NULL, " ");  
    }  
	archivo.close();
	
	int palabrasNoEncontradas = numeroPalabrasEnDiccionario - numeroPalabrasEncontradas;
	float porcentajeDeInfeccion = (float)palabrasNoEncontradas / (float)numeroPalabrasEnDiccionario;
	cout << "Numero de palabras no encontradas: " << palabrasNoEncontradas << endl;
	cout << "Numero de palabras encontradas: " << numeroPalabrasEncontradas << endl;
	if(porcentajeDeInfeccion > CRITERIO_INFECCION ){
		cout << "Es probable que el archivo se encuentra infectado con el virus Twister ... un total de " << palabrasNoEncontradas << " no fueron reconocidas por nuestro diccionario." << endl;
		system("pause");
		return true;
	}else
		cout << "El archivo no se encuentra infectado con el virus Twister " << porcentajeDeInfeccion << endl;
		
	return false;
	
}

void cargarDiccionario(){
	// Las letras ñ fueron reemplazadas por nh
	ifstream archivo;
	int MAX_CARACTERES = 100000;
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
	cout << "Cargando las palabras volteadas en una Pila de datos..." << endl;
	int MAX_CARACTERES = 1000;
	char contenido[MAX_CARACTERES];
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
	
	cout << "La Pila de palabras ha sido cargada..." << endl;
}

void cargarPalabrasBicola(){
	cout << "Usando estructura de Bicolas para poder voltear las palabras del archivo..." << endl;
	int MAX_CARACTERES_POR_PALABRA = 1000;
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
	cout << "La cola de palabras ha sido cargada..." << endl;	
}

void leerArchivo(char *nombre){
	cout << "Pasando el contenido del archivo a una Cola de datos..." << endl;
	ifstream archivo;
	int MAX_CARACTERES = 1000;
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
	cout << "La cola de palabras ha sido cargada..." << endl;
}


int main(int argc, char** argv) {
	int MAX_NOMBRE = 30;
	char nombre[MAX_NOMBRE];
	
	cout << "Por favor ingrese el nombre del archivo: ";
	cin.sync();
	cin.getline(nombre, MAX_NOMBRE, '\n');
	
	cargarDiccionario();
	if(verificarInfeccion(nombre)){
		cout << "Iniciando restauracion..." << endl;
		leerArchivo(nombre);	
		cargarPalabrasBicola();
		cargarPalabrasOrdenadasEnLaPila(nombre);
	}
	
	system("pause");
	return 0;
}