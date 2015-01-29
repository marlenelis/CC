/**
  * @mainpage Práctica Final: Clases y E/S Transformación de Imágenes \n de Metodología de la Programación
  * @author Marlene E. Vásquez Calero
  * @date Junio 2012
  * <br><img src="../lenna.jpg"><br>
  * \htmlonly
    <marquee scrollamount="5" scrolldelay="10"><font color=blue>   ¡¡¡¡¡ Finalizado !!! .</font></marquee>
  * \endhtmlonly
  * @file procesar.h
  * @brief Fichero cabecera que contiene las declaraciones
  * de las funciones para ocultar/extraer un mensaje y transformar  imagenes.
  */

#include <iostream>
#include <fstream>
#include "imagen.h"
#include "transformacion.h"

#ifndef PROCESAR_H
#define PROCESAR_H

using namespace std;
    /**
      * @brief devuelve el tamaño de un vector de caracteres que lo utilizaremos
      * para almacenar el mensaje que se va a ocultar/revelar.
      **/
        int tamanio(const char c[]);//tamaño de un vector de caracteres

    /**
      * @brief devuelve si el bit es 1 o 0 al recorrer el @a numero @a nbit
      **/
        bool activo(int numero ,int nbit);

    /**
      * @brief oculta el mensaje en la imagen.
      * @param img imagen en la cual se va a ocultar el mensaje.
      * @param mensaje mensaje a ocultar en la imagen.
      * @return true si se ha realizado la ocultación con éxito.
      * @return false si no se a ocultado el mensaje.
      **/
        bool ocultar( Imagen& img ,char mensaje[]);

    /**
      * @brief  revela el mensaje de la imagen.
      * @param  img imagen de la cual se va a obtener el mensaje.
      * @param  mensaje mensaje obtenido de la imagen.
      * @return true si se ha realizado con éxito la revelación.
      * @return false si no se ha realizado con éxito la revelación.
      **/
        bool  revelar (Imagen img,char mensaje[]);

    /**
      * @brief  transforma una imagen tras aplicar una transformación.
      * @param  entrada imagen a la cual se va a aplicar una transformación,
      *         cambiando los valores de cada pixel por los valores que contiene @a Tr .
      * @param  Tr valores con los que se va a cambiar los pixeles de la imagen.
      * @return true si se ha realizado con éxito la transformación.
      * @return false si no se ha realizado con éxito la transformación.
      **/
        bool transformar_Imagen( Imagen& entrada,Transformacion Tr);

#endif
