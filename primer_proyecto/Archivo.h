using namespace std; // Plantilla de mantenimiento de archivos binarios derivada de fstream
#include <iostream> // Proposito: Reusar el codigo fuente con distintos archivos en
#include <time.h>   //            procesos de rutina o manrenimiento
#include <conio.h>  // Author: David E. Ortiz Vezga
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

template <class T>
class TArchivo:public fstream
{
 private:
    T buf; // Registro o bloque de datos que almacena el archivo
    char nom[40]; // Nombre del archivo registrado en el almacenamiento secundario
 public:
    TArchivo(char *no="SinNombre.dat"){ strcpy(nom,no);}
    char *get_nomb() { return nom;}
    void reset()     { open(nom, ios::out | ios::binary ); close(); }
    int  insertar( T nue );
    int  listar();
    int  listarAptos();
    int  listarVarios(char *referencia);
    int  actualizar( T mod );
    int  buscar( T &bus);
    int  eliminar(T mod);
};

// Agrega un registro al final del archivo
template <class T>
int TArchivo<T>::insertar(T nue)
{
 open(nom, ios::out | ios::app | ios::binary );
 if ( fail() || bad() )
 return 0;
 write((char *)&nue, sizeof(nue));
 close();
 return 1;
}

// Busca un registro identificado por un campo clave en el archivo
template <class T>
int TArchivo<T>::buscar(T &bus)
{
 int enc, i;
 open(nom, ios::binary | ios::in);
 if ( fail() || bad() )
 return -2; // Valor de error abriendo el archivo
 enc=i=-1;
 while(enc==-1)
 {
         i++;
         read((char *)&buf, sizeof(buf));
         if (eof()) break;
         
         if (strcmp(buf.getRef(), bus.getRef()) == 0) {
            enc= i;
            bus= buf; // Copia todos los campos del registro localizado en el archivo en el parametro
         }           //  pasado por referencia
 }
 close();
 return enc; // Devuelve -1 si no lo encontro o el numero de registro o posicion relativa del reg
}

// Realiza un listado en pantalla con los datos almacenados en los registros
template <class T>
int TArchivo<T>::listar()
{
 open(nom, ios::binary | ios::in);
 int i=0;
 if ( fail() || bad() )
 return -2;
 // buf.hacer_encabezado();
 while(true)
 {
						read((char *)&buf, sizeof(buf));
 						if (eof()) break;
 						i++;
 						buf.mostrar();
 }
 close();
 return i;  //retorna la cantidad de datos guardados en el archivo
}

template <class T>
int TArchivo<T>::listarAptos()
{
 open(nom, ios::binary | ios::in);
 int i=0;
 if ( fail() || bad() )
 return -2;
 // buf.hacer_encabezado();
 while(true){
	read((char *)&buf, sizeof(buf));
 	if (eof()) break;
 	i++;
 	
 	if (buf.getBandera()) buf.mostrar();
 }
 close();
 return i;  //retorna la cantidad de datos guardados en el archivo
}

template <class T>
int TArchivo<T>::listarVarios(char *referencia)
{
 open(nom, ios::binary | ios::in);
 int i=0;
 if ( fail() || bad() )
 return -2;
 // buf.hacer_encabezado();
 while(true)
 {
	read((char *)&buf, sizeof(buf));
 	if (eof()) break;
 	i++;
 	if (strcmp(buf.getRef(), referencia) == 0) buf.mostrar();
 }
 close();
 return i;  //retorna la cantidad de datos guardados en el archivo
}

// Modifica un registro del archivo posicionando y sobreescribiendo.
template <class T>
int TArchivo<T>::actualizar(T mod)
{
 T aux=mod;
 int enc=buscar(aux);
 if ( enc>=0 )
 {
 open(nom, ios::binary | ios::in | ios::out);
 if ( fail() || bad() )
 return -2;
 seekg(enc*sizeof(mod), ios::beg);
 write((char *)&mod, sizeof(mod));
 close();
 }
 return enc;
}

// Elimina el registro deseado del archivo
template <class T>
int TArchivo<T>::eliminar(T mod){         
	int enc=buscar(mod);
	fstream aux;
	aux.open("temp.dat",ios::binary | ios::out);		
	if ( aux.fail() || aux.bad() )	return -2;
	if ( enc>=0 ){
		open(nom, ios::binary | ios::in);
		if ( fail() || bad() )	return -2;
		while(true){
								read((char *)&buf, sizeof(buf));
								if(eof()) break;
								if(strcmp(mod.getRef(), buf.getRef()) != 0){
							          aux.write((char *)&buf,sizeof(buf));		
								}
		}
		close();
		aux.close();
		remove(nom);
		rename("temp.dat",nom);
	}
	return enc;
}
