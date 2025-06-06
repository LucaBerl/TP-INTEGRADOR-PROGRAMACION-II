#include <iostream>
using namespace std;
#include <conio.h>
#include "menuUsuarios.h"
#include "../Usuarios/usuariosManager.h"

void menuUsuarios::mostrar(){

    system("cls");

    usuariosManager uManager;

    char opcion;

    do{
    system("cls");
    cout << "=======================================" << endl;
    cout << "     USUARIOS" << endl;
    cout << "=======================================" << endl;
    cout << "1. CREAR USUARIO" << endl;
    cout << "2. ELIMINAR USUARIO" << endl;
    cout << "3. CAMBIAR ROL DE USUARIO" << endl;
    cout << "4. MOSTRAR USUARIOS" << endl;
    cout << endl;
    cout << "5. SALIR" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                uManager.crearUsuario();
                break;
            case '2':
                uManager.validarUsuario();
                break;
            case '3':

                break;

            case '4':
                uManager.listarUsuarios();
                break;
            case '5':
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != '5');
}
