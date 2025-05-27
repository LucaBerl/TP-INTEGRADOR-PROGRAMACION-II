
#include "Clientes.h"
#include <cstring>  // para strcpy y strlen

// Constructor
Clientes::Clientes() {
    _idCliente = 0;
    _nombre_RazonSocial[0] = '\0';
    _direccion[0] = '\0';
    _telefono[0] = '\0';
    _email[0] = '\0';
    _cantidadViajesRealizados = 0;
}

// Setters

void Clientes::set_IdCliente(int idCliente) {
    _idCliente = idCliente;
}

void Clientes::set_Nombre_RazonSocial(const char* nombre_RazonSocial) {
    strncpy(_nombre_RazonSocial, nombre_RazonSocial, sizeof(_nombre_RazonSocial) - 1);
    _nombre_RazonSocial[sizeof(_nombre_RazonSocial) - 1] = '\0';  // asegurar null terminator
}

void Clientes::set_Direccion(const char* direccion) {
    strncpy(_direccion, direccion, sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}

void Clientes::set_Telefono(const char* telefono) {
    strncpy(_telefono, telefono, sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}

void Clientes::set_Email(const char* email) {
    strncpy(_email, email, sizeof(_email) - 1);
    _email[sizeof(_email) - 1] = '\0';
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

