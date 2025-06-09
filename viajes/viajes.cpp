
#include "viajes.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;



// Constructor

Viajes::Viajes(){

set_id(0);
set_chofer(Choferes());
set_ciudadOrigen(Ciudades());
set_ciudadDestino(Ciudades());
set_distancia(1);
set_fechaSalida({});
set_fechaLlegada({});
set_tipoCarga("");
set_pesoTransportado(0);
set_volumenTransportado(1);
set_estado(1);
set_cliente(Clientes());

}

// Setters:
void Viajes::set_id(int ultimo){
    _id = ultimo + 1;
}
void Viajes::set_chofer(const Choferes &chofer){
    _chofer = chofer;
}
void Viajes::set_ciudadOrigen(const Ciudades &ciudad_origen){
    _ciudadOrigen = ciudad_origen;
}
void Viajes::set_ciudadDestino(const Ciudades &ciudad_destino){
    _ciudadDestino = ciudad_destino;
}
bool Viajes::set_distancia(float distancia){
      if (distancia > 0){
          _distancia = distancia;
          return true;
      }else{return false;}
}
void Viajes::set_fechaSalida(const  tm &fechaSalida){
    _fechaSalida = fechaSalida;
}
void Viajes::set_fechaLlegada(const  tm &fechaLlegada){
    _fechaLlegada = fechaLlegada;
}
bool Viajes::set_tipoCarga(std::string tipoCarga){
    if (tipoCarga.length() < sizeof(_tipoCarga)) {
        strcpy(_tipoCarga, tipoCarga.c_str());
        return true;
    } else { return false;}
}
bool Viajes::set_pesoTransportado(float pesoCarga){
    if (pesoCarga >= 0 && pesoCarga <= 70000){
        _pesoTransportado = pesoCarga;
        return true;
    }else{return false;}
}
bool Viajes::set_volumenTransportado(float volumenCarga){
    if(volumenCarga >= 1 && volumenCarga <= 150 ){
        _volumenTransportado = volumenCarga;
        return true;
    }else{return false;}
}
void Viajes::set_estado(bool estado){
  _estado = estado;
}

void Viajes::set_cliente(const Clientes &cliente){
    _cliente = cliente;
}

///Getters:

int Viajes::get_id() const{
    return _id;
}
const Choferes& Viajes::get_chofer() const{
    return _chofer;
}
const Ciudades& Viajes::get_ciudadOrigen() const{
    return _ciudadOrigen;
}
const Ciudades& Viajes::get_ciudadDestino() const{
    return _ciudadDestino;
}
float Viajes::get_distancia() const{
    return _distancia;
}
const tm& Viajes::get_fechaSalida() const{
    return _fechaSalida;
}
const tm& Viajes::get_fechaLlegada() const{
    return _fechaLlegada;
}
std::string Viajes::get_tipoCarga() const{
    return _tipoCarga;
}
float Viajes::get_pesoTransportado()const{
    return _pesoTransportado;
}
float Viajes::get_volumenTransportado()const{
    return _volumenTransportado;
}
bool Viajes::get_estado() const{
    return _estado;
}

const Clientes& Viajes::get_cliente() const{
    return _cliente;
}

/////////////////////////////////////////////////////////////////

int Viajes::segundosRestantes(){

    time_t t0 = time(NULL); ///Tiempo actual
    tm llegada = get_fechaLlegada();
    time_t t1 = mktime(&llegada);

    if (t1 < t0){

        return 0; //Viaje finalizado
    }


    return t1 - t0; // Segundos restantes

}

void Viajes::mostrarViajeActivo(){

    int segundos = segundosRestantes();
    int horas = segundos / 3600;
    int minutos = (segundos % 3600) / 60;
    //int segundos = segundos % 60;

    cout << left; // Alinear a la izquierda todo

// Datos del viaje
    string choferCompleto = get_chofer().get_nombre() + " " + get_chofer().get_apellido();





    cout << setw(4)  << get_id()
    << setw(40) << choferCompleto
    << setw(33) << get_ciudadOrigen().getCiudad()
    << setw(33) << get_ciudadDestino().getCiudad()
    << setw(30) << get_tipoCarga()
    << setw(15) << (to_string(horas)+"h " +to_string(minutos)+"m")
    << setw(30) << get_cliente().get_Nombre_RazonSocial() << endl;

// Mostrar tiempo restante
   // cout << horas << "h " << minutos << "m" << endl;

}

void Viajes::mostrarViaje(){


    cout << left;

    string choferCompleto = get_chofer().get_nombre() + " " + get_chofer().get_apellido();

    string fechaSalida = to_string(get_fechaSalida().tm_mday) + "/" +
    to_string(get_fechaSalida().tm_mon + 1) + "/" +
    to_string(get_fechaSalida().tm_year + 1900);

    string fechaLlegada = to_string(get_fechaLlegada().tm_mday) + "/" +
    to_string(get_fechaLlegada().tm_mon + 1) + "/" +
    to_string(get_fechaLlegada().tm_year + 1900);


    cout << setw(3)  << get_id()
    << setw(40) << choferCompleto
    << setw(33) << get_ciudadOrigen().getCiudad()
    << setw(33) << get_ciudadDestino().getCiudad()
    << setw(30) << get_tipoCarga()
    << setw(15) << get_distancia()
    << setw(11) << fechaSalida
    << setw(11) << fechaLlegada;

}
