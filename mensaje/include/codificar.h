/**
  * @file codificar.h
  * @brief Fichero cabecera para la inserción y extracción de un mensaje  en imagenes.
  *
  *
  */
#ifndef _CODIFICA_R_H_
	#define _CODIFICA_R_H_
	/**
  * @brief Imprimir
  *
  * muestra el mensaje por pantalla
  *
  * @see imprimir
  */
  
		void imprimir( char m[]);
		

/**
  * @brief consulta si el tamaño del mensaje cabe en la imagen
  * @param tam parametro que refiere al tamaño de la imagen
  * @param mensaje parametro que refiere al mensaje
  *
  * @retval true si cabe el mensaje en la imagen
  * @retval false si el mensaje es de mayor tamaño que la imagen
  *
  * @see cabe_mensaje
  */
  
		bool cabe_mensaje(int tam,char mensaje[]);
		
/**
  * @brief consulta si el bit esta activo o no
  * @param numero parametro del cual se desea obtener si la 
  * posicion de bit esta activa o no
  * @param nbit parametro que refiere a  la posicion de bits del número
  * @retval 1 si esta activo
  * @retval 0 si no lo esta
  *
  * @see activo
  */
		bool activo(int numero ,int nbit);		
	/**
  * @brief Comprueba si el nombre de la imagen de salida
  * tiene incluido el tipo sea este .PGM o .PPM
  * @param nombre parametro donde se encuentra almacena los caracteres 
  * del nombre para la imagen de salida. 
  * @param tipo parametro con el que vamos a comprobar si el nombre tiene incluido el tipo.
  *
  * @see comparaTipo
  */
		bool comparaTipo(char nombre[],char tipo[]);
	
/**
  * @brief lee una cadena de caracteres y evita las líneas en blanco.
  * @param c parametro donde se almacena los caracteres leidos. 
  * @param tamanio parametro que determina el tamaño de almacenamiento.
  *
  * @see lee_linea
  */
  
		void lee_linea(char c[], int tamanio);	
		
/**
  * @brief Oculta un cadena de caracteres (mensaje) en una imagen.
  * @param buffer parámetro que refiere a la zona de memoria
  * para obtener el valor de cada uno de los píxeles de la imagen en la cual vamos a
  * ocultar el mensaje.
  * @param mensaje  parámetro que refiere al mensaje que vamos a insertar en la imagen 
  * @param tam  parámetro que refiere al tamaño del buffer de la imagen.
  * @retval true si la ocultación se a realizado con exito.
  * @retval false si a ocurrido un error en el proceso de ocultar el mensaje
  *
  * @see ocultar
  */  
  
		bool ocultar( unsigned char buffer[],char mensaje[],int tam);		
		
/**
  * @brief revela un mensaje oculto en una imagen.
  * @param buffer parámetro que refiere a la zona de memoria 
  * para obtener el valor de cada uno de los píxeles de la imagen de la cual vamos a
  * obtener el mensaje
  * @param mensaje  parámetro que refiere donde va almacenar el mensaje 
  * que se a de obtener de la imagen.
  * @param tam  parámetro que refiere al tamaño del buffer de la imagen.
  * @retval true si la la extracción del mensaje se a realizado con exito.
  * @retval false si a ocurrido un error en el proceso de extraer el mensaje.
  *
  * @see revelar
  */
  
		bool revelar (unsigned char buffer[],char mensaje[],int tam);


	#endif

/* Fin Fichero: codificar.h */

