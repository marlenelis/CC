/**
  * @autor Marlene V.
  * @file ocultar.cpp
  * @brief fichero que contiene la función que inicializa el programa de ejecución
  *
  * Permite la ocultación del mensaje en imagenes.

  */
#include <iostream>
#include <cstring>
#include "imagen.h"
#include "procesar.h"


using namespace std;

bool cabe_mensaje(int tam,char mensaje[])
{
	int s=strlen(mensaje);
	return((s*8<=tam)?0:1);
}
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        cout<<"Número de argumentos incorrecto."<<endl;
        cout<<"Uso:\nej:\t ocultar lenna.pgm salida.pgm < mensaje.txt"<<endl;
        return 1;
    }
    else
    {
        Imagen entrada;
        if( entrada.LeerImagen(argv[1]))
        {
            int TAM= entrada.Filas()*entrada.Columnas();
            char mensaje[TAM+1];
            int n,i=0;
            while((n=cin.get())!= EOF &&i<TAM)
            {
                mensaje[i]=n;
                i++;
            }

            mensaje[i]='\0';

            int tam_mensaje=tamanio(mensaje);

            if(cabe_mensaje(tam_mensaje,mensaje))
            {
                if(ocultar(entrada,mensaje))
                {
                    cout<<"Ocultando....."<<endl;
                    if( entrada.EscribirImagen(argv[2]))
                        return 0;
                    else
                        cout<<"La escritura de la imagen sin éxito."<<endl;
                }
                else
                    cout<<"La ocultación no tuvo éxito."<<endl;

            }
            else
                cout <<"El mensaje no cabe en la imagen"<<endl;

        }


   }

}
