#pragma once
#ifndef ATM_H
#define ATM_H

#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "Teclado.h" // Definici�n de la clase Teclado
#include "DispensadorEfectivo.h" // Definici�n de la clase DispensadorEfectivo
#include "RanuraDeposito.h" // Definici�n de la clase RanuraDeposito
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco
class Transaccion; // declaraci�n anticipada de la clase Transaccion

class ATM
{
public:
	ATM(); // el constructor inicializa los miembros de datos
	void ejecutar(); // inicia el ATM
private:
	bool usuarioAutenticado; // indica si el usuario est� autenticado
	int numeroCuentaActual; // n�mero de cuenta del usuario actual
	Pantalla pantalla; // pantalla del ATM
	Teclado teclado; // teclado del ATM
	DispensadorEfectivo dispensadorEfectivo; // dispensador de efectivo del ATM
	RanuraDeposito ranuraDeposito; // ranura de dep�sito del ATM
	BaseDatosBanco baseDatosBanco; // base de datos de informaci�n de las cuentas

								   // funciones utilitarias privadas
	void autenticarUsuario(); // trata de autenticar al usuario
	void realizarTransacciones(); // realiza transacciones
	int mostrarMenuPrincipal() const; // muestra el men� principal

									  // devuelve un objeto de la clase derivada de Transaccion que se especifica
	Transaccion *crearTransaccion(int);
}; 

#endif // ATM_H