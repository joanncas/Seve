#include "stdafx.h"
#include "DispensadorEfectivo.h" // Definición de la clase DispensadorEfectivo

// el constructor predeterminado de DispensadorEfectivo inicializa la cuenta al valor predeterminado
DispensadorEfectivo::DispensadorEfectivo()
{
	cuenta = CUENTA_INICIAL; // establece el atributo cuenta con el valor predeterminado
} 

  // simula el proceso de dispensar el monto especificado de efectivo; asume que hay suficiente efectivo
  // disponible (la llamada anterior a haySuficienteEfectivoDisponible devolvió true)
void DispensadorEfectivo::dispensarEfectivo(int monto)
{
	int billetesRequeridos = monto / 20; // número de billetes de $20 requeridos
	cuenta -= billetesRequeridos; // actualiza la cuenta de billetes
} 

  // indica si el dispensador de efectivo puede dispensar el monto deseado
bool DispensadorEfectivo::haySuficienteEfectivoDisponible(int monto) const
{
	int billetesRequeridos = monto / 20; // número de billetes de $20 requeridos

	if (cuenta >= billetesRequeridos)
		return true; // hay suficientes billetes disponibles
	else
		return false; // no hay suficientes billetes disponibles
} 