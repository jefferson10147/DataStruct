#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "data.h"
#include "ArrayHashing.h"

using namespace std;

void searchForElement (ArrayHashing<int> obj)
{
	int x,pos;
	cout<<"-Ingrese la cedula a buscar: V-"; cin>>x;
	if ((pos=obj.buscar(x)) != -1)
		cout<<"\nSe ha encontrado la cedula "<<x<<" en la posicion ["<<pos<<"]"<<endl;
	else
		cout<<"\nNo se ha encontrado la cedula."<<endl;
}

void parsingData ()
{
	for (int i = 0; i<size; i++)
		dataInt[i] = atoi (strtok(dataString[i],"V"));
}

int hashFolding (int key)
{
	int *vNumbs = new int [30];
	vNumbs[0] = key%10;
	int i = 1;
	while ((key/10)!= 0)
	{
		key = key / 10;
		vNumbs[i] = key %10;
		i++;
	}
	int n = ceil (i/2);	
	int *vAux = new int [n];
	int  j, k,sum;
	char stringAux1[1]; 
	char buffer[30];
	do{
		if(i%2 != 0)
		{
			vAux [0] = vNumbs [0];
			j = 1; k = 1;	
		}else{
			j = 0; k = 0;
		}
		
		for ( ; j < i; j+=2)
		{
			sum = vNumbs[j] + vNumbs[j+1];
			if(sum>=10)
				sum = sum % 10;
			
			vAux[k] = sum; 
			k++; 	
		}
		if (i/2 == 1 && i != 3 )
		{
			itoa(vNumbs[1],buffer,10);
			strcpy(stringAux1,buffer);
			itoa (vNumbs[0],buffer,10);
			strcat(stringAux1,buffer);
			break;
		}else{
			vNumbs = vAux;
			
			if(i%2==0)
				i = ceil(i/2);	
			else
				i = ceil(i/2) + 1;
	
			vAux = new int [i/2];			
		}	
	}while(true);
	
	return atoi(stringAux1);
}

int main(int argc, char** argv)
{
	ArrayHashing<int> obj(100,-1,hashFolding); 
	parsingData();
	for(int i = 0; i < size; i++)
		obj.almacenar(dataInt[i]);
	
	int option = 0;	
	while (option != 3)
	{
		cout<<"\t--------MENU--------"<<endl;
		cout<<"1) Imprimir el vector de claves y la zona de colisiones."<<endl;
		cout<<"2) Buscar una clave."<<endl;
		cout<<"3) Salir."<<endl;
		cout<<"\nOpcion:";cin>>option;
		system("cls");
		switch (option)
		{
			case 1: obj.imprimir(); break;
			case 2: searchForElement(obj); break;
			case 3: option = 3; break;
			default : cout<<" Opcion incorrecta.";
		}
		cout<<endl;
		system("pause"); system ("cls");
	}
	return 0;
}

