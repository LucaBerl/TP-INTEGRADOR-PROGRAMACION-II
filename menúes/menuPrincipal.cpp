#include <iostream>
using namespace std;
#include "menuPrincipal.h"
#include "menuViajes.h"
#include "menuChoferes.h"
#include "menuCamiones.h"


void menuPrincipal::mostrar(){
    
    system("cls");
    
    menuViajes menuV;
    menuChoferes menuCh;
    menuCamiones menuCa;
    int opcion;
    
    do{
    cout << "========================================================" << endl;
    cout << "        SISTEMA GESTION DE LOGISTICA" << endl;
    cout << "========================================================" << endl;
    cout << "1. VIAJES" << endl;
    cout << "2. CHOFERES" << endl;
    cout << "3. CAMIONES" << endl;
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

    } while(opcion != 4);
}
