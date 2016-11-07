#pragma once
#ifndef TRANSACCION_H
#define TRANSACCION_H

class Pantalla; // declaraci�n anticipada de la clase Pantalla
class BaseDatosBanco; // declaraci�n anticipada de la clase BaseDatosBanco

class Transaccion
{
public:
	// el constructor inicializa las caracter�sticas comunes de todas las Transacciones
	Transaccion(int, Pantalla &, BaseDatosBanco &);

	virtual ~Transaccion() { } // destructor virtual con cuerpo vac�o

	int obtenerNumeroCuenta() const; // devuelve el n�mero de cuenta
	Pantalla &obtenerPantalla() const; // devuelve una referencia a la pantalla
	BaseDatosBanco &obtenerBaseDatosBanco() const; // devuelve una referencia a la base de datos

												   // funci�n virtual pura para realizar la transacci�n
	virtual void ejecutar() = 0; // se sobrescribe en las clases derivadas
private:
	int numeroCuenta; // indica la cuenta involucrada
	Pantalla &pantalla; // referencia a la pantalla del ATM
	BaseDatosBanco &baseDatosBanco; // referencia a la base de datos de informaci�n de las cuentas
}; 

#endif // TRANSACCION_H
