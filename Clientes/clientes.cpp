
#include "Clientes.h"
#include <cstring>  // para strcpy y strlen

#include <iostream>
using namespace std;
#include <iomanip>

// Constructor
Clientes::Clientes() {
    set_IdCliente(-1);
    set_Nombre_RazonSocial("");
    set_Direccion("");
    set_Telefono("");
    set_Email("");
    set_CantidadViajesRealizados(0);
    set_estado(1);
}

// Setters

void Clientes::set_IdCliente(int idCliente) {
    _idCliente = idCliente + 1;
}

bool soloLetrasYEspacios(const std::string& texto) {
    for (char c : texto) {
        if (!isalpha(c) && c != ' ') {
            return false; // si no es letra ni espacio, es inválido
        }
    }
    return true;
}


bool Clientes::set_Nombre_RazonSocial(std::string  nombre_RazonSocial) {
    if(nombre_RazonSocial.length()< sizeof(_nombre_RazonSocial)&&nombre_RazonSocial.length()>2&&soloLetrasYEspacios(nombre_RazonSocial)){

        strcpy(_nombre_RazonSocial,nombre_RazonSocial.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Direccion(std::string  direccion) {

    if(direccion.length()< sizeof(_direccion)&&direccion.length()>2){

        strcpy(_direccion,direccion.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Telefono(std::string  telefono) {
    if(telefono.length()< sizeof(_telefono)&&telefono.length()>4){

        strcpy(_telefono,telefono.c_str());
        return true;

    } else {return false;}
}

bool Clientes::set_Email(std::string  email) {
    if(email.length()< sizeof(_email)&&email.length()>6){

        strcpy(_email,email.c_str());
        return true;

    } else {return false;}
}

void Clientes::set_CantidadViajesRealizados(int cantidadViajesRealizados) {
    _cantidadViajesRealizados = cantidadViajesRealizados;
}

void Clientes::set_estado(bool estado){
    _estado = estado;
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

bool Clientes::get_estado()const{
    return _estado;
}

void Clientes::mostrar(int estado )const{

if(get_estado() == estado) {
        cout << left
             << setw(5) << get_idCliente()
             << setw(30) << get_Nombre_RazonSocial()
             << setw(30) << get_Direccion()
             << setw(20) << get_Telefono()
             << setw(30) << get_Email()
             << setw(10) << get_Cantidad_Viajes_Realizados();
    }


}



