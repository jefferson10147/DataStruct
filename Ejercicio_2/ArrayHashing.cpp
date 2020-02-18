#include "ArrayHashing.h"

#include <iostream>

template <class T>
ArrayHashing<T>::ArrayHashing (int size, T ini, int (*f)(T k)) //VectorHashing<T>::VectorHashing (int size, T vallib, int (*pf)(T k)) 
{
	tam = size;
	valini = ini;
	v = new T [tam];
	
	matrizCol = new T *[tam];//
	
	for (int i = 0; i < tam; i++)
	{
		v[i] = ini; //le da un valor inicial a todas la pos del vector
		
		matrizCol [i] = new T[1];//
		matrizCol[i][0] = valini;//
	}	
	hashClass = f;
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
		v[pos] = ele;  //significa que la pos está vacia 
 	else 
		resolverCol(ele);
 	
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
			return 1;
		}
 		i++;	
	}
	return 0;
}

template <class T>
int ArrayHashing <T> :: buscar (T &ele)
{
 	int r;
 	int pos = hash (ele);
 	
 	if (v[pos] == ele)
	{
 		ele = v[pos];
 		return 1;
	}
	
	if ( v[pos] == valini) 
		return 0;  
	else
		r=buscarCol(ele,pos);

	return r; 	 	
}
 
