#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

template <class T>
class Archivo
{
      fstream pf;
      char nom[40];
      T buffer;
      int lon, N;
  public:
  	Archivo () { }
      Archivo(char *n)          { strcpy(nom,n);                 }
      void Abrir( const std::_Ios_Openmode &t )
                                { pf.open(nom,t); Longi();       }
      void Longi( )             { lon= sizeof(T);                }
      void Leer    ( T &b )     { pf.read ((char*)&b,sizeof(T)); }
      void Escribir( T &b )     { pf.write((char*)&b,sizeof(T)); }
      void Cerrar()             { pf.close();                    }
      bool EsFin()              { return pf.eof();               }
      bool Falla()              { return pf.fail();              }
      void Limpiar()            { pf.clear();                    }
      void Posicionar( int p )  { pf.seekg(p*lon, ios::beg );    }
	  void Tamano();
      void Imprimir();
      T *ExtraerInformacion ();
      int getN (){Tamano(); return N;}
      void Ordenar( int flag=0 );
      bool Buscar_Sec     ( T &bus, int &pos, int flag=0, int Max=999999 );
      bool Buscar_Binario ( T &bus, int flag=0 );
};

template <class T>
void Archivo<T>::Tamano()
{
     Longi();
     pf.seekg(0,ios::end);
     pf.clear();
     N= pf.tellg()/lon;
}

template <class T>
void Archivo<T>::Imprimir()
{
    Limpiar();
    Posicionar(0);
    while ( true )
    {
      Leer(buffer);
      if ( EsFin() ) break;
      cout<<buffer; 
    }
    cout<<endl;
}

template <class T>
T* Archivo<T>::ExtraerInformacion ()
{
    Tamano();
    T *v = new T [N];
    int i = 0;
    Limpiar ();
    Posicionar(0);
    while (true)
    {
        Leer (v[i]);
        i++;
        if (EsFin()) break;
    }
    return v;
}

template <class T>
bool Archivo<T>::Buscar_Sec( T &bus, int &pos, int flag, int Max )
{
     int i=pos;
     bool enc=false;
     Limpiar();
     Posicionar(pos);
     while ( i<=Max && !enc )
     {
       Leer(buffer);
       if ( EsFin() ) break;
       if ( bus.get_clave(flag)==buffer.get_clave(flag) )
       {
           enc=true;
           bus= buffer;
           pos= i;
       }
	   else i++;
     }
     return enc;
}

template <class T>
bool Archivo<T>::Buscar_Binario( T &bus, int flag  )
{
     bool enc=false;
     int li=0, ls=N-1, pm;
     Limpiar();
     while ( !enc && li<=ls )
     {
           pm= (li+ls)/2;
           Posicionar(pm);
           Leer(buffer);
           if ( bus.get_clave(flag)==buffer.get_clave(flag) )
           {
                enc=true;
                bus=buffer;
           }
           else if ( bus.get_clave(flag)< buffer.get_clave(flag) )
                ls= pm-1;
           else
                li= pm+1;
     }
     return enc;
}

template <class T>
void Archivo<T>::Ordenar( int flag )
{
     T aux, ini;
     int i, j, pmen;
     Tamano();
     for ( i=0; i<N-1; i++ )
     {
        Posicionar(i);
        Leer (aux); ini= aux;
        pmen=i;
        for (j=i+1; j<N; j++)
        {
            Posicionar(j);
            Leer(buffer);
            if ( buffer.get_clave(flag)< aux.get_clave(flag) )
            {
                 aux= buffer;
                 pmen= j;
            }
        }
        if ( i!=pmen )
        {
             Posicionar(i);
             Escribir(aux);
             Posicionar(pmen);
             Escribir(ini);
        }
     }
}
