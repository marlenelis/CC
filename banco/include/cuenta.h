// **************************************************************
// *** CUENTA
// **************************************************************

#include <cassert>
#include <vector>
#include <string>

#ifndef _CUENTA_
#define _CUENTA_
	#include "movimiento.h"
	class Cuenta {
	  private:
	    std::string entidad;
	    std::string sucursal;
	    std::string cuenta;
	    std::string dcontrol;
	    double saldo;
	    std::vector<Movimiento> movimientos;

	    void CalcularDigitosControl();
	    void CrearCuenta(std::string ent, std::string suc, std::string cue, const std::string& ctr);

	  public:
	    Cuenta() { saldo=0; }   // Para poder LeerCuenta
	    // Al crear la cuenta se pone saldo a cero ... asi evitamos problemas despues.
	    // Si podemos crear cuenta con un saldo inicial distinto de cero, al volcar
	    // los datos a cout y luego leerlos de cin deberiamos guardar tambien este
	    // dato para que todo cuadre --> solución: no ponerlo aquí
	    Cuenta(const std::string& ent,const  std::string& suc,const  std::string& cue,const  std::string& ctr);
	    Cuenta(const std::string& ncuenta);
	    std::string GetNumeroCuenta() const   { return entidad+sucursal+dcontrol+cuenta; }

	    bool Valida() const  { return dcontrol!=""; }

	    double Saldo() const  { return saldo; }
	    void Ingreso (const Hora& h, const Fecha& f, double cant, const std::string& motivo="");
	    void Retirada(const Hora& h, const Fecha& f, double cant, const std::string& motivo="") {
		            assert(saldo>=cant);
		            Ingreso(h,f,-cant,motivo);
		          }

	    int NumMovimientos() const   { return (int)movimientos.size(); }
	    Movimiento GetMovimiento(int n) const { assert(n>=0 && n<(int)movimientos.size());
		                               return movimientos.at(n); }
	    //vector<Movimiento> GetUltimosMovimientos(int num=10);
	};

	void EscribirCuenta(const Cuenta& c);
	Cuenta LeerCuenta();
#endif


