#include "stdafx.h"
#include <iostream>
using std::cin;

#include "Teclado.h" // Definici�n de la clase Teclado

// devuelve un valor entero introducido por el usuario
int Teclado::obtenerEntrada() const
{
	int entrada; 
	cin >> entrada; 
	return entrada; 
} 