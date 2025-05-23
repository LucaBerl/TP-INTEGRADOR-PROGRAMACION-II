#include "choferes.h"
#include "../camiones/camiones.h"
#include <cstring>
#include <sstream>  // Necesario para std::stringstream
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;


///Constructor:

Choferes::Choferes()
{

    set_id(0);
    set_asignado(0);
    set_camionAsignado({});
    set_dni(1000000);
    set_nombre("");
    set_apellido("");
    set_experiencia(0);
    set_vencimientoLicencia(Fecha());
    set_aptoCircular(1);
    set_enViaje(0);
    set_kmMensuales();


}

///Setters:

bool Choferes::set_id(int id)
{
    _id = id;
}
void Choferes::set_asignado(bool asignado)
{
    _asignado = asignado;
}
void Choferes::set_camionAsignado(const Camiones& camionasignado)
{
    _camionAsignado = camionasignado;
}
bool Choferes::set_dni(int dni)
{
    if (dni >= 1000000 && dni < 100000000)
    {
        _dni = dni;
        return true;
    }
    else
    {
        return false;
    }
}
bool Choferes::set_nombre(std::string nombre)
{
    if(nombre.length() < sizeof(_nombre))
    {
        strcpy(_nombre,nombre.c_str());
        return true;
    }
    else
    {
        return false;
    }
}
bool Choferes::set_apellido(std::string apellido)
{
    if(apellido.length() < sizeof(_apellido))
    {
        strcpy(_apellido,apellido.c_str());
        return true;
    }
    else
    {
        return false;
    }
}
bool Choferes::set_experiencia(int experiencia)
{
    if (experiencia >= 0 && experiencia <= 80)
    {
        _experiencia = experiencia;
        return true;
    }
    else
    {
        return false;
    }
}
void Choferes::set_vencimientoLicencia(const Fecha &fechaVencimiento)
{
    _vencimientoLicencia = fechaVencimiento;
}
void Choferes::set_aptoCircular(bool aptoCircular)
{
    _aptoCircular = aptoCircular;
}
void Choferes::set_enViaje(bool enViaje)
{
   _enViaje = enViaje;
}
bool Choferes::set_kmMensuales(float km,int mes)
{
    if (mes > 0 && mes < 13 && km > 0)
    {
        _kmMensuales[mes-1] += km;
        return true;
    }
    else
    {
        return false;
    }
}
void Choferes::set_kmMensuales()
{
    for(int i = 0; i < 12; i++)
    {
        _kmMensuales[i] = 0;
    }
}

///Getters:

int Choferes::get_id()const
{
    return _id;
}
const Camiones& Choferes::get_camionAsignado()const
{
    return _camionAsignado;
}
int Choferes::get_dni()const
{
    return _dni;
}
std::string Choferes::get_nombre()const
{
    return _nombre;
}
std::string Choferes::get_apellido()const
{
    return _apellido;
}
int Choferes::get_experiencia()const
{
    return _experiencia;
}
const Fecha& Choferes::get_vencimientoLicencia()const
{
    return _vencimientoLicencia;
}
bool Choferes::get_aptoCircular()const
{
    return _aptoCircular;
}
bool Choferes::get_enViaje()const
{
    return _enViaje;
}
const float* Choferes::get_kmMensuales()const
{
    return _kmMensuales;                        //devuelve todo el vector
}


////////////////////////////

void Choferes::mostrar()const{

    string aptoCircular;

    if (get_aptoCircular()){aptoCircular = "✔";} else{aptoCircular = "🚫";}
    //if (get_enViaje()){disponibilidad = "❌";}else{disponibilidad = "✔";}
    cout << left;
    cout << setw(6) << get_id()
    << setw(10) << get_dni()
    << setw(20) << get_nombre()
    << setw(20) << get_apellido()
    << setw(20) << get_experiencia()
    << setw(20) << get_vencimientoLicencia().toString()
    << setw(10) << aptoCircular;
    //<< setw(12) << disponibilidad;

}




