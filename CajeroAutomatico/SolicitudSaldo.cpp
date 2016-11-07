#include "stdafx.h"
#include "SolicitudSaldo.h" // Definici�n de la clase SolicitudSaldo
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco

// el constructor de SolicitudSaldo inicializa los miembros de datos de la clase base
SolicitudSaldo::SolicitudSaldo(int numeroCuentaUsuario, Pantalla &pantallaATM,
	BaseDatosBanco &baseDatosBancoATM)
	: Transaccion(numeroCuentaUsuario, pantallaATM, baseDatosBancoATM)
{
} 

  // realiza una transacci�n; sobrescribe la funci�n virtual pura de Transaccion
void SolicitudSaldo::ejecutar()
{
	// obtiene referencias a la base de datos del banco y la pantalla
	BaseDatosBanco &baseDatosBanco = obtenerBaseDatosBanco();
	Pantalla &pantalla = obtenerPantalla();

	// obtiene el saldo disponible para la Cuenta del usuario actual
	double saldoDisponible =
		baseDatosBanco.obtenerSaldoDisponible(obtenerNumeroCuenta());

	// obtiene el saldo total para la Cuenta del usuario actual
	double saldoTotal =
		baseDatosBanco.obtenerSaldoTotal(obtenerNumeroCuenta());

	// muestra la informaci�n del saldo en la pantalla
	pantalla.mostrarLineaMensaje("\nInformacion de saldo:");
	pantalla.mostrarMensaje(" - Saldo disponible: ");
	pantalla.mostrarMontoDolares(saldoDisponible);
	pantalla.mostrarMensaje("\n - Saldo total:     ");
	pantalla.mostrarMontoDolares(saldoTotal);
	pantalla.mostrarLineaMensaje("");
} 