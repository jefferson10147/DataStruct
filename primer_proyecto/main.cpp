#include <iostream>
#include <string.h>
#include <fstream>

#include "Archivo.h"

using namespace std;


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
        bool disponibleParaAdoptar;
        
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
			disponibleParaAdoptar = true;
		}
		
		Mascota(char *c){
			strcpy(codigo, c);
		}
        
		char *getNom() { return nom; }
		char *getCodigo(){ return codigo; }
		char *getRaza(){ return raza; }
		char *getTipo() { return animal; }
		bool getBandera(){ return disponibleParaAdoptar; }
		bool getEsApto(){ return disponibleParaAdoptar; }
		
        int  getEdad() { return edad; }
        void mostrar(){ cout << getRef() << " " << nom << " " << edad << " " << animal << " " << descripcion << endl; }
        
		char *getRef(){ return codigo; }     
        
        void setDescripcion(char *d){
        	strcpy(descripcion, d);
		}
		
		void setEdad(int e){
			edad = e;
		}
		
		bool getDisponibilidad(){
			return disponibleParaAdoptar;
		}
		
		void setDisponibilidad(bool d){
			disponibleParaAdoptar = d;
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
		bool getBandera(){ return esApto && numeroDeAdopciones < 3; }
		
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
			cout << nombre << " " << edad << " " << telefono << " " << cedula << " Numero de adopciones: " << numeroDeAdopciones << endl;
			if (esApto)
				cout << "El usuario  es apto" << endl << endl;
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
		
		void setNumeroAdopcionesACero(){
			numeroDeAdopciones = 0;
		}
		
		
		void aumentarNumeroAdopciones(){
			numeroDeAdopciones ++;
		}
		
		void disminuirNumeroAdopciones(){
			numeroDeAdopciones --;
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
		
		Adopcion(int r){
			registro = r;
		}
			
		char *getCedula(){
			return cedula;
		}	
		
		char *getCodigo(){
			return codigo;
		}
		
		void mostrar(){ 
			cout << cedula << " " << codigo << " " << fecha << endl;
		}		
		
		int getRegistro(){ return registro; }
		
		char *getRef(){
			return fecha;
		}
		
		bool getBandera(){
			return (bool)registro;
		}
		
		bool getEsApto(){ return 0; }
};


TArchivo<Mascota> archivoMascota((char*)"mascota.dat");
TArchivo<Usuario> archivoUsuario((char*)"usuario.dat");
TArchivo<Adopcion> archivoAdopcion((char*)"adopcion.dat");


int calcularNumeroDeAdopciones(){
	fstream archivo;
	int numeroRegistros = 0;
	
	archivo.open("numero_registros.txt", ios::in);
	
	if (!archivo) {
		cout << "Error en el archivo de registros..." << endl << endl;
		system("pause");
	}else
		archivo >> numeroRegistros;
	
	archivo.close();
	
	return numeroRegistros;
}


void aumentarNumeroDeAdopciones(int numeroRegistros){
	fstream archivo;
	
	archivo.open("numero_registros.txt", ios::out);
	
	if (!archivo) {
		cout << "Error en el archivo de registros..." << endl << endl;
		system("pause");
	}else
		archivo << numeroRegistros;

	archivo.close();
}


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
	int numeroDeRegistros;
	
	cout << "Ingrese la cedula: ";
	cin.sync();
	cin.getline (cedula, 30, '\n');
	
	cout << "Ingrese el codigo: ";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaAdoptar(codigo);
	Usuario personaAdoptar(cedula);
	
	if((archivoMascota.buscar(mascotaAdoptar) >= 0) && (archivoUsuario.buscar(personaAdoptar) >= 0)){
		if (mascotaAdoptar.getDisponibilidad() && personaAdoptar.getEsApto() && personaAdoptar.getNumeroDeAdopciones() < 3){
			cout << "Ingrese la fecha: ";
			cin.sync();
			cin.getline (fecha, 15, '\n');
			
			numeroDeRegistros = calcularNumeroDeAdopciones();
			Adopcion nuevaAdopcion(cedula, codigo, fecha, numeroDeRegistros++);
			aumentarNumeroDeAdopciones(numeroDeRegistros++);
		
			if(archivoAdopcion.insertar(nuevaAdopcion)){
				cout << endl << endl << "Adopcion registrada con exito ;)..." << endl << endl;
				personaAdoptar.aumentarNumeroAdopciones();
				mascotaAdoptar.setDisponibilidad(false);
				
				archivoMascota.actualizar(mascotaAdoptar);
				archivoUsuario.actualizar(personaAdoptar);	
			}else
				cout << endl << endl << "Ha ocurrido un error :(..." << endl << endl;		
		}else
			cout << "No es posible realizar la adopcion para esta persona..." << endl << endl;
	}else
		cout << "Ha introducido los datos incorrectos..." << endl << endl;
		
	system("pause");
}


void listarMascotas(){
	cout << "Mascotas" << endl;
	archivoMascota.listar();
	cout << endl << endl;
	
	cout << "Disponibles para adoptar" << endl;
	archivoMascota.listarAptos();
}


void listarUsuarios(){
	archivoUsuario.listarAptos();
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


void eliminarMascota(){
	char codigo[30];
	
	cout << "Ingrese el codigo de la mascota que desea elimanar del registro:";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaEliminar(codigo);
	
	if(archivoMascota.eliminar(codigo) >= 0)
		cout << "La mascota ha sido eliminada de nuestros registros ..." << endl << endl;
	else
		cout << "Ha ocurrido un error tratando de eliminar la mascota ..."	<< endl << endl;
		
	system("pause");
}


void eliminarUsuario(){
	char cedula[15];
	
	cout << "Ingrese la cedula del usuario que desea eliminar de los registros:";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario usuarioEliminar(cedula);
	cout << usuarioEliminar.getRef() << " Es la cedula jeje " << endl << endl;
	
	if(archivoUsuario.eliminar(usuarioEliminar) >= 0)
		cout << "El usuario ha sido eliminado de los registros ..." << endl << endl;
	else
		cout << "Ha ocurrido un error al eliminar el usuario ..." << endl << endl;
}


void consultarDatosMascota(){
	char codigo[30];
	
	cout << "Ingrese el codigo de la mascota que desea consultar datos:";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaConsultar(codigo);
	
	if(archivoMascota.buscar(mascotaConsultar) >= 0)
		mascotaConsultar.mostrar();
	else
		cout << "La mascota no ha sido encontrada..." << endl << endl;
		
	system("pause");	
}


void consultarDatosUsuario(){
	char cedula[15];
	
	cout << "Ingrese la cedula del usuario que desea consultar:";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario usuarioConsultar(cedula);
	
	if(archivoUsuario.buscar(usuarioConsultar) >= 0)
		usuarioConsultar.mostrar();
	else
		cout << "El usuario no ha sido encontrado..." << endl << endl;
		
	system("pause");
}


void listarPorFecha(){
	char fecha[15];
	
	cout << "Ingrese la fecha como referencia: ";
	cin.sync();
	cin.getline (fecha, 15, '\n');
	
	archivoAdopcion.listarVarios(fecha);
}


void listaNegra(){
	cout << "Imprimiendo la lista negra de usuarios..." << endl;
	archivoUsuario.listarNoAptos();
}


void eliminarDeterminadoRegistro(){
	int posicion;
	
	cout << "Ingrese la posicion de la adopcion que desea eliminar: ";
	cin >> posicion;
	posicion --;
	
	Adopcion registroEspecifico(posicion);
	
	archivoAdopcion.buscarPos(registroEspecifico, posicion);
	
	Mascota mascotaActualizar(registroEspecifico.getCodigo());
	archivoMascota.buscar(mascotaActualizar);
	mascotaActualizar.setDisponibilidad(true);
	archivoMascota.actualizar(mascotaActualizar);
	
	Usuario usuarioActualizar(registroEspecifico.getCedula());
	archivoUsuario.buscar(usuarioActualizar);
	usuarioActualizar.disminuirNumeroAdopciones();
	archivoUsuario.actualizar(usuarioActualizar);
	
	archivoAdopcion.eliminar(registroEspecifico);
	
	cout << "Eliminando..." << endl;
	system("pause");
}

int main() {
	/*
	Mascota a("Manchas", 5, "callejero", "5487L", "De la unet", 'F', "perro");
	Mascota a1("Coqui", 8, "Labrador", "5498CM", "De la unet", 'M', "perro");
	Mascota a2("Wilson", 7, "Gato rubio", "8789LO", "De noruega", 'M', "gato");
	archivoMascota.insertar(a);
	archivoMascota.insertar(a1);
	archivoMascota.insertar(a2);
	
	Usuario u("V26493551", "Jefferson", "Tachira", "Tariba", "Calle 3", "+58 412 54602929", 22);
	Usuario u1("V89754211", "Pedro", "Tachira", "Michelena", "Calle 8", "+58 424 59848578", 25);
	Usuario u2("E98785485", "Milagros", "Norte de Santader", "Cucuta", "Calle 7", "+58 412 54602929", 23);
	archivoUsuario.insertar(u);
	archivoUsuario.insertar(u1);
	archivoUsuario.insertar(u2);
	*/
	
	listarMascotas();
	listarUsuarios();
	listarAdopciones();
	// listarPorFecha();
	// insertarAdopcion();
	// listaNegra();
	eliminarDeterminadoRegistro();
	listarAdopciones();
	
	

    system("pause");
    return EXIT_SUCCESS;
}