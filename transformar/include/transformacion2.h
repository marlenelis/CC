/**
  * @file transformacion2.h
  * @brief Fichero cabecera que contiene las declaraciones necesarias para utilizar
  * la nueva representación Transformacion.
  * Representación en base a un puntero a un vector en memoria dinámica.

  */
#ifndef TRANSF_2_H_
    #define TRANSF_2_H_
/**
  * @class Transformacion
  */
        class Transformacion
        {
            private:
                int *datos; ///< Transformacion datos
            public:
                /**
                  * @brief constructor por defecto
                  * inicializa el nuevo tipo
                  */
                    Transformacion();//constructor
                /**
                  * @brief constructor de copias
                  */
                    Transformacion(const Transformacion& orig);//Constructor de copias
                /**
                  * @brief destructor del nuevo tipo
                  * Liberacion de memoria
                  */
                    ~Transformacion();//destructor
                /**
                  * @brief redefinición de operator=
                  */
                    Transformacion& operator=(const Transformacion& orig );//operator=
                    /**
                  * @brief  Obtiene el dato que se encuentra en la posición i del vector
                  * @param i posición
                  * @return Devuelve el dato (int).
                  * @see Get
                  */
                    int Get( int  i)const;
                /**
                  * @brief  Inserta un nuevo dato en el nuevo tipo Imagen
                  * @param i posición
                  * @param c nuevo dato.
                  * @see Set
                  */
                    void Set( int  i, int c);

        };
        /**
        * @brief redefinición de operator+
        */
        Transformacion  operator+(const Transformacion& Tr1,const Transformacion& Tr2);//operator+
        /**
        * @brief Lee la transformación desde un fichero de disco.
        * @param file nombre del fichero a leer
        * @param Tr nuevo tipo que almacenara los valores leidos.
        * @return true si la lectura se ha realizado con éxito
        * @return false si en la lectura ha ocurrido algun error.
        **/
        bool LeerTransformacion(const char file[],Transformacion &Tr);
        /**
        * @brief Salvar la transformación a un fichero de disco.
        * @param file nombre del fichero en el cual de va a salvar los datos que contiene el nuevo tipo
        * @param Tr nuevo tipo del cual se obtendrán los datos a ser salvados.
        * @param tipo tipo de fichero a salvar t o T ->texto ; b o B ->binario
        **/
        bool Escribir_Transformacion(const char file[],Transformacion Tr,char tipo);

    #endif // TRANSF_2_H_
