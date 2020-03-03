#include <iostream>
using namespace std;
template <class T>
class ArrayHashing
{
	T *v; 
	T **matrizCol;
	int tam;
	int valini;
	int (*hash)(T clave);
	
	public: 
	
		ArrayHashing (){}
		ArrayHashing (int size, T ini, int (*f)(T k));
		int almacenar (T ele);
		int buscar (T &ele);
		void imprimir();
		void resolverCol (T ele, int pos);	
		int buscarCol(T &ele, int pos);
};
template <class T>
ArrayHashing<T>::ArrayHashing (int size, T ini, int (*f)(T k)) 
{
	tam = size;
	valini = ini;
	v = new T [tam];
	
	matrizCol = new T *[tam];
	
	for (int i = 0; i < tam; i++)
	{
		v[i] = ini; 
		
		matrizCol [i] = new T[1];
		matrizCol[i][0] = valini;
	}	
	hash = f;
} 
template <class T>
void ArrayHashing <T> :: resolverCol (T ele, int pos)
{
 	if (matrizCol[pos][0] == valini)
 	{
 		matrizCol[pos][0] = ele;
 		matrizCol[pos][1] = valini; 
	}else{
 		int cont = 0;
 		while(matrizCol[pos][cont] != valini)
 			cont++;
		
 		T *vAux = new T [cont];
 		
 		for (int i = 0; i < cont; i++)
 			vAux [i] = matrizCol[pos][i];
 		
 		matrizCol [pos] = new T [cont+2];
 	
 		for (int i = 0; i < cont; i++)
 			matrizCol[pos][i] = vAux[i];
 			
 		matrizCol[pos][cont] = ele;
 		matrizCol[pos][cont+1] = valini;
 		vAux = NULL;
	}	
}
template <class T>
int ArrayHashing <T> :: almacenar (T ele)
{
 	int pos = hash (ele);
 	
 	if (v[pos] == valini)
		v[pos] = ele;  
 	else 
		resolverCol(ele,pos);
 	
 	return 1;
}
template <class T>
int ArrayHashing<T> :: buscarCol (T &ele, int pos)
{
 	int i = 0;
 	while (matrizCol[pos][i] != valini)
	 {
 		if(matrizCol[pos][i] == ele)
 		{
 			ele = matrizCol[pos][i];
			return pos;
		}
 		i++;	
	}
	return -1;
}
template <class T>
int ArrayHashing <T> :: buscar (T &ele)
{
 	int r;
 	int pos = hash (ele);
 	if (v[pos] == ele)
	{
 		ele = v[pos];
 		return pos;
	}
	if ( v[pos] == valini) 
		return -1;  
	else
		r=buscarCol(ele,pos);

	return r; 	 	
}
template <class T>
void ArrayHashing<T> :: imprimir ()
{
	int j,cont = 0, cont2 = 0;
	bool band; 
	cout<<"    | Claves |->{ Zona de Colisiones }\n\n";
	for (int i = 0; i < tam; i++)
	{
		band = false;
		if(v[i] != valini)
		{
			cout<<"["<<i<<"]"<<": |"<<v[i]<<"|";
			band = true;
			cont2 ++;
		}
		j = 0;
		while (matrizCol[i][j] != valini)
		{
			cout<<"->{"<<matrizCol[i][j]<<"}";
			j++; cont++;
		}
		if(band)
			cout<<endl;
	}
	if (tam!=0)
	{
		float num = cont + 0.0;
		float resp = (num/(cont2+cont))*100;
		cout<<"El porcentaje de colisiones es de: "<<resp<<" %"<<endl;
	}
}
