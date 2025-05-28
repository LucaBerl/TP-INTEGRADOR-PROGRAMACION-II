#pragma once

#include <string>


class Clientes{

private:
  int _idCliente;
  char _nombre_RazonSocial[50];
  char _direccion[50];
  char _telefono[15];
  char _email[50];
  int _cantidadViajesRealizados;


public:

    void mostrar()const;

 // constructor

    Clientes();



 //setter


void set_IdCliente(int idCliente);

bool set_Nombre_RazonSocial(std::string  nombre_RazonSocial);

bool set_Direccion(std::string  direccion);

bool set_Telefono(std::string  telefono);

bool set_Email(std::string  email);

void set_CantidadViajesRealizados(int cantidadViajesRealizados);



 // getters


 int get_idCliente()const;

 std::string get_Nombre_RazonSocial()const;

 std::string get_Direccion()const;

 std::string get_Telefono()const;

 std::string get_Email()const;

 int get_Cantidad_Viajes_Realizados()const;

};
