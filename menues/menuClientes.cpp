#include <iostream>
using namespace std;
#include "menuClientes.h"
#include "../Clientes/ClientesManager.h"
#include <conio.h>
#include <windows.h>

void menuClientes::mostrar(){

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        MENÚ CLIENTES" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA/BAJA/ACTUALIZACIÓN" << endl;
    cout << "2. LISTADOS" << endl;
    cout << "3. LISTADOS" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                menu_abm();
                break;
            case '2':
                menulistados();
                break;
            case '3':
                menulistados();
                break;
            case '4':
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != '4');



}

void menuClientes::menu_abm(){


   clientesManager clientManager;

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA NUEVO CLIENTE" << endl;
    cout << "2. BAJA CLIENTE" << endl;
    cout << "3. ACTUALIZAR CLIENTE" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ CLIENTES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                clientManager.altaCliente();
                break;
            case '2':
                clientManager.bajaCliente();
                break;
            case '3':
                clientManager.actualizarCliente();
                break;
            case '4':
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != '4');
}


void menuClientes::menulistados(){


    clientesManager clientManager;

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        LISTADOS DE CLIENTES" << endl;
    cout << "=======================================" << endl;
    cout << "1. LISTAR TODOS" << endl;
    cout << "2. LISTAR EN VIAJE" << endl;
    cout << "3. LISTAR DISPONIBLES INACTIVOS" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ CLIENTES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':

                break;
            case '2':

                break;
            case '3':

                break;
            case '4':
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != '4');

}
