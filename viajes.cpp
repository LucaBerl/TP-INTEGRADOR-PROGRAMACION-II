#include "viajes.h"


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
