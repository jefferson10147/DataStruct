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
		
		Mascota(char *c){
			strcpy(codigo, c);
		}
        
		char *getNom() { return nom; }
		char *getCodigo(){ return codigo; }
		char *getRaza(){ return raza; }
		char *getTipo() { return animal; }
		
        int  getEdad() { return edad; }
        void mostrar(){ cout << getRef() << " con cambio eh " << nom << " " << edad << " " << animal << " " << descripcion << endl; }
        
		char *getRef(){ return codigo; }     
        
        void setDescripcion(char *d){
        	strcpy(descripcion, d);
		}
		
		void setEdad(int e){
			edad = e;
		}
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
		
		Usuario(char *ci){
			strcpy(cedula, ci);
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
		
		void setEstado(char *e){
			strcpy(estado, e);
		}
		
		void setCiudad(char *c){
			strcpy(ciudad, c);
		}
		
		void setDireccion(char *d){
			strcpy(direccion, d);
		}
		
		void setTelefono(char *t){
			strcpy(telefono, t);
		}
		
		void setEdad(int e){
			edad = e;
		}
};

class Adopcion
{
	private:
		char cedula[30];
		char codigo[30];
		char fecha[15];
		int registro;
	
	public:
		static int totalMascotasAdoptadas;
		
		Adopcion(){ }
		
		Adopcion(char *ci, char *c, char *f, int r){
			strcpy(cedula, ci);
			strcpy(codigo, c);
			strcpy(fecha, f);
			registro = r;
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
	
	Adopcion nuevaAdopcion(cedula, codigo, fecha, numeroDeRegistros++);
	
	if(archivoAdopcion.insertar(nuevaAdopcion)){
		cout << endl << endl << "Adopcion registrada con exito ;)" << endl << endl;
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


void actualizarMascota(){
	char descripcion[255];
	char codigo[30];
	int edad;
	
	cout << "Ingrese el codigo de la mascota que desea actualizar:";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaActualizar(codigo);
	
	if(archivoMascota.buscar(mascotaActualizar) >= 0){
		cout << "Ingrese la descripcion: ";
		cin.sync();
		cin.getline (descripcion, 255, '\n');
	
		cout << "Ingrese la edad: ";
		cin >> edad;
		
		mascotaActualizar.setDescripcion(descripcion);
		mascotaActualizar.setEdad(edad);
		
		archivoMascota.actualizar(mascotaActualizar);
	}else
		cout << "Codigo de mascota incorrecto ... " << endl << endl;
	
	system("pause");
}


void actualizarUsuario(){
	char cedula[15];
	char estado[30];
	char ciudad[30];
	char direccion[30];
	char telefono[30];
	int edad;
	
	cout << "Ingrese la cedula del usuario que desea actualizar:";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario usuarioActualizar(cedula);
	
	if(archivoUsuario.buscar(usuarioActualizar) >= 0){
		cout << "Ingrese el nuevo estado donde reside: ";
		cin.sync();
		cin.getline (estado, 30, '\n');
	
		cout << "Ingrese la nueva ciudad donde reside: ";
		cin.sync();
		cin.getline (ciudad, 30, '\n');
	
		cout << "Ingrese la nueva direccion donde reside: ";
		cin.sync();
		cin.getline (direccion, 30, '\n');
	
		cout << "Ingrese el nuevo telefono que posee: ";
		cin.sync();
		cin.getline (telefono, 30, '\n');
	
		cout << "Ingrese la edad: ";
		cin >> edad;
		
		usuarioActualizar.setEstado(estado);
		usuarioActualizar.setCiudad(ciudad);
		usuarioActualizar.setDireccion(direccion);
		usuarioActualizar.setTelefono(telefono);
		usuarioActualizar.setEdad(edad);
		
		archivoUsuario.actualizar(usuarioActualizar);
	}else
		cout << "Usuario no encontrado ... " << endl;
		
	system("pause");
}


int main() {

	listarMascotas();
	listarUsuarios();
	listarAdopciones();

	cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}