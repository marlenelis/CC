// **************************************************************
// *** CLIENTE
// **************************************************************

#include <string>

#ifndef _CLIENTE_H
#define _CLIENTE_H 
	struct Cliente {
	  std::string nif;
	  std::string nombre, apellidos;
	  std::string direccion;
	};

	Cliente LeerCliente() ;
	void EscribirCliente(const Cliente& cli) ;
#endif
