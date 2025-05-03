#include "viajes.h"
#include <string>
#include<iostream>

// Constructor

Viajes();

// Setters:

void set_chofer(const Choferes &chofer){
    _chofer = chofer;
} 
void set_ciudadOrigen(const Ciudades &ciudad_origen){
    _ciudadOrigen = ciudad_origen;
}
void set_ciudadDestino(const Ciudades &ciudad_destino){
    _ciudadDestino = ciudad_destino;
}
bool set_distancia(float distancia){ 
      if (distancia > 0){
          _distancia = distancia;
          return true;
      }else{return false;}
}
void set_fechaSalida(const  tm &fechaSalida){
    _fechaSalida = fechaSalida;
}
void set_fechaLlegada(const  tm &fechaLlegada){
    _fechaLlegada = fechaLlegada;
}
bool set_tipoCarga(std::string tipoCarga){
    if (tipoCarga.length() < sizeof(_tipoCarga)) {
        strcpy(_tipoCarga, tipoCarga.c_str());
        return true;
    } else { return false;}              
}
void set_estado(bool estado){
  _estado = estado;
}


///Getters:


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
string Viajes::get_tipoCarga() const{
    return _tipoCarga;
}
bool Viajes::get_estado() const{
    return _estado;
}
