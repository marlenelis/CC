// **************************************************************
// *** BANCO
// **************************************************************

#include <cassert>
#include <vector>
#include <string>

#ifndef _BANCO_
#define _BANCO_
	#include "cuenta.h"
	#include "cliente.h"
	struct Titularidad {
	  std::string nif;
	  std::string ncuenta;
	};

	class Banco {
	  private:
	    std::vector<Cliente> clientes;
	    std::vector<Cuenta> cuentas;
	    std::vector<Titularidad> relacioncc;

	    int BuscaCliente(const std::string& nif) const;
	    int BuscaCuenta(const std::string& ncuenta) const;
	    int BuscaPar(const std::string& nif, const std::string& ncuenta) const;

	  public:

	    // Si el cliente no existe lo añade a la lista
	    // Si el cliente ya existe ... no lo añade: modifica sus datos
	    // Si la cuenta ya existe lo añade como titular
	    // Si la cuenta no existe: la crea
	    void NuevoCC(const Cliente& cli, const std::string& ncuenta);

	    // Añade nuevo titular a una cuenta
	    // Debe verificar que ambos existen
	    //void NuevoTitular(string nif, string cuenta);  // Con NuevoCliente sería suficiente?

	    // Consultores
	    std::vector<Cliente> Titulares(const std::string& ncuenta="") const;  // Si =="" entonces listado completo
	    Cliente GetCliente(const std::string& nif) const;

	    std::vector<Cuenta> CuentasCliente(const std::string& nif="") const;  // Si =="" entonces listado completo
	    Cuenta GetCuenta(const std::string& ncuenta) const;
	    bool ExisteCuenta(const std::string& ncuenta) const;

	    // Consultores de una cuenta (no son estrictamente necesarios si tenemos GetCuenta)
	    // double Saldo(string ncuenta);

	    // Modificadores de cuentas
	    void Ingreso (const std::string& ncuenta, const Hora& h, const Fecha& f, double cant, const std::string& motivo="");
	    void Retirada (const std::string& ncuenta, const Hora& h, const Fecha& f, double cant, const std::string& motivo="");


	    // bool InsertaCliente(Cliente cli);  // Añade o modifica según si estaba o no
	    // void BorraCliente(string nif);     // Integridad referencial ?

	    // bool InsertaCuenta() // ???
	    // void BorraCuenta(string ncuenta);   // Integridad referencial ?

	    // Para solucionar la integridad referencial quizá en lugar de borrar
	    // podríamos "desactivar" (clientes y cuentas)

	    void CargarDatos();
	    void SalvarDatos() const;
	};
#endif
