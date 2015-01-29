/**
  * @autor Marlene V.
  * @file transformacion.cpp
  * @brief Fichero de definiciones para insertar la implementación deseada
  *
  * Incluye la definición correspondiente dependiendo de la selección en transformacion.h
  *
  */

#include "transformacion.h" // Aquí se define el valor de CUAL_COMPILO

#if CUAL_COMPILO==1
  #include "transformacion1.cpp"
#else
  #include "transformacion2.cpp"
#endif

