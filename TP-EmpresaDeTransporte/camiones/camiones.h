/*
#pragma once
#include "fecha.h"
#include <string>


class Camiones{

private:
  int _idCamion;
  char _patente[8];
  char _marca[30];
  char _modelo[30];
  int _anio;
  float _pesoCarga;
  float _volumenCarga;
  float _kmMensuales[12];
  Fecha _ultimaVerificacion;
  bool _aptoCircular;
  bool _disponibilidad;

public:

// Constructor

Camiones();

// Setters:

void set_idCamion(int idCamion);
bool set_patente(std::string patente);
bool set_marca(std::string marca);
bool set_modelo(std::string modelo);
bool set_anio(int anio);
bool set_pesoCarga(float pesoCarga);
bool set_volumenCarga(float volumenCarga);
void set_kmMensuales();                     //Setea en 0 todo el array
bool set_kmMensuales(float km,int mes);    // Lleva la cuenta de los km mensuales
void set_ultimaVerificacion(const Fecha &ultimaVerificacion);
void set_aptoCircular(bool aptoCircular);
void set_disponibilidad(bool disponibilidad);

// Getters:

int get_idCamion()const;
std::string get_patente()const;
std::string get_marca()const;
std::string get_modelo()const;
int get_anio()const;
float get_pesoCarga()const;
float get_volumenCarga()const;
const float* get_kmMensuales()const; // devuelve 12 elementos
const Fecha& get_ultimaVerificacion()const;
bool get_aptoCircular()const;
bool get_disponibilidad()const;


};
*/
