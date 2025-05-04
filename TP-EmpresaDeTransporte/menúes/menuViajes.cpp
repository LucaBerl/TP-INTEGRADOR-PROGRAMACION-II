#include <iostream>
using namespace std;
#include "menuViajes.h"

void menuViajes::mostrar(){




    int opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        MENÚ VIAJES" << endl;
    cout << "=======================================" << endl;
    cout << "1. CREAR NUEVO VIAJE" << endl;
    cout << "2. VIAJES ACTIVOS" << endl;
    cout << "3. HISTORIAL DE VIAJES" << endl;
    cout << endl;
    cout << "4. VOLVER AL MENÚ PRINCIPAL" << endl;
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
