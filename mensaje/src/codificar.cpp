
/**
  * @file codificar.cpp
  * @brief Fichero con funciones para ocultar/extraer un mensaje en imagenes
  *
  * Permite la extracion ocultacion y extracción de un mensaje en imagenes de tipo PGM,PPM
  *
  */

#include <iostream>
#include <string>
#include <cstring>
#include "codificar.h"

using namespace std;
void imprimir( char m[])
{
	for (int i=0;m[i]!='\0';i++)
		cout <<m[i];
	cout<<endl;
}

bool cabe_mensaje(int tam,char mensaje[])
{
	int s=strlen(mensaje);
	return((s*8<tam)?1:0);
}

bool activo(int numero ,int nbit)
{
	return (numero&(1<<nbit)?1:0);
}
//___________________________________________________________________________________________
//
// 				Ocultar
//___________________________________________________________________________________________


bool ocultar( unsigned char buffer[],char mensaje[],int tam)
{
	int i=0;
	bool exito= false;

	int tamcadena=strlen(mensaje);
	if(tamcadena<=tam)
	{
		for(int j=0;j<=tamcadena;j++)
		{
			for(int k=7;k>=0;k--)//recorre los bits del caracter
			{
				if(activo(mensaje[j],k))
					buffer[i]= buffer[i]|1;
				else
					buffer[i]=buffer[i]&(~1);
				i++;
			}
			if(j==tamcadena)
			{
			 	exito= true;
			}
		}
	}else exito=false;
		return exito;
}
bool comparaTipo(char nombre[],char tipo[])
{
	bool ok=false;
	int c=strlen(nombre);
	int cont=0;
	int d=strlen(tipo);

		for(int i=c-1,j=d-1;i>=c-4;i--,j--)
			if(nombre[i]==tipo[j])
				cont++;
		if (cont==d)
			ok=true;
		return ok;
}
void lee_linea(char c[], int tamanio)
{
	do{
		cin.getline(c,tamanio);
	}while (c[0]=='\0');
}
//___________________________________________________________________________________________
//
//				Revelar
//___________________________________________________________________________________________

bool  revelar (unsigned char buffer[],char mensaje[],int tam)
{
	int cont=0,j=0;
	char c=' ';
	bool exito=false;
	cout<<"Revelando...."<<endl;
	for(int i=0;c!='\0';i++)
	{
	    c=0;
	    cont=0;
			for(int nbits=7;nbits>=0;nbits--)
			{
				if(activo(buffer[j],0))
				{
					c=c<<1;
					c=c|1;
				}else
					c=c<<1;

				if(cont==7)    mensaje[i]=c;

				if ((cont==7) && (c=='\0'))
				{					
				    mensaje[i]='\0';
				    exito=true;
				}
				if(j==tam && c!='\0') exito= false;

				cont++;
               	j++;
			}
	}
	return exito;
}

