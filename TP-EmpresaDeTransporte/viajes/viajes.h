
#pragma once
#include "../Ciudades/ciudades.h"
#include "../choferes/choferes.h"
#include <ctime>
#include <string>

class Viajes{

private:
  int _id;
  Choferes _chofer;
  Ciudades _ciudadOrigen;
  Ciudades _ciudadDestino;
  float _distancia;
  struct tm _fechaSalida;
  struct tm _fechaLlegada;
  char _tipoCarga[30];
  bool _estado;

public:

int segundosRestantes();
void mostrarViajeActivo();

// Constructor

Viajes();

// Setters:
void set_id(int ultimo);
void set_chofer(const Choferes &chofer);
void set_ciudadOrigen(const Ciudades &ciudad_origen);
void set_ciudadDestino(const Ciudades &ciudad_destino);
bool set_distancia(float distancia);
void set_fechaSalida(const  tm &fechaSalida);
void set_fechaLlegada(const  tm &fechaLlegada);
bool set_tipoCarga(std::string tipoCarga);
void set_estado(bool estado);

// Getters:

int get_id() const;
const Choferes& get_chofer() const;
const Ciudades& get_ciudadOrigen() const;
const Ciudades& get_ciudadDestino() const;
float get_distancia() const;
const tm& get_fechaSalida() const;
const tm& get_fechaLlegada() const;
std::string get_tipoCarga() const;
bool get_estado() const;

};


