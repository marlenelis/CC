/**
  * @file transformacion.h
  * @brief Fichero cabecera para insertar la implementación deseada
  *
  * Permite modificar la implementación @a CUAL_COMPILO mediante un número el 1 o 2.
  *
  */


#define CUAL_COMPILO 2 ///< CUAL_COMPILO

#if CUAL_COMPILO==1
  #include "transformacion1.h"
#else
  #include "transformacion2.h"
#endif
