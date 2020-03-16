#include <math.h>
#include "Archivo.h"
#include "ordenamiento.h"
#include "MezclaDirecta.h"
#include "MezclaEquilibrada.h"

class Alumno
{
      int ced;
      char nom[30];
      bool retiroMateria;
  public:
      Alumno()                 { ced=0;                }
      Alumno( char *n, int c ) { ced=c; strcpy(nom,n); retiroMateria = true;}
      int  get_clave(int flag) { return ced;           }
      char *get_nom()          { return nom;           }
      void set_nom(char *n)    { strcpy(nom,n);        }
      void set_retiroMateria (bool band){ retiroMateria = band;}
      bool get_retiroMateria (){ return retiroMateria;  }
      void set_ced(int n)      { ced= n;               }
      void setValue(int n)      { ced= n;               }
	  void imprime()     { cout<<ced<<"  "<<nom<<endl; }
      void cargarAlumno ()
      {
        cout<<"\n ...INGRESANDO DATOS ..."<<endl;
        cout<<"Ingrese el nombre del alumno: "; cin.sync(); cin.getline (nom,30,'\n');
        cout<<"Ingrese la cedula del alumno: "; cin>>ced;
      }
      bool operator < (Alumno &obj)
      { return ced < obj.get_clave(0);}
      bool operator <= (Alumno &obj)
      { return ced <= obj.get_clave(0);}
      bool operator > (Alumno &obj)
      { return ced > obj.get_clave(0);}
      bool operator >= (Alumno &obj)
      { return ced >= obj.get_clave(0);}
      bool operator == (Alumno &obj)
      { return ced == obj.get_clave(0);}
      friend ostream & operator<<(  ostream &os, Alumno  c )
      { 
          os<<c.ced<<"  "<<c.nom<<endl; 
          return os;
       } 
};

class Materia
{
      int cod;
      char tit[80], uc;
  public:
      Materia( char *n, int c, char v ) { cod=c; strcpy(tit,n); uc=v;  }
      Materia()                { cod=0;                }
      int  get_clave(int flag) { return cod;           }
      char get_uc()            { return uc;            }
      char *get_tit()          { return tit;           }
      void set_tit(char *n)    { strcpy(tit,n);        }
      void set_cod(int n)      { cod= n;               }
      void setValue(int n)     { cod= n;               }
      void set_uc( char v )    { uc=v;                 }
      void imprime()           { cout<<cod<<"  "<<tit<<"  "<<uc<<endl;}
      void cargarMateria ()
      {
        cout<<"\n ...INGRESANDO DATOS ..."<<endl;
        cout<<"Ingrese el nombre de la materia: "; cin.sync(); cin.getline(tit,80);
        cout<<"Ingrese el numero de unidades de la materia: "; cin>>uc;
        cout<<"Ingrese el cod de la materia: "; cin>>cod;
      }
      
      bool operator < (Materia &obj)
      { return cod < obj.get_clave(0);}
      bool operator <= (Materia &obj)
      { return cod <= obj.get_clave(0);}
      bool operator > (Materia &obj)
      { return cod > obj.get_clave(0);}
      bool operator >= (Materia &obj)
      { return cod >= obj.get_clave(0);}
      bool operator == (Materia &obj)
      { return cod == obj.get_clave(0);}
      friend ostream & operator<<(  ostream &os, Materia  m )
      { 
          os<<m.cod<<"  "<<m.tit<<" "<<m.uc<<endl; 
          return os;
       } 
};

class Semestre
{
      int cod;
      int ced;
  public:
      Semestre ( int v1, int v2 ) { cod=v1; ced=v2; }
      Semestre ( )                {                 }
      void set_cod(int c)         {     cod = c;    }
      void set_ced(int c)         {     ced = c;    }
      int  get_clave(int flag)  {  if ( flag==0 ) return cod;
                                   else           return ced;}
      void setValue(int n)        {      cod= n;    }
      void imprime()  { cout<<cod<<"  "<<ced<<endl; }
      void cargar ()
      {
        cout<<"\n ...INGRESANDO DATOS ..."<<endl;
        cout<<"Ingrese el codigo de la materia: "; cin>>cod;
        cout<<"Ingrese la cedula del alumno: "; cin>>ced;
      }
      
      bool operator < (Semestre &obj)
      { return cod < obj.get_clave(0);}
      bool operator <= (Semestre &obj)
      { return cod <= obj.get_clave(0);}
      bool operator > (Semestre &obj)
      { return cod > obj.get_clave(0);}
      bool operator >= (Semestre &obj)
      { return cod >= obj.get_clave(0);}
      bool operator == (Semestre &obj)
      { return cod == obj.get_clave(0);}
      friend ostream & operator<<(  ostream &os, Semestre  s )
      { 
          os<<s.cod<<"  "<<s.ced<<endl; 
          return os;
       }
};

Archivo<Alumno>  objalu((char*)"Datos.dat");
Archivo<Materia> objmat((char*)"Materia.dat");
Archivo<Semestre>objsem((char*)"Inscritos.dat");

void agregarMateria ()
{
    Materia objAux;
    objAux.cargarMateria();
    objmat.Abrir(ios::app | ios::binary);
    objmat.Limpiar();
    objmat.Escribir(objAux);
    objmat.Cerrar();
    system("pause");
}

void agregarAlumno ()
{
    Alumno objAux;
    objAux.cargarAlumno();
    objalu.Abrir(ios::app | ios::binary);
    objmat.Limpiar();
    objalu.Escribir(objAux);
    objalu.Cerrar();
    system("pause");
}

bool consultaDatosAlumno (int cedula, bool flag = false)
{
    int pos = 0;
    Alumno objAux ((char*)" ",cedula);
    objalu.Abrir(ios::in | ios::binary);
    if (objalu.Buscar_Sec(objAux,pos))
    {
        if(flag)
        {
	   cout<<objAux;
	   system("pause");	
         }
        return true;
    }else
        return false;

    objalu.Cerrar();
}

bool consultaDatosMateria (int cod, bool flag = false)
{
    int p = 0;
    Materia objAux ((char*)" ",cod,' ');
    objmat.Abrir(ios::in | ios::binary);
    if (objmat.Buscar_Sec(objAux,p))
    {
        if (flag)
	{
	   cout<<objAux;
	   system("pause");	
	}
        return true;
    }else
        return false;

    objmat.Cerrar();
}

void realizarInscripcion ()
{
    int ced, cod, pos = 0;
    char resp;
    cout<<"Ingrese la cedula del alumno que desar inscribir: "; cin>>ced;
    if(consultaDatosAlumno(ced))
    {
        while (true)
        {
            cout<<"Ingrese el codigo de la materia que desea inscribir: "; cin>>cod;
            if(consultaDatosMateria(cod))
            {
                Semestre objAux (cod,ced);
                objsem.Abrir(ios::app | ios::binary);
                objsem.Escribir(objAux);
                objsem.Ordenar(1);
                objsem.Cerrar();
            }else
                cout<<"\n\nMateria no encontrada"<<endl;

            cout<<"\nDesea intentar inscribir otra materia para el mismo alumno s/n: "; cin>>resp;
            if(resp == 'n' || resp == 'N')
                break;
        }
    }else
        cout<<"\nAlumno no encontrado."<<endl;
    system("pause");
}

void consultarInscripcion ()
{
    int cedula, pos2, pos = 0, acum = 0;
    cout<<"\nIngrese la cedula del alumno que desea consultar: "; cin>>cedula;
    if (consultaDatosAlumno(cedula,true))
    {
        Semestre objAux;
        objAux.set_ced(cedula);
        objsem.Abrir(ios::in | ios::binary);
        objmat.Abrir(ios::in | ios::binary);
        while (objsem.Buscar_Sec(objAux,pos,1))
        {
            Materia objAux2 ((char*)" ",objAux.get_clave(0),' ');
            pos2 = 0;
            if(objmat.Buscar_Sec(objAux2,pos2))
            {
                objAux2.imprime();
                acum += (int) (objAux2.get_uc() - '0');
            }
            pos++;
        }
        cout<<"\nTotal de Unidades de Creditos inscritas: "<<acum<<endl;
    }else
        cout<<"\nAlumno no encontrado"<<endl;
    objmat.Cerrar();
    objsem.Cerrar();
    system("pause");
}

void generarListadoSemestre ()
{
    int codAux, cedAux, j, posIni, posIni2;
    Alumno objAuxAlu;
    Materia objAuxMateria;
    Semestre objAuxSemestre;
    fstream archivoSemestre;
    archivoSemestre.open ("ListadoDelLapso2019-2.txt", ios :: out);
    if(archivoSemestre.is_open ())
    {
        objsem.Abrir(ios::in | ios::binary);
        objmat.Abrir(ios::in | ios::binary);
        objalu.Abrir(ios::in | ios::binary);
        Alumno *vInfoAlumnos = new Alumno [objsem.getN()];
        Materia *vInfoMateria = objmat.ExtraerInformacion();
        for (int i = 0; i < objmat.getN(); i++)
        {
            archivoSemestre<<"---> Materia: ";
            archivoSemestre<<vInfoMateria[i].get_clave(0)<<" ";
            archivoSemestre<<vInfoMateria[i].get_tit()<<" ";
            archivoSemestre<<vInfoMateria[i].get_uc()<<endl;
            objAuxSemestre.set_cod(vInfoMateria[i].get_clave(0));
            posIni = 0; j = 0;
            while (objsem.Buscar_Sec(objAuxSemestre,posIni))
            {
                vInfoAlumnos[j].set_ced(objAuxSemestre.get_clave(1));
                posIni++; j++;
            }
            shakerSort(vInfoAlumnos,j);
            posIni2 = 0;
            archivoSemestre<<"---> Alumnos inscritos en la materia:\n";
            for (int z = 0; z < j; z++)
            {
                if(objalu.Buscar_Sec(vInfoAlumnos[z],posIni2))
                {
                    archivoSemestre<<"\t";
                    archivoSemestre<<vInfoAlumnos[z].get_nom()<<" ";
                    archivoSemestre<<vInfoAlumnos[z].get_clave(0)<<endl;
                }
            }
            archivoSemestre<<"\n\n";
        }
        objalu.Cerrar();
        objmat.Cerrar();
        objsem.Cerrar();
        archivoSemestre.close();
        cout<<"\nListado generado con exito, por favor revisar el archivo 'listadoDelLapso2019-2.txt'"<<endl;
    }else
        cout<<"\nNo se ha podido generar el listado."<<endl;
        
    system("pause");
}

void consultarArchivo(int o)
{
	cout<<endl<<endl;
	switch (o)
	{
		case 1: objalu.Abrir (ios::in | ios::binary);
			objalu.Imprimir();
			objalu.Cerrar();
			break;
		case 2: objmat.Abrir (ios::in | ios::binary);
			objmat.Imprimir();
			objmat.Cerrar();
			break;
		case 3: objsem.Abrir (ios::in | ios::binary);
			objsem.Imprimir();
			objsem.Cerrar();
			break;
	}
	system("pause");
}

void ordenarMezclaDirecta (int o)
{
	int n;
	bool band = false;
	MezclaDirecta<Alumno> objOrdenarAlumnos((char*)"Datos.dat");
	MezclaDirecta<Materia> objOrdenarMaterias ((char *)"Materia.dat");
	MezclaDirecta<Semestre> objOrdenarSemestre ((char*)"Inscritos.dat");
	switch (o)
	{
		case 1: 
    			objalu.Abrir(ios::in | ios::binary);
    			n = objalu.getN();
    			objalu.Cerrar();
    			objOrdenarAlumnos.Ordenar(n);
			band = true;
			break;
		case 2: 
			objmat.Abrir(ios::in | ios::binary);
			n = objmat.getN();
			objmat.Cerrar();
			objOrdenarMaterias.Ordenar(n);
			band = true;
			break;
		case 3: 
			objsem.Abrir(ios::in | ios::binary);
			n = objsem.getN();
			objsem.Cerrar();
			objOrdenarSemestre.Ordenar(n);
			band = true;
			break;
	}
	if (band)
		cout<<"Ordenamiento de Archivos realizado con exito."<<endl;
	else
		cout<<"Ocurrio un error en el ordenamiento."<<endl;
		
	system("pause");
}

void ordenarMezclaEquilibrada (int o)
{
	MezclaEquilibrada<Alumno> objOrdenarAlumno((char *)"Datos.dat");
	MezclaEquilibrada<Materia> objOrdenarMateria ((char*)"Materia.dat");
	MezclaEquilibrada<Semestre> objOrdenarSemestre ((char*)"Inscritos.dat");
	bool band = false;
	switch(o)
	{
		case 1: 
			objOrdenarAlumno.ordenar();
			rename("Datos.dat",(char*)"ArchivoViejo.dat");
			remove((char*)"ArchivoViejo.dat");
			rename((char*)"F2.dat","Datos.dat");
			band = true;
			break;
		case 2: 
			objOrdenarMateria.ordenar();
			rename("Materia.dat",(char*)"ArchivoViejo.dat");
			remove((char*)"ArchivoViejo.dat");
			rename((char*)"F2.dat","Materia.dat");
			band = true;
			break;
		case 3: 
			objOrdenarSemestre.ordenar();
			rename("Inscritos.dat",(char*)"ArchivoViejo.dat");
			remove((char*)"ArchivoViejo.dat");
			rename((char*)"F2.dat","Inscritos.dat");
			band = true;
			break;	
	}
	
	if (band)
		cout<<"Ordenamiento de Archivos realizado con exito."<<endl;
	else
		cout<<"Ocurrio un error en el ordenamiento."<<endl;
		
	system("pause");
}

void retirarMateria()
{
	int cedula, pos2, pos = 0, acum = 0;
	cout<<"\nIngrese la cedula del alumno al cual desea retirar la materia: ";
	cin>>cedula;
	if (consultaDatosAlumno(cedula,true))
	{
		Semestre objAux;
        objAux.set_ced(cedula);
        objsem.Abrir(ios::in | ios::binary);
        objmat.Abrir(ios::in | ios::binary);
        while (objsem.Buscar_Sec(objAux,pos,1))
        {
            Materia objAux2 ((char*)" ",objAux.get_clave(0),' ');
            pos2 = 0;
            if(objmat.Buscar_Sec(objAux2,pos2))
            {
                objAux2.imprime();
                acum += (int) (objAux2.get_uc() - '0');
            }
            pos++;
        }
        cout<<"\nTotal de Unidades de Creditos inscritas: "<<acum<<endl<<endl;
        
	fstream archivoAlumnosConRetiro;
	int cedulaRetiro;
	bool banderaCedula = false;
	archivoAlumnosConRetiro.open((char *)"AlumnosConRetiro.txt", ios::in);    
	do
	{
	     archivoAlumnosConRetiro>>cedulaRetiro;
	     if(cedulaRetiro == cedula)
	     {
	    	banderaCedula = true;
	    	break;
             }
            if(archivoAlumnosConRetiro.eof()) break;
	}while (true);
	archivoAlumnosConRetiro.close();		
	int materiaRetirar;
	if(!banderaCedula)
	{
 	      cout<<"\nIngrese el codigo de la materia que desea retirar:";
              cin>>materiaRetirar;
              int posInicialMateria = 0;
              Materia objMateriaRetirar ((char *)" ",materiaRetirar,(char)' ');
              objmat.Buscar_Sec(objMateriaRetirar,posInicialMateria);
              int resta = acum - (int)(objMateriaRetirar.get_uc()-'0');
              if(resta >= 4)
	      {
        	  Semestre objsemRetirar (materiaRetirar,cedula);
	          Semestre objsemEscribir;		
	          Archivo<Semestre> objsemAuxiliar((char*)"InscritosNuevo.dat");
	          objsemAuxiliar.Abrir(ios::out | ios::binary);
	       	  int posInicial = 0;
	          objsem.Limpiar();
	          objsem.Posicionar(posInicial);
	          while (true)
	          {
	        	objsem.Leer(objsemEscribir);
	         	if(objsem.EsFin()) break;
			if(objsemRetirar.get_clave(0) == objsemEscribir.get_clave(0) && objsemRetirar.get_clave(1) == objsemEscribir.get_clave(1))
	       		    continue;
	        	else
	        	    objsemAuxiliar.Escribir(objsemEscribir);
		   }
		   objsem.Cerrar();
		   objsemAuxiliar.Cerrar();
		   remove("Inscritos.dat");
		   rename("InscritosNuevo.dat","Inscritos.dat");
		   archivoAlumnosConRetiro.open((char*)"AlumnosConRetiro.txt",ios::app);
	           archivoAlumnosConRetiro<<cedula<<endl;
		   archivoAlumnosConRetiro.close();	
		}else
	        {
		   cout<<"\nNo puede retirar materias porque queda con baja carga."<<endl;
		   objsem.Cerrar ();
		}	
	}else
			cout<<"Este alumno ya realizo un retiro, no puede hacer mas."<<endl;
			
		objalu.Cerrar();
		objmat.Cerrar();
	}else
	    cout<<"No se ha encontrado el alumno en el archivo."<<endl;	
	system("pause");
}

int menu ()
{
	system("cls");
    int opcion;
    cout<<"--------------------------------------"<<endl;
    cout<<"\t\tMenu"<<endl;
    cout<<"1.Agregar."<<endl;
    cout<<"2.Realizar inscripcion."<<endl;
    cout<<"3.Consultar datos."<<endl;
    cout<<"4.Consultar inscripcion."<<endl;
    cout<<"5.Generar listado de inscritos en el semestre."<<endl;
    cout<<"6.Consultar datos en archivos."<<endl;
    cout<<"7.Ordenar archivos con mezcla directa."<<endl;
    cout<<"8.Ordenar archivos con mezcla equilibrada."<<endl;
    cout<<"9.Realizar retiro de materia."<<endl;
    cout<<"10.Salir.\n"<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    return opcion;
}

int main(int argc, char *argv[])
{
    int opcion, opcion2, aux;
    while ((opcion = menu() )!= 10)
    {	
    	system("cls");
        switch(opcion)
        {
            case 1: cout<<"1. Agregar alumno."<<endl;
                    cout<<"2. Agregar materia."<<endl;
                    cout<<"Opcion: ";
                    cin>>opcion2;
                    if(opcion2 == 1)
                        agregarAlumno();
                    else if (opcion2 == 2)
                        agregarMateria();
                    else
                        cout<<"Opcion incorrecta."<<endl;
                        
                        cout<<"ARCHIVO DE MATERIAS "<<endl;
                        objmat.Abrir (ios::in | ios:: binary);
                        objmat.Imprimir ();
                        objmat.Cerrar();
						
						cout<<"ARCHIVO DE ALUMNOS "<<endl;
                        objalu.Abrir (ios::in | ios:: binary);
                        objalu.Imprimir ();
                        objalu.Cerrar();
                    break;
            case 2: realizarInscripcion();
                    break;
            case 3: cout<<"1. Consultar datos de alumno."<<endl;
                    cout<<"2. Consultar datos de materia."<<endl;
                    cout<<"Opcion: ";
                    cin>>opcion2;
                    if(opcion2 == 1)
                    {
                        cout<<"Por favor ingrese la cedula a consultar: "; cin>>aux;
                        consultaDatosAlumno(aux, true);
                    }else if (opcion2 == 2){
                        cout<<"Por favor ingrese el codigo de la materia a consultar: "; cin>>aux;
                        consultaDatosMateria(aux,true);
                    }else
                        cout<<"Opcion incorrecta."<<endl;

                    break;
            case 4: consultarInscripcion();
                    break;
            case 5: generarListadoSemestre();
                    break;
            case 6: cout<<"1. Datos.dat"<<endl;
					cout<<"2. Materias.dat"<<endl;
					cout<<"3. Semestre.dat"<<endl;
					cout<<"Opcion: ";
					cin>>opcion2;
					consultarArchivo(opcion2);
					break;
            case 7: cout<<"ORDENAMIENTO POR MEZCLA DIRECTA"<<endl;
					cout<<"1. Ordenar archivo de alumnos."<<endl;
            		cout<<"2. Ordenar archivo de materias."<<endl;
            		cout<<"3. Ordenar archivo de semestre."<<endl;
					cout<<"Opcion: ";
					cin>>opcion2;
					ordenarMezclaDirecta(opcion2);			
			break;
			case 8:
				   cout<<"ORDENAMIENDO POR MEZCLA EQUILIBRADA"<<endl;
				   cout<<"1. Ordenar archivo de alumnos."<<endl;
            	   cout<<"2. Ordenar archivo de materias."<<endl;
            	   cout<<"3. Ordenar archivo de semestre."<<endl;
				   cout<<"Opcion: ";
				   cin>>opcion2;
				   ordenarMezclaEquilibrada(opcion2);
			break;
			case 9: retirarMateria();
					break;
			case 10: break;
			default: cout<<"Opcion incorrecta."<<endl;
        }

    }
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
