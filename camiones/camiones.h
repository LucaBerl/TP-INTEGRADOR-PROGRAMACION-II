
#pragma once
#include "../Fecha/fecha.h"
#include <string>
#include <vector>

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
  bool _aptoCircular; /// Si transcurrio menos de 1 año desde la fecha de la ultima verificacion, entonces es apto
  bool _enViaje;  /// Si se encuentra en viaje = 1 , si no es 0
  bool _choferAsignado;  /// Si le asignamos un camion a un chofer, el estado pasa a 1
  bool _estado;  /// Si damos de baja el camion, el estado pasa a 0

public:

void mostrar()const;
void listarMarcas() const;
std::vector<std::string> catalogoMarcas() const;
std::string validarMarca(int nro) const;


// Constructor

Camiones();

// Setters:

void set_idCamion(int ultimo);
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
void set_enViaje(bool disponibilidad);
void set_choferAsignado(bool asignado);
void set_estado(bool estado);

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
bool get_enViaje()const;
bool get_choferAsignado()const;
bool get_estado()const;


};




