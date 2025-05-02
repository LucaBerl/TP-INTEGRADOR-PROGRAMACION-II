#pragma once
#include "ciudades.h"
#include "choferes.h"
#include <ctime>

class Viajes{

private:
  Choferes _chofer;
  Ciudades _ciudadOrigen;
  Ciudades _ciudadDestino;
  float _distancia;
  struct tm _fechaSalida;
  struct tm _fechaLlegada; 
  char _tipoCarga[30];
  bool _estado;
  
public:

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


};
