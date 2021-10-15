#include <iostream>
#include <string.h>

using namespace std;


enum tipo{gato, perro, conejo};
char Tipo[][10]={"gato","perro","conejo"};

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
		bool esApto = true;
	
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
};

int main() {

	Mascota a("Manchas", 5, "callejero", "5487L", "De la unet", 'F', "perro");
	Usuario u("V26493551", "Jefferson", "Tachira", "Tariba", "Calle 3", "+58 412 54602929", 22);
	
    a.mostrar();
    u.mostrar();
    
    
    return 0;
}