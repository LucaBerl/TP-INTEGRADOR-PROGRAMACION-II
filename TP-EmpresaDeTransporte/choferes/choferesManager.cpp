#include "choferesManager.h"
#include "choferes.h"
#include <string>
#include <iostream>
#include "choferesArchivo.h"
#include <sstream>

using namespace std;

void choferesManager::cargarChofer()
{

    Choferes choferes; //crea el objeto llamando al constructor vacio
    choferesArchivo cArchivo;

    int id;
    bool asignado;
    int dni;
    string nombre;
    string apellido;
    int experiencia;
    bool aptoCircular;
    bool disponibilidad;
    float km;
    int mes;
    bool estado;

    cout <<"Ingrese ID del chofer: ";
    cin >>id;

    cout <<"Ingrese DNI del chofer: ";
    cin >>dni;

    cout <<"Ingrese nombre/s del chofer: ";
    cin.ignore();
    getline(cin, nombre);

    cout <<"Ingrese apellido/s del chofer: ";
    getline(cin, apellido);

    cout <<"Ingrese los años de experiencia del chofer: ";
    cin >>experiencia;

    cout <<"El chofer esta apto para circular 1-Si 0-No : ";
    cin >>aptoCircular;

    cout <<"El chofer esta asignado 1-Si 0-No : ";
    cin >>asignado;

    cout <<"Ingrese la cantidad de kilometros que recorrio el chofer en un  mes: ";
    cin >>km;

    cout <<"Ingrese el mes en el que el chofer recorrio esa cantidad de kilometros: ";
    cin >>mes;

    estado=true;

    //choferes se remplaza por el constructor que recibe paramentros
    choferes.set_id(id);
    choferes.set_dni(dni);
    choferes.set_nombre(nombre);
    choferes.set_apellido(apellido);
    choferes.set_experiencia(experiencia);
    choferes.set_aptoCircular(aptoCircular);
    choferes.set_asignado(asignado);
    choferes.set_kmMensuales(km, mes);



    if(cArchivo.guardar(choferes))
    {
        cout<<"Se guardo correctamente"<<endl;
    }
    else
    {
        cout<<"Hubo un error inesperado"<<endl;
    }
}


void choferesManager::bajaChofer()
{

}

void choferesManager::modificarChofer()
{

}

void choferesManager::mostrarCantidadRegistros()
{
    choferesArchivo cArchivo;

    int cantidadRegistros=cArchivo.getCantidadRegistros();

    cout<<"La cantidad de registros son: "<<cantidadRegistros<<endl;
}


void choferesManager::listarTodos()
{

    choferesArchivo cArchivo;
    Choferes registro;

    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        registro = cArchivo.leer(i);

        cout<<"----------"<<endl;
        cout<<"ID: "<<registro.get_id()<<endl;
        cout<<"dni: "<<registro.get_dni()<<endl;
        cout<<"Apellido: "<<registro.get_apellido()<<endl;
        cout<<"Nombre: "<<registro.get_nombre()<<endl;
        cout<<"Experiencia: "<<registro.get_experiencia()<<endl;
        cout<<"Es apto para circular: "<<registro.get_aptoCircular()<<endl;
        cout<<"Kilometros recorridos: "<<registro.get_kmMensuales()<<endl;
        cout<<"Mes en el que recorrio los kilometros: "<<registro.get_kmMensuales()<<endl;
    }
}

void choferesManager::listarDisponibles()
{
    choferesArchivo cArchivo;
    Choferes reg;

    int cantidad = cArchivo.getCantidadRegistros();
    cout<<"Los choferes disponibles son: "<<endl;
    for(int i=0; i<cantidad; i++)
    {
        reg=cArchivo.leer(i);

        if(reg.get_disponibilidad())
        {
            cout<<"----------"<<endl;
            cout<<"ID: "<<reg.get_id()<<endl;
            cout<<"dni: "<<reg.get_dni()<<endl;
            cout<<"Apellido: "<<reg.get_apellido()<<endl;
            cout<<"Nombre: "<<reg.get_nombre()<<endl;
            cout<<"Experiencia: "<<reg.get_experiencia()<<endl;
            cout<<"Es apto para circular: "<<reg.get_aptoCircular()<<endl;
        }
    }
}

void choferesManager::listarEnViaje()
{
    choferesArchivo cArchivo;
    Choferes registro;

    int cantidad = cArchivo.getCantidadRegistros();
    cout<<"Los choferes en viaje son: "<<endl;
    for(int i=0; i<cantidad; i++)
    {
        registro=cArchivo.leer(i);

        if(registro.get_disponibilidad())
        {
            cout<<"----------"<<endl;
            cout<<"ID: "<<registro.get_id()<<endl;
            cout<<"dni: "<<registro.get_dni()<<endl;
            cout<<"Apellido: "<<registro.get_apellido()<<endl;
            cout<<"Nombre: "<<registro.get_nombre()<<endl;
            cout<<"Experiencia: "<<registro.get_experiencia()<<endl;
            cout<<"Es apto para circular: "<<registro.get_aptoCircular()<<endl;
        }
    }
}
