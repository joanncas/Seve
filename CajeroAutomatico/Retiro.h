#pragma once
#ifndef RETIRO_H
#define RETIRO_H

#include "Transaccion.h" // Definición de la clase Transaccion
class Teclado; // declaración anticipada de la clase Teclado
class DispensadorEfectivo; // declaración anticipada de la clase DispensadorEfectivo

class Retiro : public Transaccion
{
public:
	Retiro(int, Pantalla &, BaseDatosBanco &, Teclado &, DispensadorEfectivo &);
	virtual void ejecutar(); // realiza la transacción
private:
	int monto; // monto a retirar
	Teclado &teclado; // referencia al teclado del ATM
	DispensadorEfectivo &dispensadorEfectivo; // referencia al dispensador de efectivo del ATM
	int mostrarMenuDeMontos() const; // muestra el menú de retiro
}; 

#endif // RETIRO_H