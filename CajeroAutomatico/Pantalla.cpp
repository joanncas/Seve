#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Pantalla.h" // Definición de la clase Pantalla
using namespace std;

// imprime un mensaje sin nueva línea
void Pantalla::mostrarMensaje(string mensaje) const
{
	cout << mensaje;
} 

  // imprime un mensaje con una nueva línea
void Pantalla::mostrarLineaMensaje(string mensaje) const
{
	cout << mensaje << endl;
} 

  // imprime un monto en dólares
void Pantalla::mostrarMontoDolares(double monto) const
{
	cout << fixed << setprecision(2) << "$" << monto;
} 
