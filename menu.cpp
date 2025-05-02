#include <iostream>
using namespace std;
#include "menuViajes"
#include "menuChoferes"
#include "menuCamiones"


void menupPrincipal::mostrar(){

    menuViajes menuV
    menuChoferes menuCh
    menuCamiones menuCa
    int opcion;
    
    do{
    cout << "========================================================" << endl;
    cout << "        SISTEMA GESTION DE LOGISTICA" << endl;
    cout << "========================================================" << endl;
    cout << "1. VIAJES" << endl;
    cout << "2. CHOFERES" << endl;
    cout << "3. CAMIONESS" << endl;
    cout << "4. SALIR" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                menuV.mostrar();               
                break;
            case 2:
                menuCh.mostrar();
                break;
            case 3:
                menuCa.mostrar();
                break;       
            case 4:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 0);
}
