/**
 * @version 1.0
 * @date 21/01/2025
 * @autor "Alejandro y Danny"
 * @name CajeroATM
 */

#include <iostream>

using namespace std;

/**
 * @class Cuenta
 * @brief Representa una cuenta bancaria con autenticación y operaciones básicas.
 */
class Cuenta {
private:
    int numeroCuenta; ///< Número de cuenta del usuario.
    int pin; ///< PIN de seguridad para autenticación.
    double saldo; ///< Saldo disponible en la cuenta.

public:
    /**
     * @brief Constructor de la clase Cuenta.
     * 
     * Inicializa una cuenta con un número de cuenta, un PIN y un saldo inicial.
     * 
     * @param numeroCuenta Número de cuenta del usuario. Valor por defecto: 0.
     * @param pin PIN de la cuenta. Valor por defecto: 0.
     * @param saldo Saldo inicial de la cuenta. Valor por defecto: 0.
     */
    Cuenta(int numeroCuenta = 0, int pin = 0, double saldo = 0) 
        : numeroCuenta(numeroCuenta), pin(pin), saldo(saldo) {}

    /**
     * @brief Verifica si el PIN ingresado es correcto.
     * 
     * @param pinIngresado PIN ingresado por el usuario.
     * @return true si el PIN es correcto, false en caso contrario.
     */
    bool verificarPin(int pinIngresado) {
        return pin == pinIngresado;
    }

    /**
     * @brief Realiza un depósito en la cuenta.
     * 
     * @param cantidad Monto a depositar en la cuenta.
     */
    void depositar(double cantidad) {
        saldo += cantidad;
        cout << "Depósito exitoso. Nuevo saldo: $" << saldo << endl;
    }

    /**
     * @brief Realiza un retiro de la cuenta, si hay fondos suficientes.
     * 
     * @param cantidad Monto a retirar de la cuenta.
     * @return true si el retiro fue exitoso, false si no hay fondos suficientes.
     */
    bool retirar(double cantidad) {
        if (cantidad > saldo) {
            cout << "Fondos insuficientes." << endl;
            return false;
        }
        saldo -= cantidad;
        cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
        return true;
    }

    /**
     * @brief Consulta el saldo actual de la cuenta.
     * 
     * @return Saldo disponible en la cuenta.
     */
    double consultarSaldo() {
        return saldo;
    }

    /**
     * @brief Obtiene el número de cuenta del usuario.
     * 
     * @return Número de cuenta.
     */
    int obtenerNumeroCuenta() {
        return numeroCuenta;
    }
}