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


void insertarMascota(){
	char nom[30];
    char raza[30];
    char codigo[30];
    char descripcion[255];
    char sexo;
    int  edad;
    char animal[30];
    
	cout << "Ingrese el nombre: ";
	cin.sync();
	cin.getline (nom, 30, '\n');
	
	cout << "Ingrese la raza: ";
	cin.sync();
	cin.getline (raza, 30, '\n');
	
	cout << "Ingrese el codigo: ";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	cout << "Ingrese la descripcion: ";
	cin.sync();
	cin.getline (descripcion, 255, '\n');
	
	cout << "Ingrese el sexo (F/M) de la mascota:";
	cin >> sexo;
	
	cout << "Ingrese la edad: ";
	cin >> edad;
	
	cout << "Ingrese el tipo de animal: ";
	cin.sync();
	cin.getline (animal, 30, '\n');
	
	Mascota nuevaMascota(nom, edad, raza, codigo, descripcion, sexo, animal);
	
	if (archivoMascota.insertar(nuevaMascota))
		cout << endl << endl << "Mascota regitrada con exito :)" << endl << endl;
	else
		cout << endl << endl << "Ha ocurrido un error al registar la mascota :(" << endl << endl;
		
	system("pause");
}


void insertarUsuario(){
	char cedula[15];
	char nombre[30];
	char estado[30];
	char ciudad[30];
	char direccion[30];
	char telefono[30];
	int edad;
	
	cout << "Ingrese la cedula: ";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	cout << "Ingrese el nombre: ";
	cin.sync();
	cin.getline (nombre, 30, '\n');
	
	cout << "Ingrese el estado: ";
	cin.sync();
	cin.getline (estado, 30, '\n');
	
	cout << "Ingrese la ciudad: ";
	cin.sync();
	cin.getline (ciudad, 30, '\n');
	
	cout << "Ingrese la direccion: ";
	cin.sync();
	cin.getline (direccion, 30, '\n');
	
	cout << "Ingrese el telefono: ";
	cin.sync();
	cin.getline (telefono, 30, '\n');
	
	cout << "Ingrese la edad: ";
	cin >> edad;
	
	Usuario nuevoUsuario(cedula, nombre, estado, ciudad, direccion, telefono, edad);
	
	if (archivoUsuario.insertar(nuevoUsuario))
		cout << endl << endl << "Usuario ingresado con exito :)" << endl << endl;
	else
		cout << endl << endl << "Ha ocurrido un problema ingresando usuario :(" << endl << endl;
		
	system("pause");
}


void insertarAdopcion(){
	char cedula[30];
	char codigo[30];
	char fecha[15];
	
	cout << "Ingrese la cedula: ";
	cin.sync();
	cin.getline (cedula, 30, '\n');
	
	cout << "Ingrese el codigo: ";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	cout << "Ingrese la fecha: ";
	cin.sync();
	cin.getline (fecha, 15, '\n');
	
	Adopcion nuevaAdopcion(cedula, codigo, fecha);
	
	if(archivoAdopcion.insertar(nuevaAdopcion)){
		cout << endl << endl << "Adopcion registrada con exito ;)" << endl << endl;
		numeroDeRegistros++;
	}else
		cout << endl << endl << "Ha ocurrido un error :(" << endl << endl;
	
	system("pause");
}


void listarMascotas(){
	archivoMascota.listar();
	cout << endl << endl;
}


void listarUsuarios(){
	archivoUsuario.listar();
	cout << endl << endl;
}


void listarAdopciones(){
	archivoAdopcion.listar();
	cout << endl << endl;
}


int main() {
	
	insertarMascota();
	insertarUsuario();
	insertarAdopcion();
	
	listarMascotas();
	listarUsuarios();
	listarAdopciones();

	cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}