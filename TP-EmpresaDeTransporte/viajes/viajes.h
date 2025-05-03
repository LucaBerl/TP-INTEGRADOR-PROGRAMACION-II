#pragma once


#include <ctime>

class Viajes{

private:


  float _distancia;
  struct tm _fechaSalida;
  struct tm _fechaLlegada;
  char _tipoCarga[30];
  bool _estado;

public:

// Constructor

Viajes();

// Setters:


bool set_distancia(float distancia);
void set_fechaSalida(const  tm &fechaSalida);
void set_fechaLlegada(const  tm &fechaLlegada);

void set_estado(bool estado);

// Getters:


float get_distancia() const;
const tm& get_fechaSalida() const;
const tm& get_fechaLlegada() const;

bool get_estado() const;

};
