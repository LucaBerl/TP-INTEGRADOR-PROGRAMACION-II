
#include "viajes.h"
#include <cstring>

double Viajes::segundosRestantes(){

    time_t t0 = time(NULL); ///Tiempo actual
    tm llegada = get_fechaLlegada();
    time_t t1 = mktime(&llegada);

    if (t1 < t0){

        return 0; //Viaje finalizado
    }


    return t1 - t0; // Segundos restantes

}

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


