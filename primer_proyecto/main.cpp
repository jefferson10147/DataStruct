#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <ctime>

#include "Archivo.h"
#include "MezclaEquilibrada.h"
#include "MezclaDirecta.h"

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
        
        void hacerEncabezado(){
			cout << "{Nombre}-{Raza}-{Codigo}-{Sexo}-{Edad}-{Animal}" << endl << endl;
		}
		
        void mostrar(){ 
			cout << "{" << nom << "}-{" << raza << "}-{" << codigo << "}-{" << sexo << "}-{" << edad << "}-{" << animal << "}" << endl;
			cout << "{" << descripcion << "}" << endl;
			
			if (disponibleParaAdoptar)
				cout << "Se encuentra disponible para adoptar..." << endl << endl;
		}
        
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
		
		void setValue(char *c){ strcmp(codigo, c); }
		
		bool operator < (Mascota &obj){ 
			if (strcmp(codigo, obj.getRef()) < 0)
				return true;
			else
				return false;
			// return ced < obj.get_clave(0);
		}
		
		
      	bool operator <= (Mascota &obj){ 
      		if (strcmp(codigo, obj.getRef()) <= 0)
				return true;
			else
				return false;
		  // return ced <= obj.get_clave(0);
		}
		
      	bool operator > (Mascota &obj){ 
      		if (strcmp(codigo, obj.getRef()) > 0)
				return true;
			else
				return false;
		  // return ced > obj.get_clave(0);
		}
      
        
	  	bool operator >= (Mascota &obj){ 
	  		if (strcmp(codigo, obj.getRef()) >= 0)
				return true;
			else
				return false;
		  // return ced >= obj.get_clave(0);
		}
		
		  
	    bool operator == (Mascota &obj){ 
	    	if (strcmp(codigo, obj.getRef()) == 0)
				return true;
			else
				return false;
			// return ced == obj.get_clave(0);
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
		
		void hacerEncabezado(){
			cout << "{Nombre}-{Edad}-{Telefono}-{Cedula}-{Direccion}-{Ciudad}-{Estado}" << endl << endl;
		}
		
		void mostrar(){ 
			cout << "{ "<< nombre << " }-{ " << edad << " }-{ " << telefono << " }-{ " << cedula << " }-{ " << direccion << " }-{ " << ciudad << " }-{ " << estado << " }" << endl;
			if (esApto)
				cout << "El usuario  es apto para adoptar una mascota" << endl << "Numero de adopciones: " << numeroDeAdopciones << endl << endl;
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
		
		Adopcion(char *ci){
			strcpy(cedula, ci);
		}
			
		char *getCedula(){
			return cedula;
		}	
		
		char *getCodigo(){
			return codigo;
		}
		
		void hacerEncabezado(){
			cout << "{Cedula}-{Codigo}-{Fecha}" << endl << endl;
		}
		
		void mostrar(){ 
			cout << "{" << cedula << "}-{" << codigo << "}-{" << fecha << "}" << endl << endl;
		}		 
		
		int getRegistro(){ return registro; }
		
		char *getRef(){
			return cedula;
		}
		
		bool getBandera(){
			return (bool)registro;
		}
		
		bool getEsApto(){ return 0; }
};


TArchivo<Mascota> archivoMascota((char*)"mascota.dat");
TArchivo<Usuario> archivoUsuario((char*)"usuario.dat");
TArchivo<Adopcion> archivoAdopcion((char*)"adopcion.dat");
TArchivo<Mascota> archivoOrdenados((char*)"ordenado.dat");

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
	
	archivoOrdenados.insertar(nuevaMascota);
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
	cout << endl << "\t======Listado de mascotas disponibles para adoptar ======" << endl << endl;
	archivoMascota.listarAptos();
	system("pause");
}


void listarUsuarios(){
	cout << endl << "\t======Listado de personas disponibles para adoptar===" << endl;
	archivoUsuario.listarAptos();
	cout << endl << endl;
	system("pause");
}


void listarAdopciones(){
	cout << endl << "\t======Listado de adopciones===" << endl;
	archivoAdopcion.listar();
	cout << endl << endl;
	system("pause");
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
	
	archivoOrdenados.eliminar(mascotaEliminar);
	system("pause");
}


void eliminarUsuario(){
	char cedula[15];
	
	cout << "Ingrese la cedula del usuario que desea eliminar de los registros:";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario usuarioEliminar(cedula);
	
	if(archivoUsuario.eliminar(usuarioEliminar) >= 0)
		cout << "El usuario ha sido eliminado de los registros ..." << endl << endl;
	else
		cout << "Ha ocurrido un error al eliminar el usuario ..." << endl << endl;
		
	system("pause");
}


void consultarDatosMascota(){
	char codigo[30];
	
	cout << "Ingrese el codigo de la mascota que desea consultar datos:";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaConsultar(codigo);
	
	if(archivoMascota.buscar(mascotaConsultar) >= 0){
		mascotaConsultar.hacerEncabezado();
		mascotaConsultar.mostrar();
	}else
		cout << "La mascota no ha sido encontrada..." << endl << endl;
		
	system("pause");	
}


void consultarDatosUsuario(){
	char cedula[15];
	
	cout << "Ingrese la cedula del usuario que desea consultar:";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario usuarioConsultar(cedula);
	
	if(archivoUsuario.buscar(usuarioConsultar) >= 0){
		usuarioConsultar.hacerEncabezado();
		usuarioConsultar.mostrar();
	}else
		cout << "El usuario no ha sido encontrado..." << endl << endl;
		
	system("pause");
}


void listarPorFecha(){
	char fecha[15];
	
	cout << "Ingrese la fecha como referencia: ";
	cin.sync();
	cin.getline (fecha, 15, '\n');
	
	archivoAdopcion.listarVarios(fecha);
	system("pause");
}


void listaNegra(){
	cout << "Imprimiendo la lista negra de usuarios..." << endl;
	archivoUsuario.listarNoAptos();
	system("pause");
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


void reportarUsuario(){
	char cedula[15];
	
	cout << "Ingrese la cedula del usuario que desea reportar: ";
	cin.sync();
	cin.getline (cedula, 15, '\n');
	
	Usuario auxUsuario(cedula);	
	Adopcion auxAdopcion(cedula);
	
	if (archivoUsuario.buscar(auxUsuario) >= 0){
		while(archivoAdopcion.buscar(auxAdopcion) >= 0){
			Mascota mascotaActualizar(auxAdopcion.getCodigo());
			archivoMascota.buscar(mascotaActualizar);
			mascotaActualizar.setDisponibilidad(true);
			archivoMascota.actualizar(mascotaActualizar);
			
			archivoAdopcion.eliminarDatoEspecifico(auxAdopcion);
			auxAdopcion = Adopcion(cedula);
		}
		
		auxUsuario.setEsApto(false);
		auxUsuario.setNumeroAdopcionesACero();
		archivoUsuario.actualizar(auxUsuario);	
	}else
		cout << "No hay ningun usuario registrado con esa cedula..." << endl << endl;

	system("pause");	
}


template <class t>
int pivote(t v[], int start, int end) 
{    
    t pivot = v[end];  
    int i = (start - 1);

    for (int j = start; j <= end- 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;    
            swap(v[i],v[j]);
        }
    }
    swap (v[i+1],v[end]);
    return (i + 1);
}

template <class t>
void quickSort(t v[], int start, int end)
{
  
  int pospiv;    
  if(start < end) {
    pospiv = pivote(v, start, end);
    quickSort(v, start, pospiv-1);
    quickSort(v, pospiv+1, end);    
  }              
}


template <class t>
void heapify(t arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 

template <class t>
void heapSort(t arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


template <class t>
int buscarBinaria (t v[], int n, t &clave ){
  
  int m, li = 0, ls = n-1;
  while (li <= ls ){
    m = (li + ls) /2;
    if (clave == v [m]){
    	clave = v[m];
		return m;	
	} 
    
    if (clave < v[m]) ls = m-1;
    else li = m+1;
  }
  
  return -1;
}


void getListaElementos(Mascota v[]){
	ifstream archivo("ordenado.dat");
	
	if(!archivo)
		archivoMascota.getVector(v);
	else
		archivoOrdenados.getVector(v);
	
	system("pause");
}


void insertarVectorOrdenado(Mascota v[], int n){
	archivoOrdenados.reset();
	
	for(int i = 0; i < n; i ++)
		archivoOrdenados.insertar(v[i]);		
}


void listarVector(){
	int n = archivoMascota.listar();
	Mascota v[n];
	system("cls");
	getListaElementos(v);
	
	for(int i = 0; i < n; i ++)
		v[i].mostrar();
	
	insertarVectorOrdenado(v, n);
	system("pause");		
}

	
void listarArchivosMascotas(){
	archivoMascota.listar();
	system("pause");
}


void ordenarMezclaEquilibrada(){
	unsigned t0, t1;
	MezclaEquilibrada<Mascota> mezclaEquilibradaMascota((char *)"mascota.dat");
	
	t0 = clock();
	mezclaEquilibradaMascota.ordenar();
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	cout << "Archivo ordenado por metodo de Mezcla Equilibrada :)" << endl;
	cout << "Ha tomado un tiempo de: " << time << " segundos."<< endl;
	system("pause");
}


void ordenarMezclaDirecta(){
	unsigned t0, t1;
	MezclaDirecta<Mascota> mezclaDirectaMascota((char*)"mascota.dat");
	int n = archivoMascota.listar();
	
	t0 = clock();
	mezclaDirectaMascota.Ordenar(n);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	cout << "Archivo ordenado por metodo de Mezcla Directa :)" << endl;
	cout << "Ha tomado un tiempo de: " << time << " segundos."<< endl;
	system("pause");
}


void ordenarQuicksort(){
	unsigned t0, t1;
	int n = archivoMascota.listar();
	Mascota v[n];
	system("cls");
	getListaElementos(v);
	
	t0 = clock();
	quickSort(v, 0, n - 1);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	insertarVectorOrdenado(v, n);
	cout << "Archivo ordenado por metodo de Quicksort :)" << endl;
	cout << "Ha tomado un tiempo de: " << time << " segundos."<< endl;
} 


void ordenarHeapsort(){
	unsigned t0, t1;
	int n = archivoMascota.listar();
	Mascota v[n];
	system("cls");
	getListaElementos(v);
	
	t0 = clock();
	heapSort(v, n);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	insertarVectorOrdenado(v, n);
	cout << "Archivo ordenado por metodo de Heapsort :)" << endl;
	cout << "Ha tomado un tiempo de: " << time << " segundos."<< endl;
	system("pause");
}


void buscarBinario(){
	char codigo[30];
	unsigned t0, t1;
	
	cout << "Ingrese el codigo de la mascota que desea actualizar:";
	cin.sync();
	cin.getline (codigo, 30, '\n');
	
	Mascota mascotaBuscar(codigo);
	
	ordenarQuicksort();
	
	int n = archivoMascota.listar();
	Mascota v[n];
	getListaElementos(v);
	system("cls");
	
	t0 = clock();
	int resultado = buscarBinaria(v, n, mascotaBuscar);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	
	if( resultado >= 0){
		cout << "Mascota encontrada con metodo de busqueda binaria!!" << endl;
		cout << "Ha tomado un tiempo de: " << time << " segundos."<< endl << endl;
		mascotaBuscar.mostrar();
	}else
		cout << "No se ha podido encontrar la mascota :( " << endl;
		
	system("pause");
}

int menu(){
	int opcion; 
	
	cout << "\t======Menu Principal======" << endl;
	cout << "1. Menu Mascota" << endl;
	cout << "2. Menu Usuario" << endl;
	cout << "3. Menu Adopcion" << endl;
	cout << "PROYECTO DE ORDENACION:" << endl;
	cout << "4. Mostrar el Archivo Binario de Mascotas" << endl;
	cout << "5. Mostrar el Vector de Mascotas" << endl;
	cout << "6. Ordenar por Mezcla Equilibrada" << endl;
	cout << "7. Ordenar por Mezcla Directa" << endl;
	cout << "8. Ordenar el Vector de Datos con el Metodo de Quicksort" << endl;
	cout << "9. Ordenar el Vector de Datos con el Metodo de Heapsort" << endl;
	cout << "10. Buscar Mascota (Metodo de Busqueda Binaria)" << endl;
	cout << "11. Salir" << endl;
	cout << endl << "Su opcion: ";
	cin >> opcion;
	
	return opcion;
}


void menuMascota(){
	int opcion; 
	bool band = false;
	
	while(true){
		cout << "\t======Menu Mascota======" << endl;
		cout << "1. Registro de Mascota" << endl;
		cout << "2. Consultar datos" << endl;
		cout << "3. Listado general de mascotas" << endl;
		cout << "4. Actualizacion de una mascota" << endl;
		cout << "5. Eliminacion de una mascota" << endl;
		cout << "6. Volver al menu principal" << endl;
		cout << endl << "Su opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertarMascota();
				break;
			case 2:
				consultarDatosMascota();
				break;
				
			case 3:
				listarMascotas();
				break;
				
			case 4:
				actualizarMascota();
				break;
				
			case 5: 
				eliminarMascota();
				break;
				
			case 6:
				band = true;
				break;	
				
			default: 
				cout << "opcion incorrecta.." << endl;
				system("pause");	
		}
		system("cls");
		if (band) break;
	}
}


void menuUsuario(){
	int opcion; 
	bool band = false;
	
	while(true){
		cout << "\t======Menu Usuario======" << endl;
		cout << "1. Registro de Usuario" << endl;
		cout << "2. Consultar datos" << endl;
		cout << "3. Listado general de personas" << endl;
		cout << "4. Actualizacion de un usuario" << endl;
		cout << "5. Eliminacion de un usuario" << endl;
		cout << "6. Reportar usuario como maltratador" << endl;
		cout << "7. Volver al menu principal" << endl;
		cout << endl << "Su opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertarUsuario();
				break;
			case 2:
				consultarDatosUsuario();
				break;
				
				
			case 3:
				listarUsuarios();
				break;
				
				
			case 4:
				actualizarUsuario();
				break;
				
			case 5: 
				eliminarUsuario();
				break;
				
			case 6:
				reportarUsuario();
				break;
				
			case 7:
				band = true;
				break;	
				
			default: 
				cout << "opcion incorrecta.." << endl;
				system("pause");	
		}
		system("cls");
		if (band) break;
	}
	
}


void menuAdopcion(){
	int opcion; 
	bool band = false;
	
	while(true){
		cout << "\t======Menu Adopcion======" << endl;
		cout << "1. Registro de Adopcion" << endl;
		cout << "2. Consultar de Adopcion por fecha" << endl;
		cout << "3. Listado general de Adopcion" << endl;
		cout << "4. Eliminacion de una Adopcion por su numero de registro" << endl;
		cout << "5. Lista negra" << endl;
		cout << "6. Volver al menu principal" << endl;
		cout << endl << "Su opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertarAdopcion();
				break;
			case 2:
				listarPorFecha();
				break;
				
			case 3:
				listarAdopciones();
				break;
				
			case 4:
				eliminarDeterminadoRegistro();
				break;
				
			case 5: 
				listaNegra();
				break;
				
			case 6:
				band = true;
				break;	
			
			default: 
				cout << "opcion incorrecta.." << endl;
				system("pause");	
		}
		system("cls");
		if (band) break;
	}
}

int main() {
	int opcion;
	bool band = false;
	
	while(true){
		opcion = menu();
		
		switch(opcion){
			case 1:
				menuMascota();
				break;
			case 2:
				menuUsuario();
				break;
			case 3:
				menuAdopcion();
				break;
				
			case 4:
				listarArchivosMascotas();
				break;
				
			case 5:
				listarVector();
				break;
				
			case 6:
				ordenarMezclaEquilibrada();
				break;
			
			case 7:
				ordenarMezclaDirecta();
				break;
				
			case 8:
				ordenarQuicksort();
				system("pause");
				break;
				
			case 9:
				ordenarHeapsort();
				break;
				
			case 10:
				buscarBinario();
				break;	
			
			case 11: 
				band = true;
				break;
				
			default: 
				cout << "opcion incorrecta.." << endl;
				system("pause");
		}
		system("cls");
		if (band) break;
		
	}

    system("pause");
    return EXIT_SUCCESS;
}