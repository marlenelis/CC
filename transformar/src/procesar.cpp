/**
  * @autor Marlene V.
  * @file procesar.cpp
  * @brief Fichero con funciones para ocultar/extraer un mensaje en imagenes
  * y transformaciones de imagenes tipo PGM
  *
  */
#include <iostream>
#include <string>
#include <cstring>

#include "imagen.h"
#include "transformacion.h"
#include "Transformaciones.h"
#include "procesar.h"

using namespace std;

int tamanio(const char c[])
{
    int i=0;
    while(c[i]!='\0')
    i++;
    return i;
}
bool activo(int numero ,int nbit)
{
	return (numero&(1<<nbit)?1:0);
}
bool ocultar( Imagen& img ,char mensaje[])
{
	int z=0;
	bool exito= false;

	int tamcadena=strlen(mensaje);
	int F_las = img.Filas();
	int C_lumnas = img.Columnas();

    /*************************************************************/
	    unsigned char *vector;
	    vector=new unsigned char [F_las*C_lumnas];
	    for(int i=0;i<F_las;i++)
	        for(int j=0;j<C_lumnas;j++)
	        vector[i*C_lumnas+j]= img.Get(i,j);
    /**************************************************************/
		for(int j=0;j<=tamcadena;j++)
		{
			for(int k=7;k>=0;k--)//recorre los bits del caracter
			{
				if(activo(mensaje[j],k))
					vector[z]= vector[z]|1;
				else
					vector[z]=vector[z]&(~1);
				z++;
			}
			if(j==tamcadena)
			 	exito= true;
		}

    /**********************************************************/
        for(int i=0;i<F_las;i++)
            for(int j=0;j<C_lumnas;j++)
                img.Set(i,j,vector[i*C_lumnas+j]);

        delete[]vector;
	/**********************************************************/

		return exito;
}

bool  revelar (Imagen img,char mensaje[])
{
	int cont=0,j=0;
	int F_las = img.Filas();
	int C_lumnas = img.Columnas();

	char c=' ';
	bool exito=false;

/*****************************************************************************/
        unsigned char *vector;
        vector=new unsigned char [F_las*C_lumnas];
	    for(int i=0;i<F_las;i++)
	        for(int j=0;j<C_lumnas;j++)
                vector[j+i*C_lumnas]= img.Get(i,j);
/*****************************************************************************/
	for(int i=0;c!='\0';i++)
	{
	    c=0; cont=0;
			for(int nbits=7;nbits>=0;nbits--)
			{
                c=c<<1;
				if(activo(vector[j],0))		c=c|1;

				if(cont==7) mensaje[i]=c;

				if ((cont==7) && (c=='\0'))
				{
				    mensaje[i]='\0';
				    exito=true;
				}
				if(j==(F_las*C_lumnas) && c!='\0') exito= false;

				cont++;
               	j++;
			}
	}
/*****************************************************************************/
        for(int i=0;i<F_las;i++)
	        for(int j=0;j<C_lumnas;j++)
                img.Set(i,j,vector[j+i*C_lumnas]);
        delete []vector;
/*****************************************************************************/

	return exito;
}

/**************************TRANSFORMACIONES*******************************/
bool transformar_Imagen(Imagen& entrada,Transformacion Tr)
{
    bool exito=false;
    for(int i=0;i<entrada.Filas();++i)
        for(int j=0;j<entrada.Columnas();++j)
        {
            int n =entrada.Get(i,j);
            entrada.Set(i,j,Tr.Get(n));
            exito = true;
        }

    return exito;
}
