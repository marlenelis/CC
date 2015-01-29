/**
  * @file mainR.cpp
  * @brief fichero main para la extraccion del mensaje
  *
  * Permite la extraccion o revelacion de mensaje paraS archivos de tipo PGM,PPM
  *
  */

#include <iostream>
#include <string>
#include <cstring>
#include "codificar.h"
#include "imagenES.h"


using namespace std;
int main()
{

	const int MAXBUFFER=1000000;
	const int MAXNOMBRE=100;
	char nombre_imagen_E[MAXNOMBRE];
	unsigned char buffer[MAXBUFFER];
	char mensaje[MAXBUFFER];
	int filas=0;
	int columnas=0;
	//0=desconocido; 1=PGM;2=PPM
	cout<< "Introduzca la imagen de entrada:"; cin >> nombre_imagen_E;

	TipoImagen tipoE=LeerTipoImagen(nombre_imagen_E, filas,columnas);
	if(tipoE==0)
		cout << "imagen Desconocida.";
	else
	if(tipoE==1)
	{
		if(LeerImagenPGM (nombre_imagen_E, filas,columnas,buffer))
		{

			if(revelar(buffer,mensaje,filas*columnas-1))
			{
				cout<< "el mensaje obtenido es: "<<endl;
				imprimir(mensaje);
				
			}
		}
		else
			cout << "La imagen no puede ser procesada " << endl;
	}
	else
		if(tipoE==2)
		{
			if(LeerImagenPPM (nombre_imagen_E,filas,columnas, buffer))
			{
							if(revelar(buffer,mensaje,filas*columnas))
							{
								cout<< "el mensaje obtenido es: "<<endl;
								imprimir(mensaje);
							}
			}
			else
				cout << "La imagen no puede ser procesada " << endl;
		}




}


