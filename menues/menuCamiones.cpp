#include <iostream>
using namespace std;
#include "menuCamiones.h"
#include "../camiones/camionesManager.h"
#include <conio.h>
#include <windows.h>

void menuCamiones::mostrar(int &rol){

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA/BAJA/ACTUALIZACIÓN" << endl;
    cout << "2. LISTADOS/REPORTES" << endl;
    cout << endl;
    cout << "ESC. VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                if (rol == 1){
                    menu_abm();
                }else{
                    system("cls");
                    cout << endl << "Acceso restringido 🔒🔒" << endl << endl;
                    system("pause");
                }
                break;
            case '2':
                menu_listados();
                break;
            case 27:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 27);



}

void menuCamiones::menu_abm(){


    camionesManager caManager;

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
    cout << "=======================================" << endl;
    cout << "1. ALTA NUEVO CAMION" << endl;
    cout << "2. BAJA CAMION" << endl;
    cout << "3. ACTUALIZAR VERIFICACION" << endl;
    cout << endl;
    cout << "ESC. VOLVER AL MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                caManager.altaCamion();
                break;
            case '2':
                caManager.bajaCamion();
                break;
            case '3':
                caManager.modificarVerificacion();
                break;
            case 27:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 27);
}

void menuCamiones::menu_listados(){


    camionesManager caManager;

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "        LISTADOS DE CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "1. LISTAR TODOS" << endl;
    cout << "2. LISTAR EN VIAJE" << endl;
    cout << "3. LISTAR DISPONIBLES PARA ASIGNAR A CHOFER" << endl;
    cout << "4. LISTAR CAMIONES POR ANTIGÜEDAD" << endl;
    cout << "5. INFORMAR CANTIDAD DE KM POR CAMION" << endl;
    cout << "6. INFORMAR ESTADO DE VERIFICACIONES" << endl;
    cout << endl;
    cout << "ESC. VOLVER AL MENÚ CAMIONES" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                caManager.listarTodos();
                break;
            case '2':
                caManager.listarEnViaje();
                break;
            case '3':
                caManager.listarSinAsignar();
                break;
            case '4':
                caManager.mostrarPorAntiguedad();
                break;
            case '5':
                caManager.mostrarKmPorCamion();
                break;
            case '6':
                caManager.mostrarVerificaciones();
                break;
            case 27:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 27);

}

