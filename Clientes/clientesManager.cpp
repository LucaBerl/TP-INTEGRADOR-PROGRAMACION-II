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
    cout << setw(3) << "ID   "
    << setw(15) << "RAZON SOCIAL / NOMBRE   "
    << setw(15) << "DIRECCION"
    << setw(15) << "TELEFONO"
    << setw(15) << "EMAIL    "
    << setw(3) << "CANTIDAD VIAJES REALIZADOS";


    cout << endl << "----------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = clientArchivo.getCantidadClientes();

    for(int i = 0;i < cantidadRegistros; i++){

        if(clientArchivo.leerClientes(i,clientes)){
                 if (clientes.get_estado() == 1){

                    clientes.mostrar(1);
                    cout << endl;


                }


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

    cout << "RESUMEN" << endl;

    cout << endl << "ID: " << cliente.get_idCliente();

    cout << endl << "Razon social / Nombre " << cliente.get_Nombre_RazonSocial();

    cout << endl << "Direccion " << cliente.get_Direccion();

    cout << endl << "Telefono " <<cliente.get_Telefono();

    cout << endl << "Email " << cliente.get_Email();

    cout << endl << "Estado " << cliente.get_estado();








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
    cout << setw(3) << "ID   "
    << setw(15) << "RAZON SOCIAL / NOMBRE   "
    << setw(15) << "DIRECCION"
    << setw(15) << "TELEFONO"
    << setw(15) << "EMAIL"
    << setw(3) << "CANTIDAD VIAJES REALIZADOS";


    cout << endl << "----------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = clientArchivo.getCantidadClientes();

    for(int i = 0;i < cantidadRegistros; i++){

        if(clientArchivo.leerClientes(i,clientes)){
                 if (clientes.get_estado() == 0){

                    clientes.mostrar(0);

                    cout << endl;


                }


            }else{cout << "Lectura incorrecta";}

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
     << setw(20) << "Nombre/Empresa"
     << setw(15) << "Direccion"
     << setw(15) << "Origen"
     << setw(15) << "Destino"
     << setw(15) << "Distancia"
     << setw(10) << "Estado";

cout << endl << string(119, '-') << endl;


    for(int i = 0;i < cantidadRegistros; i++){



        if(vArchivo.leerViaje(i,viaje)){

            if(viaje.get_estado() == true){

                cout << setw(4)  << viaje.get_cliente().get_idCliente()
     << setw(20) <<viaje.get_cliente().get_Nombre_RazonSocial()
     << setw(15) << viaje.get_cliente().get_Direccion()
     << setw(15) << viaje.get_ciudadOrigen().getCiudad()
     << setw(15) << viaje.get_ciudadDestino().getCiudad()
     << setw(10) << viaje.get_distancia();


  cout << "        ";
  cout << setw(10) << viaje.get_estado()
     << endl;

            }

        }else{cout << "No se pudo leer el viaje";}

    }

    cout << endl << endl;
    system("pause");
}








