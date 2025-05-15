#pragma once

#include <string>


class Clientes{

private:
  int _idCiente;
  char _nombre_RazonSocial[50];
  char _direccion[50];
  char _telefono[15];
  char _email[50];
  int _cantidadViajesRealizados;


public:

 // constructor

    Clientes();



 //setter


void set_IdCliente(int idCliente);

void set_Nombre_RazonSocial(const char* nombre_RazonSocial);

void set_Direccion(const char* direccion);

void set_Telefono(const char* telefono);

void set_Email(const char* email);

void set_CantidadViajesRealizados(int cantidadViajesRealizados);



 // getters


 int get_idCliente()const;

 std::string get_Nombre_RazonSocial()const;

 std::string get_Direccion()const;

 std::string get_Telefono()const;

 std::string get_Email()const;

 int get_Cantidad_Viajes_Realizados()const;

}
