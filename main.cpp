/**
 * @version 1.0
 * @date 21/01/2025
 * @autor "Danny Rosas"
 * @name CajeroATM
 */

#include <iostream>
#include "banco.h"

using namespace std;

/**
 * @brief Función principal del programa.
 * 
 * Crea una instancia del banco y del cajero automático. Luego, solicita al usuario
 * su número de cuenta y PIN para autenticarse. Si la autenticación es exitosa, se 
 * muestra el menú de operaciones disponibles.
 * 
 * @return 0 si la ejecución es exitosa.
 */
int main() {
    Banco banco; ///< Instancia de la clase Banco que gestiona las cuentas bancarias.
    CajeroAutomatico cajero(banco); ///< Instancia de la clase CajeroAutomatico para la interacción del usuario.

    int numeroCuenta; ///< Número de cuenta ingresado por el usuario.
    int pin; ///< PIN ingresado por el usuario.

    cout << "Ingrese su número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese su PIN: ";
    cin >> pin;

    /**
     * @brief Proceso de autenticación del usuario.
     * 
     * Se verifica si el número de cuenta y el PIN ingresados son correctos.
     * Si la autenticación es exitosa, se muestra el menú de opciones del cajero.
     */
    if (cajero.autenticar(numeroCuenta, pin)) {
        cajero.mostrarMenu();
    } else {
        cout << "Autenticación fallida. Intente de nuevo." << endl;
    }

    return 0;
}