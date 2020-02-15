#include <iostream>

using namespace std;

template <class t>
void mostrar(t *v, int size)
{
	for (int i = 0; i<size;i++)
   		cout<<v[i]<<" ";
}

template <class t>
void insertionSort (t *v,int size, int start, int final, bool right)
{										 
	t aux;								 
	int I,i;
	
	if (right)
	{
		for(i=(final+1); i<size;i++)
		{  
			I=i;
			aux=v[i];
			while(I>start && aux<v[I-1])
			{
				v[I]=v[I-1];
				I--;
			}
			v[I]=aux;
		}	
	}else{
		for(i=(start-1); i >= 0;i--)
		{ 
			I=i;
			aux=v[i];
			while(I<(size-1) && aux>v[I+1])
			{
				v[I]=v[I+1];
				I++;
			}
			v[I]=aux;
		}		
	}	
}

template <class t>
void lookForContinuosPos(t *v, int size, int sizeToSearch, int &start, int &final)
{
	int cont = 0;
	int actualPos, auxStart, auxFinal;
	for (int i = 0; i < size-1; i++)
	{
		actualPos = i;
		auxStart = i;
		cont = 1;
		while (v[actualPos]<v[actualPos+1] && actualPos != size -1)
		{
			actualPos++;
			cont++;		
		}
		auxFinal = actualPos;
		if (cont >= sizeToSearch && cont != size)
		{
			start = auxStart; 
			final = auxFinal;
			lookForContinuosPos (v,size,(sizeToSearch+1),start,final); 
			break;
		}
		/*if (cont == size) arreglo ordenado :D*/
	}	
}

int main ()
{
	int start = 0, final = 0;
	int v[ ] = {  6, 24, 12, 16, 20, 17, 10, 19};
	int size = sizeof(v)/sizeof(v[0]);
	lookForContinuosPos(v,size,2,start,final);
	insertionSort (v,size,start,final,true);
	insertionSort (v,size,start,final,false);
	mostrar (v,size);
	return 0;
}
