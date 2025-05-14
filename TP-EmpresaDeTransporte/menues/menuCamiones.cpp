#include <iostream>
using namespace std;
#include "menuCamiones.h"
#include "../camiones/camionesManager.h"

void menuCamiones::mostrar(){

    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA/BAJA/MODIFICACIÓN" << endl;
    cout << "2. LISTADOS" << endl;
    cout << "3. INFORMES" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                menu_abm();
                break;
            case 2:
                menu_listados();
                break;
            case 3:
                menu_informes();
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

void menuCamiones::menu_abm(){


    camionesManager caManager;

    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA NUEVO CAMION" << endl;
    cout << "2. BAJA CAMION" << endl;
    cout << "3. MODIFICAR CAMION" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                caManager.altaCamion();
                break;
            case 2:

                break;
            case 3:

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

void menuCamiones::menu_listados(){




    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        LISTADOS" << endl;
    cout << "=======================================" << endl;
    cout << "1. LISTAR TODOS" << endl;
    cout << "2. LISTAR EN VIAJE" << endl;
    cout << "3. LISTAR DISPONIBLES" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

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

void menuCamiones::menu_informes(){



    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        INFORMES" << endl;
    cout << "=======================================" << endl;
    cout << "1. CANTIDAD DE KM POR CAMION" << endl;
    cout << "2. REGISTRO DE VERIFICACIONES" << endl;
    cout << endl;
    cout << "3. VOLVER AL MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 4);
}
