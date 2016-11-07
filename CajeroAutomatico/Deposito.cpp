#include "stdafx.h"
#include "Deposito.h" // Definici�n de la clase Deposito
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco
#include "Teclado.h" // Definici�n de la clase Teclado
#include "RanuraDeposito.h" // Definici�n de la clase RanuraDeposito

const static int CANCELO = 0; // constante que representa la opci�n de cancelar 

							  // el constructor de Deposito inicializa los miembros de datos de la clase
Deposito::Deposito(int numeroCuentaUsuario, Pantalla &pantallaATM,
	BaseDatosBanco &baseDatosBancoATM, Teclado &tecladoATM,
	RanuraDeposito &ranuraDepositoATM)
	: Transaccion(numeroCuentaUsuario, pantallaATM, baseDatosBancoATM),
	teclado(tecladoATM), ranuraDeposito(ranuraDepositoATM)
{
	
} 

  // realiza una transacci�n; sobrescribe a la funci�n virtual pura de Transaccion
void Deposito::ejecutar()
{
	BaseDatosBanco &baseDatosBanco = obtenerBaseDatosBanco(); // obtiene una referencia
	Pantalla &pantalla = obtenerPantalla(); // obtiene una referencia

	monto = pedirMontoADepositar(); // obtiene el monto a depositar del usuario

									// comprueba si el usuario introdujo un monto a depositar o cancel�
	if (monto != CANCELO)
	{
		// solicita el sobre de dep�sito que contiene el monto especificado
		pantalla.mostrarMensaje(
			"\nInserte un sobre de deposito que contenga ");
		pantalla.mostrarMontoDolares(monto);
		pantalla.mostrarLineaMensaje(" en la ranura de deposito.");

		// recibe el sobre de dep�sito
		bool sobreRecibido = ranuraDeposito.seRecibioSobre();

		// comprueba si se recibi� el sobre de dep�sito
		if (sobreRecibido)
		{
			pantalla.mostrarLineaMensaje("\nSe recibio su sobre."
				"\nNOTA: El dinero depositado no estara disponible sino hasta"
				"\nverificar el monto de cualquier efectivo incluido, junto con "
				"los cheques.");

			// abona a la cuenta para reflejar el dep�sito
			baseDatosBanco.abonar(obtenerNumeroCuenta(), monto);
		} 
		else // no se recibi� el sobre de dep�sito
		{
			pantalla.mostrarLineaMensaje("\nUsted no inserto un "
				"sobre, por lo que el ATM cancelo su transaccion.");
		} 
	} 
	else // el usuario cancel� en vez de introducir el monto
	{
		pantalla.mostrarLineaMensaje("\nCancelando la transaccion...");
	} // fin de else
} // fin de la funci�n ejecutar

  // pide al usuario que introduzca un monto a depositar en centavos
double Deposito::pedirMontoADepositar() const
{
	Pantalla &pantalla = obtenerPantalla(); // obtiene referencia a la pantalla

											// muestra el indicador y recibe la entrada
	pantalla.mostrarMensaje("\nIntroduzca un monto a depositar en "
		"CENTAVOS (o 0 para cancelar): ");
	int entrada = teclado.obtenerEntrada(); // recibe la entrada del monto a depositar

											// comprueba si el usuario cancel� o introdujo un monto v�lido
	if (entrada == CANCELO)
		return CANCELO;
	else
	{
		return  (double)(entrada) / 100; // devuelve el monto en d�lares 
	} 
} 
