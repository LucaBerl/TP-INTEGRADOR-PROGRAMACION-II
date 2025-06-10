#include <iostream>
#include "menues/menuPrincipal.h"
#include <windows.h>
#include <ctime>
#include "viajes/viajesManager.h"
#include "Clientes/ClientesArchivo.h"
#include "Usuarios/usuariosManager.h"
using namespace std;



int main()
{

    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    usuariosManager uManager;
    int rol = uManager.validarUsuario();

    if (rol == 0){
        return 0;
    }

    viajesManager vManager;
    if(!vManager.actualizarEstados()){
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return -1;
    }

    menuPrincipal mp;


    mp.mostrar(rol);


    return 0;
}

/// Pendientes :

/// -Terminar choferes (principalmente el alta, los listados pueden venir despues) (Listo)
/// -Asignacion de camiones a los choferes (Listo)
/// -Terminar viajes con la asignacion de choferes (Listo)
/// -Si damos de baja un camion con chofer, el chofer debe quedar sin asignacion y viceversa. (Listo)
/// -La actualizacion de verificacion tambien tiene que hacerse en los camiones asignados a choferes. (Listo)

/// -Actualizar estados de viaje para chofere y camiones (Listo)
/// -Asignar la actualizacion de viaje en los menues (Listo)
/// -Agregar kilometros recorridos en choferes y camiones despues de guardar cada viaje (Listo)
/// -Ver kilometros (Listo)
/// -Informar estado de licencias y actualizar licencias en seccion choferes (Listo)
/// -Clase clientes y acoplar
/// -Clase Usuarios (Listo)


