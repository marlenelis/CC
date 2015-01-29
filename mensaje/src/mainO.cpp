/**
  * @file mainO.cpp
  * @brief fichero main para la ocultación del mensaje
  *
  * Permite la ocultación del mensaje para archivos de tipo PGM,PPM
  */

#include <iostream>
#include <cstring>
#include <string>
#include "imagenES.h"
#include "codificar.h"


using namespace std;
int main()
{

	const int MAXBUFFER=1000000;
	const int MAXNOMBRE=100;
	char nombre_imagen_E[MAXNOMBRE];
	char nombre_imagen_S[MAXNOMBRE];

	char PPM[]={'.','p','p','m','\0'};
	char PGM[]={'.','p','g','m','\0'};
	unsigned char buffer[MAXBUFFER];
	char mensaje[1000];
	int filas=0,columnas=0;
	//0=desconocido; 1=PGM;2=PPM
	cout<< "Introduzca la imagen de entrada:"; cin >> nombre_imagen_E;

	TipoImagen tipoE = LeerTipoImagen(nombre_imagen_E, filas,columnas);
	
	if(tipoE==0)
		cout << "imagen Desconocida.";
	else
	if(tipoE==1)
	{
		if(LeerImagenPGM (nombre_imagen_E, filas,columnas,buffer))
		{			
			cout << "Introduzca la imagen de salida: "; cin >> nombre_imagen_S;			
				
			if(!comparaTipo(nombre_imagen_S,PGM))  strcat(nombre_imagen_S,PGM);//concatena con .ppm	
			cout << "Introduzca el mensaje: ";
			lee_linea(mensaje,1000);                                                 				
			if(ocultar(buffer,mensaje,filas*columnas))
			{
				cout<<"Ocultando";
				if(EscribirImagenPGM (nombre_imagen_S, buffer, filas, columnas))
					cout<< "..." << endl;
			}
			else cout << "no fue posible ocultar el mensaje" << endl;
		}
		else cout << "La imagen no puede ser procesada " << endl;
	}
	else
		if(tipoE==2)
		{
			if(LeerImagenPPM (nombre_imagen_E, filas,columnas,buffer))
			{				
				cout << "Introduzca la imagen de salida: "; cin >> nombre_imagen_S;			
				
				if(!comparaTipo(nombre_imagen_S,PPM))  strcat(nombre_imagen_S,PPM);//concatena con .ppm	
				cout << "Introduzca el mensaje: ";
				lee_linea(mensaje,1000);                                                 				
				if(ocultar(buffer,mensaje,filas*columnas))
				{
					cout<<"Ocultando";
					if(EscribirImagenPPM (nombre_imagen_S, buffer, filas, columnas))
						cout<< "..." << endl;
				}
				else
				cout << "no fue posible ocultar el mensaje" << endl;
			}
			else
			cout << "La imagen no puede ser procesada " << endl;
		}





}


