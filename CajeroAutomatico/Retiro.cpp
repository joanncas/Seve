#include "stdafx.h"
#include "Retiro.h" // Definici�n de la clase Retiro
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco
#include "Teclado.h" // Definici�n de la clase Teclado
#include "DispensadorEfectivo.h" // Definici�n de la clase DispensadorEfectivo

// constante global que corresponde a la opci�n del men� para cancelar
const static int CANCELO = 6;

// el constructor de Retiro inicializa los miembros de datos de la clase
Retiro::Retiro(int numeroCuentaUsuario, Pantalla &pantallaATM,
	BaseDatosBanco &baseDatosBancoATM, Teclado &tecladoATM,
	DispensadorEfectivo &dispensadorEfectivoATM)
	: Transaccion(numeroCuentaUsuario, pantallaATM, baseDatosBancoATM),
	teclado(tecladoATM), dispensadorEfectivo(dispensadorEfectivoATM)
{

} // fin del constructor de Retiro

  // realiza una transacci�n; sobrescribe la funci�n virtual pura de Transaccion
void Retiro::ejecutar()
{
	bool efectivoDispensado = false; // no se ha dispensado todav�a el efectivo
	bool transaccionCancelada = false; // no se ha cancelado todav�a la transacci�n

									   // obtiene referencias a la base de datos del banco y la pantalla
	BaseDatosBanco &baseDatosBanco = obtenerBaseDatosBanco();
	Pantalla &pantalla = obtenerPantalla();

	// hasta que se dispensa el efectivo o hasta que el usuario cancela
	do
	{
		// obtiene el monto de retiro elegido del usuario 
		int seleccion = mostrarMenuDeMontos();

		// comprueba si el usuario eligi� un monto de retiro o cancel�
		if (seleccion != CANCELO)
		{
			monto = seleccion; // establece monto con el monto en d�lares seleccionado

							   // obtiene el saldo disponible de la cuenta involucrada
			double saldoDisponible =
				baseDatosBanco.obtenerSaldoDisponible(obtenerNumeroCuenta());

			// comprueba si el usuario tiene suficiente dinero en la cuenta 
			if (monto <= saldoDisponible)
			{
				// comprueba si el dispensador de efectivo tiene suficiente dinero
				if (dispensadorEfectivo.haySuficienteEfectivoDisponible(monto))
				{
					// actualiza la cuenta involucrada para reflejar el retiro
					baseDatosBanco.cargar(obtenerNumeroCuenta(), monto);

					dispensadorEfectivo.dispensarEfectivo(monto); // dispensa el efectivo
					efectivoDispensado = true; // se dispens� el efectivo

											   // instruye al usuario para que tome el efectivo
					pantalla.mostrarLineaMensaje(
						"\nPor favor tome su efectivo del dispensador de efectivo.");
				} 
				else // el dispensador de efectivo no tiene suficiente efectivo
					pantalla.mostrarLineaMensaje(
						"\nNo hay suficiente efectivo disponible en el ATM."
						"\n\nElija un monto menor.");
			} 
			else // no hay suficiente dinero en la cuenta del usuario
			{
				pantalla.mostrarLineaMensaje(
					"\nNo hay suficientes fondos en su cuenta."
					"\n\nElija un monto menor.");
			} 
		} 
		else 
		{
			pantalla.mostrarLineaMensaje("\nCancelando la transaccion...");
			transaccionCancelada = true; // el usuario cancel� la transacci�n
		} 
	} while (!efectivoDispensado && !transaccionCancelada); 
} 

  // muestra un men� de montos de retiro y la opci�n para cancelar;
  // devuelve el monto elegido o 0 si el usuario opt� por cancelar
int Retiro::mostrarMenuDeMontos() const
{
	int opcionUsuario = 0; 

	Pantalla &pantalla = obtenerPantalla(); // obtiene la referencia a la pantalla

											// arreglo de montos que corresponden a los n�meros del men�
	int montos[] = { 0, 20, 40, 60, 100, 200 };

	
	while (opcionUsuario == 0)
	{

		pantalla.mostrarLineaMensaje("\nOpciones de retiro:");
		pantalla.mostrarLineaMensaje("1 - $20");
		pantalla.mostrarLineaMensaje("2 - $40");
		pantalla.mostrarLineaMensaje("3 - $60");
		pantalla.mostrarLineaMensaje("4 - $100");
		pantalla.mostrarLineaMensaje("5 - $200");
		pantalla.mostrarLineaMensaje("6 - Cancelar transaccion");
		pantalla.mostrarMensaje("\nElija una opcion de retiro (1-6): ");

		int entrada = teclado.obtenerEntrada(); // obtiene la entrada del usuario a trav�s del teclado

												
		switch (entrada)
		{
		case 1: // si el usuario eligi� un monto de retiro 
		case 2: // (es decir, si eligi� la opci�n 1, 2, 3, 4 o 5), devuelve
		case 3: // el monto correspondiente del arreglo montos
		case 4:
		case 5:
			opcionUsuario = montos[entrada]; // guarda la opci�n del usuario
			break;
		case CANCELO: // el usuario eligi� cancelar
			opcionUsuario = CANCELO; // guarda la opci�n del usuario
			break;
		default: // el usuario no introdujo un valor entre 1 y 6
			pantalla.mostrarLineaMensaje(
				"\nSeleccion invalida. Intente de nuevo.");
		} 
	} 

	return opcionUsuario; // devuelve monto de retiro o CANCELO
} 
