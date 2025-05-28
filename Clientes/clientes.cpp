
#include "Clientes.h"
#include <cstring>  // para strcpy y strlen

#include <iostream>
using namespace std;
#include <iomanip>

// Constructor
Clientes::Clientes() {
    set_IdCliente(0);
    set_Nombre_RazonSocial("");
    set_Direccion("");
    set_Telefono("");
    set_Email("");
    set_CantidadViajesRealizados(0);
}

// Setters

void Clientes::set_IdCliente(int idCliente) {
    _idCliente = idCliente + 1;
}




bool Clientes::set_Nombre_RazonSocial(std::string  nombre_RazonSocial) {
    if(nombre_RazonSocial.length()< sizeof(_nombre_RazonSocial)){

        strcpy(_nombre_RazonSocial,nombre_RazonSocial.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Direccion(std::string  direccion) {

    if(direccion.length()< sizeof(_direccion)){

        strcpy(_direccion,direccion.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Telefono(std::string  telefono) {
    if(telefono.length()< sizeof(_telefono)){

        strcpy(_telefono,telefono.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Email(std::string  email) {
    if(email.length()< sizeof(_email)){

        strcpy(_email,email.c_str());
        return true;

    } else {return false;}
}

void Clientes::set_CantidadViajesRealizados(int cantidadViajesRealizados) {
    _cantidadViajesRealizados = cantidadViajesRealizados;
}

// Getters

int Clientes::get_idCliente() const {
    return _idCliente;
}

std::string Clientes::get_Nombre_RazonSocial() const {
    return std::string(_nombre_RazonSocial);
}

std::string Clientes::get_Direccion() const {
    return std::string(_direccion);
}

std::string Clientes::get_Telefono() const {
    return std::string(_telefono);
}

std::string Clientes::get_Email() const {
    return std::string(_email);
}

int Clientes::get_Cantidad_Viajes_Realizados() const {
    return _cantidadViajesRealizados;
}

void Clientes::mostrar()const{

/*    string aptoCircular, disponibilidad;

    if (get_aptoCircular()){aptoCircular = "✔";}else{aptoCircular = "🚫";}
    if (get_enViaje()){disponibilidad = "❌";}else{disponibilidad = "✔";}

*/

    cout << left;
    cout << setw(3) << get_idCliente()
    << setw(10) << get_Nombre_RazonSocial()
    << setw(30) << get_Direccion()
    << setw(30) << get_Telefono()
    << setw(6) << get_Email()
    << setw(7) << get_Cantidad_Viajes_Realizados();

}
