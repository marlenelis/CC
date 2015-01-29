/**
 * @autor Marlene V.
 * @file imagen.cpp
 *
 * @brief  Fichero que contiene las definiciones  para la nueva representación.
 *
 * Este tipo de dato se creará en memoria dinámica, para permitir procesar imágenes de
 * cualquier tamaño.
 *
 * Representación en base a dos enteros (filas y columnas) más un vector -en memoria
 * dinámica- de punteros a las filas. El primer puntero apunta a un vector con todos los
 * elementos de la imagen consecutivos por filas. El resto de punteros apunta al comienzo
 * de cada fila
 *
 **/
#include <iostream>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

//Para no olvidarme del examen ;( imagen3.cpp

Imagen::Imagen()//constructor por defecto
{
    //ctor
    filas=0;
    columnas=0;
    unsigned char **dat;
    dat=new unsigned char *[filas];
    dat[0]= new unsigned char [filas*columnas];

    for(int i=1; i<filas; i++)
        dat[i]= dat[i-1]+columnas;

    buffer=dat;
}

Imagen::Imagen(int f,int c) //constructor con parámetros
{
    filas=f;
    columnas=c;

    unsigned char **dat;
    dat=new unsigned char *[filas];
    dat[0]= new unsigned char [filas*columnas];

    for(int i=1; i<filas; i++)
        dat[i]= dat[i-1]+columnas;
    buffer=dat;
}

Imagen::~Imagen()//destructor
{
    if(filas>0&&columnas>0)
    {
        delete [] buffer[0];
        delete [] buffer;
    }
}
int Imagen::Filas ()const
{
    return filas;
}
int Imagen::Columnas()const
{
    return columnas;
}
void Imagen::Set (int i, int j, unsigned char val)
{
    buffer[i][j]=val;
}
unsigned char Imagen::Get(int i, int j)const
{
    return buffer[i][j];
}

Imagen::Imagen(const Imagen& orig)//Constructor de copias
{
        filas=orig.filas;
        columnas = orig.columnas;

        if(filas>0 && columnas>0)
        {
           unsigned char **dat;
            dat=new unsigned char *[filas];
            dat[0]= new unsigned char [filas*columnas];

            for(int i=1; i<filas; i++)
                dat[i]= dat[i-1]+columnas;

            buffer=dat;

            for(int i=0; i<filas; i++)
            for(int j=0; j<columnas; j++)
                buffer[i][j]= orig.buffer[i][j];
        }


}

Imagen& Imagen::operator=(const Imagen& orig)//Asignación
{
    if(this!=&orig)
    {
        if(filas>0 && columnas>0)
        {
            delete [] buffer[0];
            delete [] buffer;
        }
            filas=orig.filas ;
            columnas =orig.columnas ;

        if(filas>0 && columnas>0)
        {
            unsigned char **dat;
            dat=new unsigned char *[filas];
            dat[0]= new unsigned char [filas*columnas];

            for(int i=1; i<filas; i++)
                dat[i]= dat[i-1]+columnas;
            buffer=dat;

            for(int i=0;i<filas;i++)
                for(int j=0;j<columnas;j++)
                    buffer[i][j]=orig.buffer[i][j];
        }

    }else{filas=0;columnas=0;}

     return *this;
}


bool Imagen::LeerImagen(const char file[])
{
    bool exito=false;
    int f=0,c=0;
    TipoImagen n = LeerTipoImagen(file,f,c);
    if(n==IMG_PGM)
    {
        unsigned char *vector= new unsigned char [f*c];
        if(LeerImagenPGM (file, f,c,vector))
        {
/*********************************************************/
                Imagen nueva(f,c);
/*********************************************************/
            unsigned char cad;
            for(int i=0; i<nueva.filas; i++)
                for(int j=0; j<nueva.columnas; j++)
                {
                    cad=vector[j+i*c];
                    nueva.Set(i,j,cad);
                    exito=true;
                }
            *this=nueva;
        }

        delete [] vector;
    }
    return exito;
}
bool Imagen::EscribirImagen(const char file[])const //Salva img en file
{
    int f=filas;
    int c=columnas;

    bool exito=false;
    unsigned char *vector;
    vector = new unsigned char[f*c];

    for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
            vector[i*c+j] =Get(i,j) ;

    if(EscribirImagenPGM (file, vector, f, c))
        exito=true;
    delete [] vector;

    return exito;
}

