/**
  * @autor Marlene V.
  * @file Transformaciones.cpp
  *
  * @brief Fichero que contine la implementación para inicializar las diferentes transformaciones
  * (negativo,desplazar,umbralizar, brillo).
  *
  */
#include "Transformaciones.h"
#include <iostream>

using namespace std;

/****************************OPERACIONES************************************/

Transformacion negativo ()
{
    Transformacion Tr;

    for(int i=0;i<256;i++)
         Tr.Set(i,255-i);
    return Tr;
}

Transformacion desplazar( int n)
{

    Transformacion Tr;
    for(int i=0;i<256 ;i++)
    {
        if(i<<n > 255)
            Tr.Set(i,255);
        else
            Tr.Set(i,i << n);
    }
    return Tr;
}

Transformacion umbralizar(int v)
{
    Transformacion Tr;
    for(int i=0;i<256;i++)
    {
        if(i<=v)
         Tr.Set(i,0);
        else
            Tr.Set(i,255);
    }
    return Tr;

}
Transformacion brillo(int d)
{
    Transformacion Tr;
    for(int i=0;i<256 ;i++)
    {

        if(i+d<0 || i+d>255)
        {
            if(i+d<0)
                Tr.Set(i,0);
            else
                Tr.Set(i,255);
        }
        else
        Tr.Set(i,i+d);
    }
    return Tr;

}

