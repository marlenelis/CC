/**
  * @autor Marlene V. 
  * @file componer.cpp
  * @brief Fichero que contiene la funcion que inicializa el programa de ejecución.
  *
  * Nos permite obtener una transformación composición a partir de otras dos existentes.
  */

#include<iostream>
#include <transformacion.h>
using namespace std;
int main(int argc, char* argv[])
{
    //componer t neg_y_mitad_txt.trf mitad_txt.trf negativo_bin.trf

    if(argc !=5)
    {
        cout <<"El número de parámetros es incorrecto"<<endl;
        cout <<"Uso: "<<endl;
        cout<< "\tcomponer tipo[t-b]  -archivo_Salida [Transformacion]  -archivo1[transformacion]  -archivo2[Transformacion]"<<endl;

        cout <<"\tcomponer t neg_y_mitad_txt.trf mitad_txt.trf negativo_bin.trf"<<endl;

    }
    else
    {
        Transformacion Tr1;
        char tipo= *argv[1];

        if(LeerTransformacion(argv[3],Tr1))
        {
            Transformacion Tr2;
            if(LeerTransformacion(argv[4],Tr2))
            {
                Transformacion Res;
                Res= Tr1+Tr2;

                if(Escribir_Transformacion(argv[2],Res,tipo))
                    cout<<"La composición se ha realizado con exito. "<<endl;
                else
                    cout<<"Error.. no se ha realizado la composición."<<endl;
            }
            else
                cout<<"Error en la lectura del archivo"<<argv[4]<<endl;
        }
        else
                cout<<"Error en lalectura del archivo"<<argv[3]<<endl;

    }
}
