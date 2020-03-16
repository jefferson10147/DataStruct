#include <fstream>
#include <stdlib.h>

using namespace std;
template <class T>
class MezclaEquilibrada {
	private:
		char nombre[20];
		void abrir(fstream *f, char nom[], int tip=1)
		{
		    if(tip==1)
			(*f).open(nom, ios::in | ios::binary );
		    else if(tip==2)
			(*f).open(nom, ios::out | ios::app | ios::binary);
		    else
			(*f).open(nom, ios::out | ios::binary);
			}
			void cerrar(fstream *f)
			{
		    (*f).close();
		}
		void particionInicial()
		{
		    T aux, dato;
		    bool ban=true;
		    fstream F, F2, F3;
		    abrir(&F ,   nombre, 1);
		    abrir(&F2,(char*) "F2.dat", 3);
		    abrir(&F3, (char*)"F3.dat", 3);
		    F.seekg(0, ios::beg);
		    F.read((char*)&aux, sizeof(T));
		    
		    while(!F.eof() && !F.fail())
		    {
			F.read((char*)&dato, sizeof(dato));
			if(ban) {
			    F2.write((char*)&aux, sizeof(aux));
			    if(aux.get_clave (0) > dato.get_clave(0) )
				ban=false;
			} else {
			    F3.write((char*)&aux, sizeof(aux));
			    if(aux.get_clave (0) > dato.get_clave(0))
				ban=true;
			}
			aux=dato;
		    }
		    
		    cerrar(&F);
		    cerrar(&F2);
		    cerrar(&F3);
		}
	
		void particionFusion()
		{
		    fstream F1;
		    abrir(&F1, (char*)"F1.dat", 1);
		    bool bandera=true;
	
		     do {
			if(bandera) {
			    bandera=false;
			    intercalacionDeArchivo((char*)"F2.dat",(char*)"F3.dat",  nombre,(char*)"F1.dat");
			} else {
			    bandera=true;
			    intercalacionDeArchivo(nombre  ,(char*)"F1.dat",(char*)"F2.dat",(char*)"F3.dat");
			}
		    } while(!F1.eof());
		    cerrar(&F1);
		}
	
	       void intercalacionDeArchivo(char nom1[], char nom2[], char nom3[], char nom4[])
	       {
		    T    aux1,     aux2, dato ;
		    T    mayor1,   mayor2;
		    bool bandera1, bandera2=true;
		    fstream F1, F2, F3, F4;
		    abrir(&F1, nom1, 1);
		    abrir(&F2, nom2, 1);
		    abrir(&F3, nom3, 3);
		    abrir(&F4, nom4, 3);
		    F1.seekg(0, ios::beg);
		    F1.read((char*)&aux1, sizeof(T));
		    F2.seekg(0, ios::beg);
		    F2.read((char*)&aux2, sizeof(T));
		    mayor1=aux1;
		    mayor2=aux2;
		       
		    while(!F1.eof() && !F2.eof())
		    {
			if(aux2.get_clave(0) < mayor2.get_clave(0) && aux1.get_clave(0) < mayor1.get_clave(0))
			{
			    if(bandera2)
				bandera2=false;
			    else
				bandera2=true;
			    mayor1=aux1;
			    mayor2=aux2;
			}
			if((aux1.get_clave(0)  <= aux2.get_clave(0)  && aux1.get_clave(0)  >= mayor1.get_clave(0) ) || aux2.get_clave(0)  < mayor2.get_clave(0) )
			{
			    bandera1=true;
			    mayor1=dato=aux1;
			} else {
			    bandera1=false;
			    mayor2=dato=aux2;
			}
			if(bandera1)
			    F1.read((char*)&aux1, sizeof(T));
			else
			    F2.read((char*)&aux2, sizeof(T));
			if(bandera2)
			    F3.write((char*)&dato, sizeof(T));
			else
			    F4.write((char*)&dato, sizeof(T));
		    }
		    if(!F1.eof())
		    {
			while(!F1.eof())
			{
			    if(aux1.get_clave(0) < mayor1.get_clave(0))
			    {
				if(bandera2)
				    bandera2=false;
				else
				    bandera2=true;
			    }
			    mayor1=aux1;
			    if(bandera2)
				F3.write((char*)&aux1, sizeof(T));
			    else
				F4.write((char*)&aux1, sizeof(T));
			     F1.read((char*)&aux1, sizeof(T));
			}
		    } else if(!F2.eof()) {
			while(!F2.eof())
			{
			    if(aux2 < mayor2)
			    {
				if(bandera2)
				    bandera2=false;
				else
				    bandera2=true;
			    }
			    mayor2=aux2;
			    if(bandera2)
				F3.write((char*)&aux2, sizeof(T));
			    else
				F4.write((char*)&aux2, sizeof(T));
			    F2.read((char*)&aux2, sizeof(T));
			}
		    }
		    cerrar(&F1);
		    cerrar(&F2);
		    cerrar(&F3);
		    cerrar(&F4);
		}

	public:
		MezclaEquilibrada(char *n){ strcpy(nombre,n); }
		void ordenar()
		{
		    cout<<"ORDENANDO ARCHIVO "<<nombre<<endl;
		    particionInicial();
		    particionFusion();
		    cout<<"FINALIZACION DEL PROCESO DE ORDENAMIENTO"<<endl;
		}
};
