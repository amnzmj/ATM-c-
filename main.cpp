/**
 * @version 1.0
 * @date 21/01/2025
 * @autor "EQUIPO ADDJ"
 * @name CajeroATM
 */

#include <iostream>

using namespace std;

//---------------------------------------- ALEX Y DANI
class Cuenta {
private:
    int numeroCuenta;
    int pin;
    double saldo;

public:
    Cuenta(int numeroCuenta = 0, int pin = 0, double saldo = 0) : numeroCuenta(numeroCuenta), pin(pin), saldo(saldo) {}

    bool verificarPin(int pinIngresado) {
        return pin == pinIngresado;
    }

    void depositar(double cantidad) {
        saldo += cantidad;
        cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
    }

    bool retirar(double cantidad) {
        if (cantidad > saldo) {
            cout << "Fondos insuficientes." << endl;
            return false;
        }
        saldo -= cantidad;
        cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
        return true;
    }

    double consultarSaldo() {
        return saldo;
    }

    int obtenerNumeroCuenta() {
        return numeroCuenta;
    }
};

//-------------------------------------------------------- DIEGO
class Banco {
private:
    Cuenta cuentas[2];

public:
    Banco() {
        cuentas[0] = Cuenta(12345, 1111, 1000.0);
        cuentas[1] = Cuenta(67890, 2222, 500.0);
    }

    Cuenta* obtenerCuenta(int numeroCuenta) {
        for (int i = 0; i < 2; i++) {
            if (cuentas[i].obtenerNumeroCuenta() == numeroCuenta) {
                return &cuentas[i];
            }
        }
        return nullptr;
    }
};

class CajeroAutomatico {
private:
    Banco& banco;
    Cuenta* cuentaActual;

public:
    CajeroAutomatico(Banco& banco) : banco(banco), cuentaActual(nullptr) {}

    bool autenticar(int numeroCuenta, int pin) {
        Cuenta* cuenta = banco.obtenerCuenta(numeroCuenta);
        if (cuenta && cuenta->verificarPin(pin)) {
            cuentaActual = cuenta;
            return true;
        }
        return false;
    }


    //------------------------------------------------------ JAIR
    void mostrarMenu() {
        if (!cuentaActual) {
            cout << "Debe autenticarse primero." << endl;
            return;
        }

        int opcion;
        do {
            cout << "\nMenú:" << endl;
            cout << "1. Consultar saldo" << endl;
            cout << "2. Depositar" << endl;
            cout << "3. Retirar" << endl;
            cout << "4. Salir" << endl;
            cout << "Elija una opción: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "Saldo actual: $" << cuentaActual->consultarSaldo() << endl;
                break;
            case 2: {
                double cantidad;
                cout << "Ingrese la cantidad a depositar: ";
                cin >> cantidad;
                cuentaActual->depositar(cantidad);
                break;
            }
            case 3: {
                double cantidad;
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidad;
                cuentaActual->retirar(cantidad);
                break;
            }
            case 4:
                cout << "Gracias por usar el cajero automático." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
            }
        } while (opcion != 4);
    }
};


//----------------------------------------------------- DANI
int main() {
    Banco banco;
    CajeroAutomatico cajero(banco);
    int numeroCuenta, pin;
    cout << "Ingrese su número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese su PIN: ";
    cin >> pin;

    if (cajero.autenticar(numeroCuenta, pin)) {
        cajero.mostrarMenu();
    }
    else {
        cout << "Autenticación fallida. Intente de nuevo." << endl;
    }

    return 0;
}
