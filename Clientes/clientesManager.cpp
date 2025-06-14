#include <iostream>
using namespace std;
#include "clientesManager.h"
#include "clientes.h"
#include "clientesArchivo.h"
#include <ctime>
#include <conio.h>
#include <iomanip>
#include "clientesManager.h"
#include "../viajes/viajesManager.h"
#include "../viajes/viajes.h"
#include "../viajes/viajesArchivo.h"


void clientesManager::mostrarTodos(){


clientesArchivo clientArchivo;
    Clientes clientes;

    system("cls");

    cout << left << fixed;

    // Encabezado alineado con los mismos setw que los datos
    cout << setw(5)  << "ID"
         << setw(30) << "RAZON SOCIAL / NOMBRE"
         << setw(30) << "DIRECCION"
         << setw(20) << "TELEFONO"
         << setw(25) << "EMAIL"
         << setw(10) << "VIAJES";

    cout << endl << string(120, '-') << endl;

    int cantidadRegistros = clientArchivo.getCantidadClientes();

    for (int i = 0; i < cantidadRegistros; i++) {
        if (clientArchivo.leerClientes(i, clientes)) {
            if (clientes.get_estado() == 1) {
                clientes.mostrar(1);
                cout << endl;
            }
        } else {
            cout << "Lectura incorrecta" << endl;
        }
    }

    cout << endl << endl;
    system("pause");



}

void clientesManager::altaCliente(){



    system("cls");

    Clientes cliente; //crea el objeto llamando al constructor vacio
    clientesArchivo clienteArchivo;




    int id, cantidadViajesRealizados;
    string nombreRazonsocial, direccion, telefono,email;
    bool validacion;


///ALTA CHOFER//////////////////////////////////////////////////////////////

    cout<< endl << "ALTA CLIENTE  (presiones enter para continuar )";



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
            cout << endl << "Nombre inválido, no cumple con el minimo o supera el maximo de caracteres. Intente de vuelta" << endl;
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
            cout << endl << "Direccion inválida, no cumple con el minimo o supera el maximo de caracteres. Intente nuevamente" << endl;
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
            cout << endl << "Apellido inválido, no cumple con el minimo o supera el maximo de caracteres. Intente nuevamente" << endl;
        }

    }
    while (!validacion);

///RESUMEN///////////////////////////////////////

    system("cls");

    cout << "RESUMEN" << endl;

    cout << endl << "ID: " << cliente.get_idCliente();

    cout << endl << "Cliente " << cliente.get_Nombre_RazonSocial();

    cout << endl << "Direccion  " << cliente.get_Direccion();

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
            system("pause");

        }
    }
    else
    {
        return;
    }






}
void clientesManager::bajaCliente(){

    system("cls");

  Clientes cliente;
  clientesArchivo clienteArchivo;

    int opcionNumerica;


      mostrarTodos();

    cout << endl << endl << "Por favor, seleccionar el ID del Cliente a dar de baja: ";

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion;
    int cantidadRegistros = clienteArchivo.getCantidadClientes();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(clienteArchivo.leerClientes(i,cliente)){
            if (cliente.get_idCliente()==opcionNumerica&& cliente.get_estado()==1){
                cliente.mostrar(1);
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea dar de baja este Cliente?";
                cout << endl << "1. SI" << endl << "2. NO" << endl;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado){
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){
             cliente.set_estado(0);
            if(clienteArchivo.guardarClienteModificado(posicion, cliente)){
                system("cls");
                cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;
                return;
            }else{
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }else if(opcionNumerica == 2){
            return;
        }

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


void clientesManager::actualizarCliente(){



    system("cls");

  Clientes cliente;
  clientesArchivo clienteArchivo;

    int opcionNumerica;


    int  cantidadViajesRealizados;
    string nombreRazonsocial, direccion, telefono,email;
    bool validacion;

      mostrarTodos();

    cout << endl << endl << "Por favor, seleccionar el ID del Cliente a modificar: ";

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion;
    int cantidadRegistros = clienteArchivo.getCantidadClientes();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(clienteArchivo.leerClientes(i,cliente)){
            if (cliente.get_idCliente()==opcionNumerica&& cliente.get_estado()==1){
                cliente.mostrar(1);
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea modificar el siguiente Cliente?";
                cout << endl << "1. SI" << endl << "2. NO" << endl;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado){
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){
           cin.ignore();
 /* do
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
*/
  int opcionCampo;
do {
    cout << "\nSeleccione el campo a modificar:\n";
    cout << "1. Nombre o Razon Social\n";
    cout << "2. Direccion\n";
    cout << "3. Telefono\n";
    cout << "4. Email\n";
    cout << "5. Finalizar modificaciones\n";
    cout << "Opcion: ";
    cin >> opcionCampo;
    cin.ignore();

    switch(opcionCampo) {
        case 1:
            do {
                cout << "\nNuevo Nombre o Razon Social: ";
                getline(cin, nombreRazonsocial);
                validacion = cliente.set_Nombre_RazonSocial(nombreRazonsocial);
                if (!validacion) cout << "Nombre inválido. Intente de nuevo.\n";
            } while (!validacion);
            break;

        case 2:
            do {
                cout << "\nNueva Direccion: ";
                getline(cin, direccion);
                validacion = cliente.set_Direccion(direccion);
                if (!validacion) cout << "Direccion inválida. Intente de nuevo.\n";
            } while (!validacion);
            break;

        case 3:
            do {
                cout << "\nNuevo Telefono: ";
                getline(cin, telefono);
                validacion = cliente.set_Telefono(telefono);
                if (!validacion) cout << "Telefono inválido. Intente de nuevo.\n";
            } while (!validacion);
            break;

        case 4:
            do {
                cout << "\nNuevo Email: ";
                getline(cin, email);
                validacion = cliente.set_Email(email);
                if (!validacion) cout << "Email inválido. Intente de nuevo.\n";
            } while (!validacion);
            break;

        case 5:
            cout << "\nFinalizando modificaciones...\n";
            break;

        default:
            cout << "Opcion invalida, intente otra vez.\n";
    }
} while (opcionCampo != 5);


            if(clienteArchivo.guardarClienteModificado(posicion, cliente)){
                system("cls");
                cout << " CLIENTE MODIFICADO CORRECTO ✔ " << endl << _getch() ;
                return  ;
            }else{
                cout << "Error en la modificacion del Cliente" << _getch() ;
                return ;
            }
        }else if(opcionNumerica == 2){
            return ;
        }

    }

}


void clientesManager::mostrarClienteInactivos(){


    clientesArchivo clientArchivo;
    Clientes clientes;

    system("cls");

    cout << left << fixed;

    // Encabezado de tabla
   cout << setw(5)  << "ID"
         << setw(30) << "RAZON SOCIAL / NOMBRE"
         << setw(30) << "DIRECCION"
         << setw(20) << "TELEFONO"
         << setw(25) << "EMAIL"
         << setw(10) << "VIAJES";

    cout << endl << string(120, '-') << endl;

    int cantidadRegistros = clientArchivo.getCantidadClientes();

    for(int i = 0; i < cantidadRegistros; i++) {
        if(clientArchivo.leerClientes(i, clientes)) {
            if(clientes.get_estado() == 0) {
                clientes.mostrar(0);
                cout << endl;
            }
        } else {
            cout << "Lectura incorrecta" << endl;
        }
    }

    cout << endl << endl;
    system("pause");
}




void clientesManager::viajesClientes(){

    system("cls");
    viajesArchivo vArchivo;
    Viajes viaje;
    viajesManager viajesManger;
    clientesArchivo clientesArchivo;


    if(!viajesManger.actualizarEstados()){
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    int cantidadRegistros = vArchivo.get_cantidadRegistros();


    cout << left; // Alinear a la izquierda todo

    // Encabezado
    cout << left;
    cout << setw(4)  << "ID"
    << setw(30) << "Nombre/Empresa"
    << setw(30) << "Direccion"
    << setw(33) << "Origen"
    << setw(33) << "Destino"
    << setw(20) << "Distancia"
    << setw(15) << "Estado";

    cout << endl << string(163, '-') << endl;


    for(int i = 0;i < cantidadRegistros; i++){



        if(vArchivo.leerViaje(i,viaje)){

            string estadoDeviaje;
            if(viaje.get_estado()){estadoDeviaje="En Viaje";}else{estadoDeviaje="Finalizado";}

            cout << setw(4)  << viaje.get_cliente().get_idCliente()
            << setw(30) <<viaje.get_cliente().get_Nombre_RazonSocial()
            << setw(30) << viaje.get_cliente().get_Direccion()
            << setw(33) << viaje.get_ciudadOrigen().getCiudad()
            << setw(33) << viaje.get_ciudadDestino().getCiudad()
            << setw(15) << viaje.get_distancia();


            cout << "     ";
            cout << setw(15) << estadoDeviaje
            << endl;



        }else{cout << "No se pudo leer el viaje";}

    }

    cout << endl << endl;
    system("pause");
}








