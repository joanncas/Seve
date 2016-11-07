#pragma once
#ifndef DEPOSITO_H
#define DEPOSITO_H

#include "Transaccion.h" // Definición de la clase Transaccion
class Teclado; // declaración anticipada de la clase Teclado
class RanuraDeposito; // declaración anticipada de la clase RanuraDeposito

class Deposito : public Transaccion
{
public:
	Deposito(int, Pantalla &, BaseDatosBanco &, Teclado &, RanuraDeposito &);
	virtual void ejecutar(); // realiza la transacción
private:
	double monto; // monto a depositar
	Teclado &teclado; // referencia al teclado del ATM
	RanuraDeposito &ranuraDeposito; // reference a la ranura de depósito del ATM
	double pedirMontoADepositar() const; // obtiene el monto a depositar del usuario
}; 

#endif // DEPOSITO_H
