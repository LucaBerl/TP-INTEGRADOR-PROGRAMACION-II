
#pragma once
#include "../Ciudades/ciudades.h"
#include "../choferes/choferes.h"
#include "../Clientes/Clientes.h"
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
  float _pesoTransportado;
  float _volumenTransportado;
  bool _estado;
  Clientes _cliente;

public:

int segundosRestantes();
void mostrarViajeActivo();
void mostrarViaje();

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
bool set_pesoTransportado(float pesoCarga);
bool set_volumenTransportado(float volumenCarga);
void set_estado(bool estado);
void set_cliente(const Clientes &cliente);

// Getters:

int get_id() const;
const Choferes& get_chofer() const;
const Ciudades& get_ciudadOrigen() const;
const Ciudades& get_ciudadDestino() const;
float get_distancia() const;
const tm& get_fechaSalida() const;
const tm& get_fechaLlegada() const;
std::string get_tipoCarga() const;
float get_pesoTransportado()const;
float get_volumenTransportado()const;
bool get_estado() const;
const Clientes& get_cliente() const;
};


