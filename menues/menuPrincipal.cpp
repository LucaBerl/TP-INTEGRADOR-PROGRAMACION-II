#include <iostream>
using namespace std;
#include "menuPrincipal.h"
#include "menuViajes.h"
#include "menuChoferes.h"
#include "menuCamiones.h"
#include "menuClientes.h"
#include "menuUsuarios.h"
#include <conio.h>



void menuPrincipal::mostrar(int &rol){

    system("cls");

    menuViajes menuV;
    menuChoferes menuCh;
    menuCamiones menuCa;
    menuClientes menuClient;
    menuUsuarios menuUs;



    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "     SISTEMA GESTION DE LOGISTICA" << endl;
    cout << "=======================================" << endl;
    cout << "1. VIAJES" << endl;
    cout << "2. CHOFERES" << endl;
    cout << "3. CAMIONES" << endl;
    cout << "4. CLIENTES" << endl;
    cout << "5. USUARIOS" << endl;
    cout << endl;
    cout << "6. SALIR" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                menuV.mostrar(rol);
                break;
            case '2':
                menuCh.mostrar(rol);
                break;
            case '3':
                menuCa.mostrar(rol);
                break;

            case '4':
                menuClient.mostrar(rol);
                break;
            case '5':
                menuUs.mostrar(rol);
                break;
            case '6':
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != '6');
}
