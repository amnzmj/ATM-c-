/**
 * @file main.cpp
 * @brief Programa principal para la simulación de un cajero automático.
 * 
 * Este programa permite a un usuario autenticarse en un cajero automático 
 * y realizar operaciones bancarias mediante la interacción con un objeto 
 * de la clase CajeroAutomatico.
 *
 * @version 1.0
 * @date 21/01/2025
 * @author Danny Rosas
 */

#include <iostream>
#include "banco.h"

using namespace std;

/**
 * @brief Función principal del programa.
 * 
 * Crea una instancia de Banco y CajeroAutomatico. Luego, solicita al usuario
 * su número de cuenta y PIN para autenticarse. Si la autenticación es exitosa, 
 * permite al usuario interactuar con el menú del cajero automático.
 * 
 * @return 0 Indica que el programa finalizó correctamente.
 */
int main() {
    Banco banco; ///< Instancia de Banco que gestiona las cuentas bancarias.
    CajeroAutomatico cajero(banco); ///< Instancia de CajeroAutomatico para la interacción con el usuario.

    int numeroCuenta; ///< Almacena el número de cuenta ingresado por el usuario.
    int pin; ///< Almacena el PIN ingresado por el usuario.

    cout << "Ingrese su número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese su PIN: ";
    cin >> pin;

    /**
     * @brief Proceso de autenticación del usuario.
     * 
     * Se verifica si el número de cuenta y el PIN ingresados son correctos.
     * Si la autenticación es exitosa, se muestra el menú de opciones del cajero.
     * De lo contrario, se muestra un mensaje de error.
     */
    if (cajero.autenticar(numeroCuenta, pin)) {
        cajero.mostrarMenu(); ///< Muestra el menú del cajero si la autenticación es correcta.
    } else {
        cout << "Autenticación fallida. Intente de nuevo." << endl;
    }

    return 0;
}