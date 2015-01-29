/**
  * @autor Marlene V.
  * @file generar.cpp
  * @brief Fichero que contiene la función que inicializa el programa de ejecución
  *
  * Permite generar archivos de transformaciones.
  */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Transformaciones.h"
#include "transformacion.h"

using namespace std;


void ayuda()
{
    cout<< "No ha ingresado ningún parámetro"<<endl;

    cout<< "Generación de Archivos de transformaciones : "<<endl;

    cout<<"\t- negativo\n\t- desplazar\n\t- umbralizar\n\t- brillo"<<endl;

    cout<<"Uso:"<<endl;

    cout<<"generacion de archivos  \n- t \t texto \n- b \t binario\n"<<endl;

    cout<< "negativo  ->\t generar tipo[t,b] nombre_archivo negativo "<<endl;
    cout<< "\t\t ej. generar t negativo_text.trf negativo \n"<<endl;

    cout<< "desplazar ->\t generar tipo[t,b] nombre_archivo desplazar  numero_bits[1...7]"<<endl;
    cout<< "\t\t ej. generar b desplazar_bin.trf desplazar 2 \n"<<endl;

    cout<< "umbralizar->\t generar tipo[t,b] nombre_archivo[*.trf] umbralizar  umbral[0...255]"<<endl;
    cout<< "\t\t ej. generar b mitad_bin.trf umbralizar 127\n"<<endl;

    cout<< "brillo   ->\t generar tipo[t,b] nombre_archivo[*.trf] brillo  brillo[(+-)0...255]"<<endl;
    cout<< "\t\t ej. generar t brillo10_text.trf brillo 10 \n"<<endl;

}
int main(int argc,char *argv[])
{

	if(argc==1 || argc>5){
		ayuda();
		return 1;
	}
    else
    {
        Transformacion nueva ;
        char tip_o= *argv[1];

            if(argc==4 && strcmp(argv[3],"negativo")==0)
            {
                nueva=negativo();

                if( Escribir_Transformacion(argv[2],nueva,tip_o))
                    cout<<"Generación del archivo con éxito."<<endl;
                else
                    cout <<"Error... no se puede generar el archivo."<<endl;
            }
            else
            if(argc==5)
            {
                if(strcmp( argv[3],"desplazar")==0)
                {
                    if(atoi(argv[4])>=0 && atoi(argv[4])<=7)
                    {
                        nueva= desplazar(atoi(argv[4]));
                        if( Escribir_Transformacion(argv[2],nueva,tip_o))
                            cout<<"Generación del archivo con éxito."<<endl;
                        else
                            cout <<"Error... no se puede generar el archivo."<<endl;
                    }
                    else
                    {
                        cout<<"El valor a desplazar no es válido. \nValores permitidos [0,1,2,3,4,5,6,7] "<<endl;
                        return 1;
                    }
                }

                if(strcmp( argv[3],"umbralizar")==0)
                {
                    nueva = umbralizar(atoi(argv[4]));
                    if( Escribir_Transformacion(argv[2],nueva,tip_o))
                        cout<<"Generación del archivo con éxito."<<endl;
                    else
                        cout <<"Error... no se puede generar el archivo."<<endl;
                }
                if(strcmp( argv[3],"brillo")==0)
                {
                    nueva = brillo(atoi(argv[4]));
                    if( Escribir_Transformacion(argv[2],nueva,tip_o))
                        cout<<"Generación del archivo con éxito."<<endl;
                    else
                        cout <<"Error... no se puede generar el archivo."<<endl;
                }
            }
            else
                ayuda();
    }

}
