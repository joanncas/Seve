#pragma once
#ifndef SOLICITUD_SALDO_H
#define SOLICITUD_SALDO_H

#include "Transaccion.h" // Definici�n de la clase Transaccion

class SolicitudSaldo : public Transaccion
{
public:
	SolicitudSaldo(int, Pantalla &, BaseDatosBanco &); // constructor
	virtual void ejecutar(); // realiza la transacci�n
}; 

#endif // SOLICITUD_SALDO_H
