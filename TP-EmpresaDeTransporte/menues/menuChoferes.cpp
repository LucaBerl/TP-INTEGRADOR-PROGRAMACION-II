#include "menuChoferes.h"
#include "../choferes/choferesManager.h"
#include <iostream>
using namespace std;
#include <conio.h>
#include <windows.h>

void menuChoferes::mostrar()
{
    choferesManager cManager;
    char opcion;
    do
    {
        system("cls");
        cout << "=======================================" << endl;
        cout << "        MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "1. ALTA/BAJA/MODIFICACIÓN" << endl;
        cout << "2. LISTADOS/REPORTES" << endl;
        cout << "3. ASIGNAR CAMIÓN" << endl;
        cout << endl;
        cout << "4. VOLVER AL MENÚ PRINCIPAL" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            menu_abm();
            break;
        case '2':
            menu_listados();
            break;
        case '3':
            // cManager.asignarCamion();
            break;
        case '4':
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != '4');
}

void menuChoferes::menu_abm()
{

    system("cls");


    char opcion;
    choferesManager cManager;
    do
    {
        cout << "=======================================" << endl;
        cout << "        ALTA/BAJA/MODIFICACIÓN" << endl;
        cout << "=======================================" << endl;
        cout << "1. ALTA NUEVO CHOFER" << endl;
        cout << "2. BAJA CHOFER" << endl;
        cout << "3. MODIFICAR CHOFER" << endl;
        cout << endl;
        cout << "4. VOLVER AL MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            cManager.cargarChofer();
            break;
        case '2':
//            cManager.bajaChofer();
            break;
        case '3':
            //         cManager.modificarChofer();
            break;
        case '4':
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != '4');
}

void menuChoferes::menu_listados()
{

    system("cls");

    choferesManager cManager;
    char opcion;

    do
    {
        cout << "=======================================" << endl;
        cout << "        LISTADOS" << endl;
        cout << "=======================================" << endl;
        cout << "1. LISTAR TODOS" << endl;
        cout << "2. LISTAR EN VIAJE" << endl;
        cout << "3. LISTAR CHOFERES SIN CAMION" << endl; //ESTABA LISTAR DISPONIBLES, PERO ESTE TITULO SE ENTIENDE MEJOR LO QUE HACE LA FUNCION
        cout << "4. MOSTRAR CANTIDAD DE REGISTROS" << endl; //ESTE NO DEBERIA IR
        cout << "5. INFORMAR CANTIDAD DE KM POR CHOFER" << endl;
        cout << "6. INFORMAR ESTADO DE LICENCIAS" << endl; //ESTABA HORAS MANEJADAS, PERO ES DIFICIL.
        cout << endl;
        cout << "7. VOLVER AL MENÚ CHOFERES" << endl;
        cout << "=======================================" << endl;
        cout << "Ingrese una opción: ";

        opcion = getch();

        switch(opcion)
        {
        case '1':
            cManager.listarTodos();
            break;
        case '2':
//        cManager.listarEnViaje();
            break;
        case '3':
//        cManager.listarDisponibles();
            break;
        case '4':
//        cManager.mostrarCantidadRegistros();
            break;
        case '5':

            break;
        case '6':

            break;
        case '7':
            return;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

        cout << endl << endl;

    }
    while(opcion != '7');

}

//void menuChoferes::menu_informes()
//{
//
//    system("cls");
//
//    int opcion;
//
//    do
//    {
//        cout << "=======================================" << endl;
//        cout << "        INFORMES" << endl;
//        cout << "=======================================" << endl;
//        cout << "1. CANTIDAD DE KM POR CHOFER" << endl;
//        cout << "2. HORAS MANEJADAS POR CHOFER" << endl;
//        cout << endl;
//        cout << "3. VOLVER AL MENÚ CHOFERES" << endl;
//        cout << "=======================================" << endl;
//        cout << "Ingrese una opcion: ";
//
//        cin >> opcion;
//
//        switch(opcion)
//        {
//        case 1:
//
//            break;
//        case 2:
//
//            break;
//        case 3:
//            return;
//            break;
//        default:
//            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
//        }
//
//        cout << endl << endl;
//
//    }
//    while(opcion != 4);
//}
