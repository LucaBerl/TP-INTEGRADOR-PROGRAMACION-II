#include <iostream>
using namespace std;
#include "menuClientes.h"
#include "../Clientes/clientesManager.h"

void menuClientes::mostrar(){

    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        MENÚ CLIENTES" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA/BAJA/ACTUALIZACIÓN" << endl;
    cout << "2. LISTADOS/REPORTES" << endl;
    cout << endl;
    cout << "3. VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                menu_abm();
                break;
            case 2:
              //  menu_listados();
                break;
            case 3:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 3);
}

void menuClientes::menu_abm(){


    clientesManager clientManager;

    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA NUEVO CLIENTE" << endl;
    cout << "2. BAJA CLIENTE" << endl;
    cout << "3. ACTUALIZAR CLIENTE" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ CLIENTE" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                clientManager.altaCliente();
                break;
            case 2:
              //  caManager.bajaCamion();
                break;
            case 3:
               // caManager.modificarVerificacion();
                break;
            case 4:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 4);
}
