/**
  * @file Transformaciones.h
  * @brief Fichero cabecera para inicializar las diferentes transformaciones
  * (negativo,desplazar,umbralizar, brillo).
  */

#include "transformacion.h"

#ifndef TRANSFS_H_
    #define TRANSFS_H_
        /*------------------NEGATIVO----------------------------*/
        /**
        * @brief inicializa la tranformacion negativo con valores
        * resultado de  realizar la siguiente resta 255−i  ; i(0,1,2,3,......,255)
        * @return nuevo tipo Transformación.
        **/
        Transformacion negativo ();

        /*------------------DESPLAZAR----------------------------*/

        /**
        * @brief inicializa la tranformación desplazar con valores
        * resultado de  realizar el desplazamiento de @a n bits i<<n  ; i(0,1,2,3,......,255)
        * @param n número de bits a desplazar.
        * @return nuevo tipo Transformación.
        **/
        Transformacion desplazar(int n);

        /*------------------UMBRALIZAR----------------------------*/

        /**
        * @brief inicializa la tranformación umbralizar con valores
        * resultado de si i<= @a v "umbral" valor a almacenar 0;caso contrario valor a almacenar 255;  i(0,1,2,3,......,255)
        * @param v umbral
        * @return nuevo tipo Transformación.
        **/
        Transformacion umbralizar(int v);

        /*------------------BRILLO----------------------------*/
        /**
        * @brief inicializa la tranformación brillo con valores
        * resultado de si i+d<0 valor a almacenar 0 o si i+ @a d>255 valor a almacenar 255;caso contrario valor a almacenar i+ @a d;  i(0,1,2,3,......,255)
        * @param d valor añadir
        * @return nuevo tipo Transformación.
        **/
        Transformacion brillo(int d);

#endif // TRANSFS_H_
