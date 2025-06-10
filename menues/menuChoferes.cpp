#include "menuChoferes.h"
#include "../choferes/choferesManager.h"
#include <iostream>
using namespace std;
#include <conio.h>
#include <windows.h>

void menuChoferes::mostrar(int &rol)
{
    choferesManager cManager;
    char opcion;
    do
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "        MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "1. ALTA/BAJA/ACTUALIZACIÓN" << endl;
        cout << "2. LISTADOS/REPORTES" << endl;
        cout << "3. ASIGNAR CAMIÓN" << endl;
        cout << "4. DESASIGNAR CAMIÓN" << endl;
        cout << endl;
        cout << "ESC. VOLVER AL MENÚ PRINCIPAL" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            if (rol == 1)
            {
                menu_abm();
            }
            else
            {
                system("cls");
                cout << endl << "Acceso restringido, no posee los permisos 🔒" << endl << endl;
                system("pause");
            }
            break;
        case '2':
            menu_listados();
            break;
        case '3':
            cManager.asignarCamion();
            break;
        case '4':
            cManager.desasignarCamion();
            break;
        case 27:
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != 27);
}

void menuChoferes::menu_abm()
{




    char opcion;
    choferesManager cManager;
    do
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
        cout << "=======================================" << endl;
        cout << "1. ALTA NUEVO CHOFER" << endl;
        cout << "2. BAJA CHOFER" << endl;
        cout << "3. ACTUALIZAR LICENCIA" << endl;
        cout << endl;
        cout << "ESC. VOLVER AL MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            cManager.cargarChofer();
            break;
        case '2':
            cManager.bajaChofer();
            break;
        case '3':
            cManager.modificarLicencia();
            break;
        case 27:
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != 27);
}

void menuChoferes::menu_listados()
{



    choferesManager cManager;
    char opcion;

    do
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "        LISTADOS" << endl;
        cout << "=======================================" << endl;
        cout << "1. LISTAR TODOS" << endl;
        cout << "2. LISTAR EN VIAJE" << endl;
        cout << "3. LISTAR CHOFERES SIN CAMION" << endl; //ESTABA LISTAR DISPONIBLES, PERO ESTE TITULO SE ENTIENDE MEJOR LO QUE HACE LA FUNCION
        cout << "4. LISTAR CHOFERES CON CAMIÓN" << endl;
        cout << "5. INFORMAR CANTIDAD DE KM POR CHOFER" << endl;
        cout << "6. INFORMAR ESTADO DE LICENCIAS" << endl; //ESTABA HORAS MANEJADAS, PERO ES DIFICIL.
        cout << endl;
        cout << "ESC. VOLVER AL MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            cManager.listarTodos();
            break;
        case '2':
            cManager.listarEnViaje();
            break;
        case '3':
            cManager.listarSinCamion();
            break;
        case '4':
            cManager.listarConCamion();
            break;
        case '5':
            cManager.mostrarKmPorChofer();
            break;
        case '6':
            cManager.mostrarLicencias();
            break;
        case 27:
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != 27);

}

