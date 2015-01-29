# include <iostream>
# include "imagenES.h"

#ifndef IMAGEN_H
#define IMAGEN_H

/**
  * @file imagen.h
  * @brief Representación en base a dos enteros (filas y columnas) más un vector -en memoria
  * dinámica- de punteros a las filas. El primer puntero apunta a un vector con todos los
  * elementos de la imagen consecutivos por filas. El resto de punteros apunta al comienzo
  * de cada fila
  */
class Imagen
{
    private:
        int filas;				///< Imagen filas
		int columnas;			///< Imagen columnas
		unsigned char **buffer;	///< Imagen buffer

    public:
      /**
      * @brief constructor por defecto
      * inicializa el nuevo tipo
      */
        Imagen();//constructor por defecto

      /**
      * @brief constructor con parámetros
      * prepara recursos e inicializa el nuevo tipo
      * con n @a f (filas) por n @a c (columnas)
      */
        Imagen(int f,int c);//constructor con parámetros

      /**
      * @brief destructor del nuevo tipo
      * Liberacion de memoria
      */
        ~Imagen();//destructor

      /**
      * @brief constructor de copias
      */
        Imagen(const Imagen& orig);//constructor de copias
      /**
      * @brief redefinición de operator=
      */
        Imagen& operator=(const Imagen& orig);//operator=

      /**
      * @brief  Devuelve el número filas
      * @return el número de filas de @a Imagen
      * @see Filas()
      */
        int Filas()const;

      /**
      * @brief  Devuelve el número columnas
      * @return el número de columnas de @a Imagen
      * @see Columnas()
      */
        int Columnas()const;

      /**
      * @brief  Inserta un nuevo dato en el nuevo tipo Imagen
      * @param i posición filas
      * @param j posición columnas
      * @param val nuevo dato.
      * @see Set
      */
        void Set(int i,int j,unsigned char val);

      /**
      * @brief  Obtiene el dato que se encuentra en la posición i (filas) y j (columnas)
      * @param i posición filas
      * @param j posición columnas
      * @return Devuelve el dato (unsigned char).
      * @see Get
      */
        unsigned char Get(int i,int j)const;

      /**
      * @brief Lee una imagen de tipo PGM sobre memoria reservada
      * @param file nombre del archivo a leer
      * @retval true si ha tenido éxito en la lectura.
      * @retval false si se ha producido algún error en la lectura.
      *
      * @see LeerImagen
      */
        bool LeerImagen(const char file[]);

      /**
      * @brief Escribe una imagen de tipo PGM
      * @param file nombre del archivo a escribir
      * @retval true si ha tenido éxito en la escritura.
      * @retval false si se ha producido algún error en la escritura.
      *
      * @see EscribirImagen
      */
        bool EscribirImagen(const char file[])const;

};

#endif // IMAGEN_H
