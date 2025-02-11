void CajeroAutomatico::mostrarMenu() {
    if (!cuentaActual) {
        cout << "Debe autenticarse primero." << endl;
        return;
    }

    int opcion;
    do {
        cout << "\Menu:" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
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
                cout << "Gracias por usar el cajero automatico." << endl;
                break;
            default:
                cout << "Opcionn no valida." << endl;
        }
    } while (opcion != 4);
}
