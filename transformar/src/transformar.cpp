/**
  * @autor Marlene V.
  * @file transformar.cpp
  * @brief Fichero que inicializa el programa para  leer una imagen y una transformación
  * aplica la transformación leida y se obtiene una nueva imagen transformada.
  *
  * Permite transformaciones de imagenes.
  */

#include <iostream>
#include <cstdlib>
#include "imagen.h"
#include "transformacion.h"
#include "Transformaciones.h"
#include "procesar.h"

using namespace std;

int main(int argc,char *argv [])
{
    if(argc!=4)
    {
        cout<< "El número de argumentos es incorrecto." <<endl;
        cout<< "Uso: "<<endl;
        cout<< "\ttransformar  -archivo [imagen]  -archivo[transformacion]  -archivo Salida[imagen]"<<endl;
        cout<< "\tej: transformar lenna.pgm carboncillo_txt.trf lenna_carbon.pgm\n"<<endl;
        return 1;
    }
    else
    {
        Imagen entrada;

        if(entrada.LeerImagen(argv[1]))
        {
            Transformacion Tr;
            if(LeerTransformacion(argv[2],Tr))
            {
                if(transformar_Imagen(entrada,Tr))
                {
                    cout<<"Transformación realizada con exito."<<endl;

                    if(entrada.EscribirImagen(argv[3]))
                       return 0;
                    else
                        cout<< "Error en la escritura de la imagen."<<endl;
                }
                else
                    cout<<"Error en la transformación."<<endl;
            }
            else
                cout<<"Error en la lectura del archivo de transformación."<<endl;
        }
        else
            cout<<"Error en la lectura de la imagen."<<endl;
    }
}
