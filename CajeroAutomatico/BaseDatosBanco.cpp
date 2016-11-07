#include "stdafx.h"
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco

// el constructor predeterminado de BaseDatosBanco inicializa las cuentas
BaseDatosBanco::BaseDatosBanco()
{
	// crea dos objetos Cuenta para evaluar
	Cuenta cuenta1(12345, 54321, 1000.0, 1200.0);
	Cuenta cuenta2(98765, 56789, 200.0, 200.0);

	// agrega los objetos Cuenta al vector cuentas
	cuentas.push_back(cuenta1); // agrega cuenta1 al final del vector
	cuentas.push_back(cuenta2); // agrega cuenta2 al final del vector
} 

  // obtiene el objeto Cuenta que contiene el n�mero de cuenta especificado
Cuenta * BaseDatosBanco::obtenerCuenta(int numeroCuenta)
{
	// busca de un n�mero de cuentas que coincida
	for (size_t i = 0; i < cuentas.size(); i++)
	{
		// devuelve la cuenta actual si se encontro una coincidencia
		if (cuentas[i].obtenerNumeroCuenta() == numeroCuenta)
			return &cuentas[i];
	} 

	return NULL; // si no encontr� una cuenta que coincida, devuelve NULL
} 

  // determina si el n�mero de cuenta y NIP especificados por el usuario coinciden
  // con los de una cuenta en la base de datos
bool BaseDatosBanco::autenticarUsuario(int numeroCuentaUsuario,
	int nipUsuario)
{
	// intenta obtener la cuenta con el n�mero de cuentas
	Cuenta * const cuentaUsuarioPtr = obtenerCuenta(numeroCuentaUsuario);

	// si la cuenta existe, devuelve el resultado de la funci�n validarNIP de Cuenta
	if (cuentaUsuarioPtr != NULL)
		return cuentaUsuarioPtr->validarNIP(nipUsuario);
	else
		return false; // no se encontr� el n�mero de cuenta, por lo que devuelve false
} 

  // devuelve el saldo disponible de la Cuenta con el n�mero de cuenta especificado
double BaseDatosBanco::obtenerSaldoDisponible(int numeroCuentaUsuario)
{
	Cuenta * const cuentaUsuarioPtr = obtenerCuenta(numeroCuentaUsuario);
	return cuentaUsuarioPtr->obtenerSaldoDisponible();
} 

  // devuelve el saldo total de la Cuenta con el n�mero de cuenta especificado
double BaseDatosBanco::obtenerSaldoTotal(int numeroCuentaUsuario)
{
	Cuenta * const cuentaUsuarioPtr = obtenerCuenta(numeroCuentaUsuario);
	return cuentaUsuarioPtr->obtenerSaldoTotal();
} 

  // abona un monto a la Cuenta con el n�mero de cuenta especificado
void BaseDatosBanco::abonar(int numeroCuentaUsuario, double monto)
{
	Cuenta * const cuentaUsuarioPtr = obtenerCuenta(numeroCuentaUsuario);
	cuentaUsuarioPtr->abonar(monto);
} 

  // carga un monto a la Cuenta con el n�mero de cuenta especificado
void BaseDatosBanco::cargar(int numeroCuentaUsuario, double monto)
{
	Cuenta * const cuentaUsuarioPtr = obtenerCuenta(numeroCuentaUsuario);
	cuentaUsuarioPtr->cargar(monto);
}
