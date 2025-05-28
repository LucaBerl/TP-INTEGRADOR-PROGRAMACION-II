#include <iostream>
using namespace std;
#include "clientesManager.h"
#include "clientes.h"
#include "clientesArchivo.h"
#include <ctime>
#include <conio.h>
#include <iomanip>
#include "clientesManager.h"


void clientesManager::mostrarTodos(){
{


    clientesArchivo clientArchivo;
    Clientes clientes;
    cout << left << fixed << setprecision(0);

  /*
  int _idCliente;
  char _nombre_RazonSocial[50];
  char _direccion[50];
  char _telefono[15];
  char _email[50];
  int _cantidadViajesRealizados;


  */

    system("cls");

    cout << left;
    cout << setw(6) << "ID"
    << setw(15) << "RAZON SOCIAL / NOMBRE   "
    << setw(15) << "DIRECCION"
    << setw(15) << "TELEFONO"
    << setw(10) << "EMAIL"
    << setw(10) << "CANTIDAD VIAJES REALIZADOS";


    cout << endl << "----------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = clientArchivo.getCantidadClientes();

    for(int i = 0;i < cantidadRegistros; i++){

        if(clientArchivo.leerClientes(i,clientes)){
              clientes.mostrar();
                cout << endl;
            }else{cout << "Lectura incorrecta";}

   }

    cout << endl << endl;
    system("pause");
}


}

void clientesManager::altaCliente(){



    system("cls");

    Clientes cliente; //crea el objeto llamando al constructor vacio
    clientesArchivo clienteArchivo;




    int id, cantidadViajesRealizados;
    string nombreRazonsocial, direccion, telefono,email;
    bool validacion;


///ALTA CHOFER//////////////////////////////////////////////////////////////

    cout<< endl << "ALTA CLIENTE";

///ID///////////////////////////////////////////////////////////////////////

//    while (true)
//    {
//        cout << endl << endl << "Ingresar ID: ";
//        cin >> id;
//        if (cin.fail())
//        {
//            cin.clear(); // Limpia el estado de error
//            cin.ignore(1000, '\n'); // Descarta el resto de la línea
//            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
//            continue;
//        }
//        if (choferes.set_id(id))
//        {
//            cout << " Guardado correcto ✔" << endl;
//            cin.ignore(1000, '\n'); // Por si quedan residuos
//
//            break; // Salir del bucle, entrada válida
//        }
//        else
//        {
//            cout << "ID invalido." << endl;
//        }
//    }

/// Creacion de ID automatica

    cliente.set_IdCliente(clienteArchivo.get_ultimoID());

    cin.ignore();


///Razon social//////////////////////////////////////////////////////

    do
    {
        cout << endl << endl << "Ingresar Razon social o nombre : ";
        getline(cin, nombreRazonsocial);

        validacion = cliente.set_Nombre_RazonSocial(nombreRazonsocial);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Nombre inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///direccion//////////////////////////////////////////////////

    do
    {
        cout << endl << endl << "Ingresar direccion: ";
        getline(cin, direccion);

        validacion = cliente.set_Direccion(direccion);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Direccion inválida, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///Telefono////////////////////////////////////////

     do
    {
        cout << endl << endl << "Ingresar Telefono: ";
        getline(cin, telefono);

        validacion = cliente.set_Telefono(telefono);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Telefono inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///Email//////////////////////////////////////

    do
    {
        cout << endl << endl << "Ingresar Email: ";
        getline(cin, email);

        validacion = cliente.set_Email(email);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Apellido inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///RESUMEN///////////////////////////////////////

    cout << "RESUMEN" << endl;

    cout << endl << "ID: " << cliente.get_idCliente();

    cout << endl << "Razon social / Nombre " << cliente.get_Nombre_RazonSocial();

    cout << endl << "Direccion " << cliente.get_Direccion();

    cout << endl << "Telefono " <<cliente.get_Telefono();

    cout << endl << "Email " << cliente.get_Email();



///CONFIRMACION Y GUARDADO//////////////////////////////////


    cout << endl << endl << "Confirmar alta de Cliente";

    int opcion;

    do
    {
        cout << endl << "1 - Confirmar";
        cout << endl << "2 - Volver a ingresar" << endl;
        cout << endl;
        cin >> opcion;
    }
    while (opcion != 1 && opcion != 2);

    if (opcion == 1)
    {
        if(clienteArchivo.guardarCliente( cliente))
        {
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl;

        }
    }
    else
    {
        return;
    }





}


/*
bool  clientesManager::validacion( string parametro){

while (true)
    {
        cout << endl << endl << "Ingresar: " parametro;
        cin >> parametro;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (choferes.set_experiencia(experiencia))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "Invalido." << endl;
        }
    }



}

*/
void clientesManager::bajaCliente(){}

bool clientesManager::actualizarCliente(){}
