/**
  * @autor Marlene V.
  * @file revelar.cpp
  * @brief fichero que contiene la funcion que inicializa el programa de ejecución
  *
  * Permite la revelación del mensaje en imagenes.
  * @author Marlene E. Vásquez
  * @date Junio 2012
  */
#include <iostream>
#include "imagen.h"
#include "procesar.h"
void imprimir( char m[])
{
	for (int i=0;m[i]!='\0';i++)
		cout <<m[i];
	cout<<endl;
}

using namespace std;

int main(int argc,char *argv[])
{
    Imagen entrada;

    if(entrada.LeerImagen(argv[1]))
    {
        int Tam = entrada.Filas()*entrada.Columnas();
        char mensaje_S[Tam];

        if( revelar(entrada,mensaje_S))
        {
			cerr<<"Revelando...."<<endl;

            if(tamanio(mensaje_S)==0)
                cout<< "No existe mensaje oculto."<<endl;
            else
                imprimir(mensaje_S);
        }
        else
            cout<<"Se ha producido un error en la revelación del mensaje."<<endl;
    }


}
