#include <iostream>
using namespace std;
#include <conio.h>
#include "menuUsuarios.h"
#include "../Usuarios/usuariosManager.h"

void menuUsuarios::mostrar(int &rol){

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
    cout << "ESC. SALIR" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese una opcion: ";

    opcion = getch();

    switch(opcion) {
            case '1':
                if (rol == 1){
                    uManager.crearUsuario();
                }else{
                    system("cls");
                    cout << endl << "Acceso restringido, no posee los permisos 🔒" << endl << endl;
                    system("pause");
                }
                break;
            case '2':
                if(rol == 1){
                    uManager.bajaUsuario();
                }else{
                    system("cls");
                    cout << endl << "Acceso restringido, no posee los permisos 🔒" << endl << endl;
                    system("pause");
                }
                break;
            case '3':
                if (rol == 1){
                    uManager.cambiarRol();
                }else{
                    system("cls");
                    cout << endl << "Acceso restringido, no posee los permisos 🔒" << endl << endl;
                    system("pause");
                }
                break;
            case '4':
                uManager.listarUsuarios();
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
