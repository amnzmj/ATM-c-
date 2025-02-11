#include <iostream>

using namespace std;

class Cuenta {
private:
    int numeroCuenta;   
    int pin;            
    double saldo;       

public:
    Cuenta(int numCuenta = 0, int pass = 0, double balance = 0) {
        numeroCuenta = numCuenta;
        pin = pass;
        saldo = balance;
    }

    bool verificarPin(int pinIngresado) {
        if (pin == pinIngresado) {
            return true;
        }
        return false;
    }

    void depositar(double cantidad) {
        saldo = saldo + cantidad;
        cout << "Se ha depositado la cantidad de $" << cantidad << ". Saldo actual: $" << saldo << endl;
    }

    bool retirar(double cantidad) {
        if (cantidad > saldo) {
            cout << "No tiene suficientes fondos para realizar este retiro." << endl;
            return false;
        }
        saldo = saldo - cantidad;
        cout << "Se ha retirado $" << cantidad << ". Saldo restante: $" << saldo << endl;
        return true;
    }

    double obtenerSaldo() {
        return saldo;
    }

    int obtenerNumeroCuenta() {
        return numeroCuenta;
    }
};

class Banco {
private:
    Cuenta cuentas[5];   

public:
    Banco() {
        cuentas[0] = Cuenta(1111, 1234, 100.0);
        cuentas[1] = Cuenta(2222, 5678, 200.0);
        cuentas[2] = Cuenta(3333, 4321, 300.0);
        cuentas[3] = Cuenta(4444, 8765, 400.0);
        cuentas[4] = Cuenta(5555, 9876, 500.0);
    }

    Cuenta* obtenerCuenta(int numeroCuenta) {
        for (int i = 0; i < 5; i++) {
            if (cuentas[i].obtenerNumeroCuenta() == numeroCuenta) {
                return &cuentas[i];
            }
        }
        cout << "No se encontró la cuenta solicitada." << endl;
        return nullptr;
    }
};

class CajeroAutomatico {
private:
    Banco *banco;      
    Cuenta *cuentaActual;
    bool autenticado;

public:
    CajeroAutomatico(Banco *bancoRef) {
        banco = bancoRef;
        cuentaActual = nullptr;
        autenticado = false;
    }

    bool autenticar(int numeroCuenta, int pin) {
        Cuenta *cuenta = banco->obtenerCuenta(numeroCuenta);
        if (cuenta != nullptr && cuenta->verificarPin(pin)) {
            cuentaActual = cuenta;
            autenticado = true;
            return true;
        }
        return false;
    }

    void mostrarMenu() {
        if (!autenticado) {
            cout << "Debe autenticarse primero." << endl;
            return;
        }

        int opcion;
        do {
            cout << "\n### Menú de Cajero Automático ###" << endl;
            cout << "1. Consultar saldo" << endl;
            cout << "2. Realizar depósito" << endl;
            cout << "3. Realizar retiro" << endl;
            cout << "4. Salir" << endl;
            cout << "Seleccione una opción: ";
            cin >> opcion;

            if (opcion == 1) {
                cout << "Saldo actual: $" << cuentaActual->obtenerSaldo() << endl;
            } else if (opcion == 2) {
                double cantidad;
                cout << "¿Cuánto desea depositar? ";
                cin >> cantidad;
                cuentaActual->depositar(cantidad);
            } else if (opcion == 3) {
                double cantidad;
                cout << "¿Cuánto desea retirar? ";
                cin >> cantidad;
                bool exito = cuentaActual->retirar(cantidad);
                if (!exito) {
                    cout << "Operación fallida." << endl;
                }
            } else if (opcion == 4) {
                cout << "Gracias por usar el cajero automático. Adiós." << endl;
            } else {
                cout << "Opción no válida. Intente de nuevo." << endl;
            }
        } while (opcion != 4);
    }
};

int main() {
    Banco banco;
    CajeroAutomatico cajero(&banco);
    int numeroCuenta, pin;
    cout << "Por favor ingrese su número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese su PIN: ";
    cin >> pin;

    if (cajero.autenticar(numeroCuenta, pin)) {
        cajero.mostrarMenu();
    } else {
        cout << "Autenticación fallida. El número de cuenta o PIN es incorrecto." << endl;
    }

    return 0;
}
