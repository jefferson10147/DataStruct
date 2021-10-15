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
		static int totalMascotasAdoptadas;
		
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

TArchivo<Mascota> archivoMascota((char*)"mascota.dat");
TArchivo<Usuario> archivoUsuario((char*)"usuario.dat");
TArchivo<Adopcion> archivoAdopcion((char*)"adopcion.dat");


int main() {

	Mascota a("Manchas", 5, "callejero", "5487L", "De la unet", 'F', "perro");
	Mascota a1("Coqui", 8, "Labrador", "5498CM", "De la unet", 'M', "perro");
	Mascota a2("Wilson", 7, "Gato rubio", "8789LO", "De noruega", 'M', "gato");
	
	Usuario u("V26493551", "Jefferson", "Tachira", "Tariba", "Calle 3", "+58 412 54602929", 22);
	Usuario u1("V89754211", "Pedro", "Tachira", "Michelena", "Calle 8", "+58 424 59848578", 25);
	Usuario u2("E98785485", "Milagros", "Norte de Santader", "Cucuta", "Calle 7", "+58 412 54602929", 23);
	
	Adopcion adop("V26493551", "5498CM", "27/10/21");
	Adopcion adop1("E98785485", "5487L", "13/11/21");
	
    
    cout  << endl << endl << "numero de registros " << ++numeroDeRegistros << endl << endl;
	
	cout << "Archivos:" << endl;
	cout << archivoMascota.get_nomb() << endl;
	cout << archivoUsuario.get_nomb() << endl;
	cout << archivoAdopcion.get_nomb() << endl;
	
	cout << "Insertando datos a los archivos..." << endl;
	archivoMascota.insertar(a);
	archivoMascota.insertar(a1);
	archivoMascota.insertar(a2);
	archivoUsuario.insertar(u);
	archivoUsuario.insertar(u1);
	archivoUsuario.insertar(u2);
	archivoAdopcion.insertar(adop);
	archivoAdopcion.insertar(adop1);
	cout << endl << endl;
	
	cout << "Listado de mascotas:" << endl;
	archivoMascota.listar();
	cout << endl << endl;
	
	cout << "Listado de Usuarios" << endl;
	archivoUsuario.listar();
	cout << endl << endl;
	
	cout << "Listado de Adopciones" << endl;
	archivoAdopcion.listar();
	cout << endl << endl;
	
	cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}