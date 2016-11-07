#pragma once
#ifndef ATM_H
#define ATM_H

#include "Pantalla.h" // Definición de la clase Pantalla
#include "Teclado.h" // Definición de la clase Teclado
#include "DispensadorEfectivo.h" // Definición de la clase DispensadorEfectivo
#include "RanuraDeposito.h" // Definición de la clase RanuraDeposito
#include "BaseDatosBanco.h" // Definición de la clase BaseDatosBanco
class Transaccion; // declaración anticipada de la clase Transaccion

class ATM
{
public:
	ATM(); // el constructor inicializa los miembros de datos
	void ejecutar(); // inicia el ATM
private:
	bool usuarioAutenticado; // indica si el usuario está autenticado
	int numeroCuentaActual; // número de cuenta del usuario actual
	Pantalla pantalla; // pantalla del ATM
	Teclado teclado; // teclado del ATM
	DispensadorEfectivo dispensadorEfectivo; // dispensador de efectivo del ATM
	RanuraDeposito ranuraDeposito; // ranura de depósito del ATM
	BaseDatosBanco baseDatosBanco; // base de datos de información de las cuentas

								   // funciones utilitarias privadas
	void autenticarUsuario(); // trata de autenticar al usuario
	void realizarTransacciones(); // realiza transacciones
	int mostrarMenuPrincipal() const; // muestra el menú principal

									  // devuelve un objeto de la clase derivada de Transaccion que se especifica
	Transaccion *crearTransaccion(int);
}; 

#endif // ATM_H