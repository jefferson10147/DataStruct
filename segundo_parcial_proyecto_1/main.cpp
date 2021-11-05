#include <iostream>

#include "ListaEnlazada.h"
#include "Colas_dinamicas.h"
#include "Bicola.h"
#include "Pilas_dinamicas.h"

using namespace std;

ListaEnlazada<char*> miLista;
Colas_dinamicas<char*> colaDinamica;
Bicola<char> bicolaPalabras;
Pilas_dinamicas<char*> pilaDinamica;

int main(int argc, char** argv) {
	// miLista.Anadir("hola");
	// miLista.Anadir("chao");
	// miLista.Imprimir();
	
	/* COLAS
	colaDinamica.Anadir("holaa");
	colaDinamica.Anadir("chao");
	cout << colaDinamica.Leer();
	cout << endl;
	cout << colaDinamica.Leer();
	cout << "imprimeindo la cola jeje" << endl;
	colaDinamica.Imprimir();
	*/
	
	/* BICOLA PARA LAS PALABRAS
	bicolaPalabras.push_front('a');
	bicolaPalabras.push_front('b');
	bicolaPalabras.push_front('c');
	
	cout << bicolaPalabras.pop_front() << endl;
	cout << bicolaPalabras.pop_front() << endl;
	cout << bicolaPalabras.pop_front() << endl;
	*/
	
	pilaDinamica.Anadir("primero en la pila, deberia ser el ultimo en salir");
	pilaDinamica.Anadir("segundo en la pila, deberia ser el segundo en salir");
	pilaDinamica.Anadir("ultimo en la pila, deberia ser el primero en salir");
	cout << pilaDinamica.Leer() << endl;
	cout << pilaDinamica.Leer() << endl;
	cout << pilaDinamica.Leer() << endl;
	return 0;
}