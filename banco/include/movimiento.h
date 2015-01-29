// **************************************************************
// *** MOVIMIENTO
// **************************************************************
#include <string>

#ifndef _MOVIMIENTO_
#define _MOVIMIENTO_

	#include "hora.h"
	#include "fecha.h"
	class Movimiento {
	  private:
	    Hora hora;
	    Fecha fecha;
	    double cantidad;
	    std::string anotacion;

	  public:
	    Movimiento()  { cantidad=0; }   // Para poder LeerMovimiento
	    Movimiento(Hora h, Fecha f, double c, std::string a="")
		       { fecha=f; hora=h; cantidad=c; anotacion=a; }
	    Hora GetHora() const                        { return hora; }
	    Fecha GetFecha() const                      { return fecha; }
	    double GetCantidad() const                  { return cantidad; }
	    std::string GetAnotacion() const                 { return anotacion; }
	};

	Movimiento LeerMovimiento();

	void EscribirMovimiento(const Movimiento& m);

#endif

