#pragma once
#ifndef TRANSACCION_H
#define TRANSACCION_H

class Pantalla; // declaración anticipada de la clase Pantalla
class BaseDatosBanco; // declaración anticipada de la clase BaseDatosBanco

class Transaccion
{
public:
	// el constructor inicializa las características comunes de todas las Transacciones
	Transaccion(int, Pantalla &, BaseDatosBanco &);

	virtual ~Transaccion() { } // destructor virtual con cuerpo vacío

	int obtenerNumeroCuenta() const; // devuelve el número de cuenta
	Pantalla &obtenerPantalla() const; // devuelve una referencia a la pantalla
	BaseDatosBanco &obtenerBaseDatosBanco() const; // devuelve una referencia a la base de datos

												   // función virtual pura para realizar la transacción
	virtual void ejecutar() = 0; // se sobrescribe en las clases derivadas
private:
	int numeroCuenta; // indica la cuenta involucrada
	Pantalla &pantalla; // referencia a la pantalla del ATM
	BaseDatosBanco &baseDatosBanco; // referencia a la base de datos de información de las cuentas
}; 

#endif // TRANSACCION_H
