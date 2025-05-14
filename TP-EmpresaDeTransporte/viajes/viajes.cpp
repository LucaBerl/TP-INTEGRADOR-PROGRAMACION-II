
#include "viajes.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;



// Constructor

Viajes::Viajes(){

set_id(-1);
set_chofer(Choferes());
set_ciudadOrigen(Ciudades());
set_ciudadDestino(Ciudades());
set_distancia(1);
set_fechaSalida({});
set_fechaLlegada({});
set_tipoCarga("");
set_estado(0);


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
void Viajes::set_estado(bool estado){
  _estado = estado;
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
bool Viajes::get_estado() const{
    return _estado;
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

    cout << setw(3)  << get_id()
     << setw(40) << choferCompleto
     << setw(33) << get_ciudadOrigen().getCiudad()
     << setw(33) << get_ciudadDestino().getCiudad()
     << setw(30) << get_tipoCarga();

// Mostrar tiempo restante
    cout << horas << "h " << minutos << "m" << endl;

}

void Viajes::mostrarViaje(){


    cout << left;

    string choferCompleto = get_chofer().get_nombre() + " " + get_chofer().get_apellido();

    cout << setw(3)  << get_id()
    << setw(40) << choferCompleto
    << setw(33) << get_ciudadOrigen().getCiudad()
    << setw(33) << get_ciudadDestino().getCiudad()
    << setw(30) << get_tipoCarga()
    << setw(15) << get_distancia()
    << setw(11) << get_fechaSalida().tm_mday<<"/"<<get_fechaSalida().tm_mon+1<<"/"<<get_fechaSalida().tm_year+1900
    << setw(11) << get_fechaLlegada().tm_mday<<"/"<<get_fechaLlegada().tm_mon+1<<"/"<<get_fechaLlegada().tm_year+1900;


}
