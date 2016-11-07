#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Pantalla.h" // Definici�n de la clase Pantalla
using namespace std;

// imprime un mensaje sin nueva l�nea
void Pantalla::mostrarMensaje(string mensaje) const
{
	cout << mensaje;
} 

  // imprime un mensaje con una nueva l�nea
void Pantalla::mostrarLineaMensaje(string mensaje) const
{
	cout << mensaje << endl;
} 

  // imprime un monto en d�lares
void Pantalla::mostrarMontoDolares(double monto) const
{
	cout << fixed << setprecision(2) << "$" << monto;
} 
