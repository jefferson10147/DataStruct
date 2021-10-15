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
        void imprimir(){ cout << nom << " " << edad << " " << animal << endl; }
};

int main() {

	Mascota a("Manchas", 5, "callejero", "5487L", "De la unet", 'F', "perro");
    a.imprimir();
    
    return 0;
}