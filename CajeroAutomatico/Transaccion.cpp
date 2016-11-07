#include "stdafx.h"
#include "Transaccion.h" // Definici�n de la clase Transaccion
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco

// el constructor inicializa las caracter�sticas comunes de todas las Transacciones
Transaccion::Transaccion(int numeroCuentaUsuario, Pantalla &pantallaATM,
	BaseDatosBanco &baseDatosBancoATM)
	: numeroCuenta(numeroCuentaUsuario),
	pantalla(pantallaATM),
	baseDatosBanco(baseDatosBancoATM)
{
}  

  // devuelve el n�mero de cuenta 
int Transaccion::obtenerNumeroCuenta() const
{
	return numeroCuenta;
} 

  // devuelve referencia a la pantalla
Pantalla &Transaccion::obtenerPantalla() const
{
	return pantalla;
} 

  // devuelve referencia a la base de datos del banco
BaseDatosBanco &Transaccion::obtenerBaseDatosBanco() const
{
	return baseDatosBanco;
} 