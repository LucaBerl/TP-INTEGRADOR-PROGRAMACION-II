#include <iostream>
#include "menues/menuPrincipal.h"
#include <windows.h>

#include "Clientes/ClientesArchivo.h"
using namespace std;



int main()
{

    menuPrincipal mp;


    mp.mostrar();




    return 0;
}

/// Pendientes :

/// -Terminar choferes (principalmente el alta, los listados pueden venir despues) V
/// -Asignacion de camiones a los choferes V
/// -Terminar viajes con la asignacion de choferes
/// -Clase clientes y acoplar
/// -Clase Usuarios

/// si damos de baja un camion con chofer, el chofer debe quedar sin asignacion y viceversa.
/// la actualizacion de verificacion tambien tiene que hacerse en los camiones asignados a choferes. V
