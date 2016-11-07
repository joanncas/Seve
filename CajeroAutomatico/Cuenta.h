#pragma once
#ifndef CUENTA_H
#define CUENTA_H

class Cuenta
{
public:
	Cuenta(int, int, double, double); // el constructor establece los atributos
	bool validarNIP(int) const; // ¿es correcto el NIP especificado por el usuario?
	double obtenerSaldoDisponible() const; // devuelve el saldo disponible
	double obtenerSaldoTotal() const; // devuelve el saldo total
	void abonar(double); // suma un monto al saldo de la Cuenta
	void cargar(double); // resta un monto del saldo de la Cuenta
	int obtenerNumeroCuenta() const; // devuelve el número de cuenta
private:
	int numeroCuenta; // número de cuenta
	int nip; // NIP para autenticación
	double saldoDisponible; // fondos disponibles para retirar
	double saldoTotal; // fondos disponibles + fondos esperando ser verificados
}; 

#endif // CUENTA_H