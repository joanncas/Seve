#pragma once
#ifndef DISPENSADOR_EFECTIVO_H
#define DISPENSADOR_EFECTIVO_H

class DispensadorEfectivo
{
public:
	DispensadorEfectivo(); // el constructor inicializa la cuenta de billetes con 500

						   // simula el proceso de dispensar el monto especificado de efectivo
	void dispensarEfectivo(int);

	// indica si el dispensador de efectivo puede dispensar el monto deseado
	bool haySuficienteEfectivoDisponible(int) const;
private:
	const static int CUENTA_INICIAL = 500;
	int cuenta; // número de billetes de $20 restantes 
}; 

#endif // DISPENSADOR_EFECTIVO_H