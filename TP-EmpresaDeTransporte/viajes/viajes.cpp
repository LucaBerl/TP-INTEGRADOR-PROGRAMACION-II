#include "viajes.h"
#include <string>
#include<iostream>

/// Setters:






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

void Viajes::set_estado(bool estado){
  _estado = estado;
}

///Getters:


float Viajes::get_distancia() const{
    return _distancia;
}
const tm& Viajes::get_fechaSalida() const{
    return _fechaSalida;
}
const tm& Viajes::get_fechaLlegada() const{
    return _fechaLlegada;
}

bool Viajes::get_estado() const{
    return _estado;
}
