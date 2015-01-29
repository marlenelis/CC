/**
  * @autor Marlene V.
  * @file transformacion1.cpp
  * @brief Fichero que contiene las definiciones que utiliza el nuevo tipo @a Transformacion.
  *
  * Representación con un vector estático
  */

#include <fstream>
#include "transformacion1.h"
#include "imagen.h"
#include <string>
using namespace std;

void Transformacion::Set( int  i, int c)
{
    tabla[i]= c;
}
int Transformacion::Get( int  i)const// confirmar tipo----------------------
{
        return tabla[i];
}
Transformacion& Transformacion:: operator=(const Transformacion& orig )
{
    for(int i=0;i<256;i++)
        tabla[i]=orig.tabla[i];
    return *this;
}

Transformacion  operator+(const Transformacion& Tr1,const Transformacion& Tr2)//
{
    Transformacion res;
    for(int i=0;i<256; i++)
    {
        int n=0,c=0;
        n=Tr1.Get(i);
        c=Tr2.Get(n);
        res.Set(i,c);
    }
    return res;
}

/************************LEER Y SALVAR TRANSFORMACIONES***************************/
char Tipo(ifstream& f)
{
    char tipo;
    if(f)
    {
         f.seekg(7);
         f.get(tipo);
    }
    return tipo;
}

bool LeerTransformacion(const char file[],Transformacion& Tr)
{
        bool exito =false;
        int v[256];
        int n,j=0;
        ifstream f(file);
        if(f)
        {
            char tip_o = Tipo(f);
               if(tip_o =='T')
               {
                    f.seekg(13);
                    while(f>>n)
                    { v[j]=n  ;   j++; }
                    f.close();
                    for(int i=0;i<256;++i)    Tr.Set(i,v[i]);
                    exito=true;
                }
                else
                if(tip_o=='B')
                {
                    f.seekg(13);
                    if (f.read(reinterpret_cast<char *>(v),256*sizeof(int)))
                    {
                        for(int i=0;i<256;++i)  Tr.Set(i,v[i]);
                        exito=true;
                    }
                    f.close();
                }
    }

    return exito;
}

bool Escribir_Transformacion(const char file[],Transformacion Tr,char tipo)
{
    bool exito=true;
    int vec[256];
    //vector con los valores de la transformacion
    for(int i=0;i<256;++i)
            vec[i]=Tr.Get(i);
    //____________________________________________

    if(tipo=='T'||tipo=='t')
    {
        ofstream f(file);
        if(f){
           f<<"MP-TRF-T 256"<<endl;
           for(int i=0;i<256;++i)
                f<< vec[i]<<endl;
                f.close();
                 if(!f)
                    exito=false;
            }

    }
    else
        if(tipo=='B'|| tipo=='b')
        {
                ofstream f(file,ios::out|ios::binary);
                if(f){
                    f<<"MP-TRF-B 256"<<endl;
                    f.write(reinterpret_cast<const char *>(vec),256*sizeof(int));
                    f.close();
                        if(!f)
                        exito=false;
                    }


        }
    return exito;

}
/***********************************************************/
