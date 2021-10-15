#include <iostream>
#include <string.h>

#include "Archivo.h"

using namespace std;


int numeroDeRegistros = 0;

class Mascota
{
    private:
        char nom[30];
        char raza[30];
        char codigo[30];
        char descripcion[255];
        char sexo;
        int  edad;
        char animal[30];
        
    public:
        Mascota() { }
        
		Mascota(char *n, int e, char *r, char *c, char *d, char s, char *tip){ 
			strcpy(nom, n);
			strcpy(raza, r);
			strcpy(codigo, c);
			strcpy(descripcion, d);
			edad = e;
			strcpy(animal, tip);
			sexo = s;
		}
        
		char *getNom() { return nom; }
		char *getCodigo(){ return codigo; }
		char *getRaza(){ return raza; }
		char *getTipo() { return animal; }
		
        int  getEdad() { return edad; }
        void mostrar(){ cout << nom << " " << edad << " " << animal << endl; }
};


class Usuario 
{
	private:
		char cedula[15];
		char nombre[30];
		char estado[30];
		char ciudad[30];
		char direccion[30];
		char telefono[30];
		int edad;
		bool esApto;
		int numeroDeAdopciones;
	
	public: 
		Usuario() { }
		Usuario(char *ci, char *n, char *e, char *c, char *d, char *t, int edad){
			strcpy(cedula, ci);
			strcpy(nombre, n);
			strcpy(estado, e);
			strcpy(ciudad, c);
			strcpy(direccion, d);
			strcpy(telefono, t);
			this->edad = edad;
			esApto = true;
			numeroDeAdopciones = 0;
		}
		
		char *getRef(){
			return cedula;
		}
		
		void mostrar(){ 
			cout << nombre << " " << edad << " " << telefono << endl;
		}
		
		void setEsApto(bool esApto){
			this->esApto = esApto;
		}
		
		bool getEsApto(){
			return esApto;
		}
		
		int getNumeroDeAdopciones(){
			return numeroDeAdopciones;
		}
		
		void aumentarNumeroAdopciones(){
			numeroDeAdopciones ++;
		}
};

class Adopcion
{
	private:
		char cedula[30];
		char codigo[30];
		char fecha[15];
	
	public:
		Adopcion(){ }
		
		Adopcion(char *ci, char *c, char *f){
			strcpy(cedula, ci);
			strcpy(codigo, c);
			strcpy(fecha, f);
		}
			
		void mostrar(){ 
			cout << cedula << " " << codigo << " " << fecha << endl;
		}
	
};

int main() {

	Mascota a("Manchas", 5, "callejero", "5487L", "De la unet", 'F', "perro");
	Usuario u("V26493551", "Jefferson", "Tachira", "Tariba", "Calle 3", "+58 412 54602929", 22);
	Adopcion adop("V26493551", "5487L", "27/10/21");
	
    a.mostrar();
    u.mostrar();
    adop.mostrar();
    
    cout << "numero de registros " << ++numeroDeRegistros << endl;
	  
	cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}