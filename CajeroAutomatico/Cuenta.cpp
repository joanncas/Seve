#include "stdafx.h"
#include "Cuenta.h" // definición de la clase Cuenta

// el constructor de Cuenta inicializa los atributos
Cuenta::Cuenta(int elNumeroDeCuenta, int elNIP,double elSaldoDisponible, double elSaldoTotal): numeroCuenta(elNumeroDeCuenta),nip(elNIP),
saldoDisponible(elSaldoDisponible),
	saldoTotal(elSaldoTotal){
} 

  // determina si un NIP especificado por el usuario coincide con el NIP en la Cuenta
bool Cuenta::validarNIP(int nipUsuario) const
{
	if (nipUsuario == nip)
		return true;
	else
		return false;
} 

  // devuelve el saldo disponible
double Cuenta::obtenerSaldoDisponible() const
{
	return saldoDisponible;
} 

  // devuelve el saldo total
double Cuenta::obtenerSaldoTotal() const
{
	return saldoTotal;
} 

  // abona un monto a la cuenta
void Cuenta::abonar(double monto)
{
	saldoTotal += monto; // lo suma al saldo total
} 

  // carga un monto a la cuenta
void Cuenta::cargar(double monto)
{
	saldoDisponible -= monto; // resta del saldo disponible
	saldoTotal -= monto; // resta del saldo total
}

  // devuelve el número de cuenta
int Cuenta::obtenerNumeroCuenta() const
{
	return numeroCuenta;
} 