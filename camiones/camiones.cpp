#include <iostream>
using namespace std;
#include "camiones.h"
#include <cstring>
#include <iomanip>
#include <vector>

// Constructor

Camiones::Camiones(){

set_idCamion(-1);
set_patente("");
set_marca("");
set_modelo("");
set_anio(0);
set_pesoCarga(501);
set_volumenCarga(2);
set_kmMensuales();
set_ultimaVerificacion(Fecha());
set_aptoCircular(1);
set_enViaje(0);
set_choferAsignado(0);
set_estado(1);



}

// Setters:

void Camiones::set_idCamion(int ultimo){
    _idCamion = ultimo +1;
}
bool Camiones::set_patente(std::string patente){

    if (patente.length() < sizeof(_patente) && ( patente.length() == 6 || patente.length() == 7 )){
        for (char &c : patente) {
            c = toupper(c);
        }
        strcpy(_patente,patente.c_str());
        return true;
    } else {return false;}
}
bool Camiones::set_marca(std::string marca){
    if (marca.length() < sizeof(_marca)){
        strcpy(_marca,marca.c_str());
        return true;
    } else {return false;}
}
bool Camiones::set_modelo(std::string modelo){
    if (modelo.length() < sizeof(_modelo)){
        strcpy(_modelo,modelo.c_str());
        return true;
    } else {return false;}
}
bool Camiones::set_anio(int anio){
    if ( anio >= 1960 && anio < 2026){
        _anio = anio;
        return true;
    }else{return false;}
}
bool Camiones::set_pesoCarga(float pesoCarga){
    if (pesoCarga >= 500 && pesoCarga <= 70000){
        _pesoCarga = pesoCarga;
        return true;
    }else{return false;}
}
bool Camiones::set_volumenCarga(float volumenCarga){
    if(volumenCarga >= 1 && volumenCarga <= 150 ){
        _volumenCarga = volumenCarga;
        return true;
    }else{return false;}
}
void Camiones::set_kmMensuales(){
    for(int i = 0; i < 12; i++){
        _kmMensuales[i] = 0;
    }
}
bool Camiones::set_kmMensuales(float km,int mes){
    if (mes > 0 && mes < 13){
        _kmMensuales[mes-1] += km;
        return true;
    }else{return false;}
}


void Camiones::set_ultimaVerificacion(const Fecha &ultimaVerificacion){
    _ultimaVerificacion = ultimaVerificacion;
}


void Camiones::set_aptoCircular(bool aptoCircular){
    _aptoCircular = aptoCircular;
}
void Camiones::set_enViaje(bool disponibilidad){
    _enViaje = disponibilidad;
}
void Camiones::set_choferAsignado(bool asignado){
    _choferAsignado = asignado;
}
void Camiones::set_estado(bool estado){
    _estado = estado;
}

// Getters:

int Camiones::get_idCamion()const{
    return _idCamion;
}
std::string Camiones::get_patente()const{
    return _patente;
}
std::string Camiones::get_marca()const{
    return _marca;
}
std::string Camiones::get_modelo()const{
    return _modelo;
}
int Camiones::get_anio()const{
    return _anio;
}
float Camiones::get_pesoCarga()const{
    return _pesoCarga;
}
float Camiones::get_volumenCarga()const{
    return _volumenCarga;
}
const float* Camiones::get_kmMensuales()const{  // devuelve 12 elementos
    return _kmMensuales;
}

const Fecha& Camiones::get_ultimaVerificacion()const{
    return _ultimaVerificacion;
}

bool Camiones::get_aptoCircular()const{
    return _aptoCircular;
}
bool Camiones::get_enViaje()const{
    return _enViaje;
}
bool Camiones::get_choferAsignado()const{
    return _choferAsignado;
}
bool Camiones::get_estado()const{
    return _estado;
}


////////////////////////////

void Camiones::mostrar()const{

    string aptoCircular, disponibilidad;

    if (get_aptoCircular()){aptoCircular = "✔";}else{aptoCircular = "🚫";}
    if (get_enViaje()){disponibilidad = "❌";}else{disponibilidad = "✔";}
    cout << left;
    cout << setw(3) << get_idCamion()
    << setw(10) << get_patente()
    << setw(30) << get_marca()
    << setw(30) << get_modelo()
    << setw(6) << get_anio()
    << setw(7) << get_pesoCarga()
    << setw(10) << get_volumenCarga()
    << setw(16) << get_ultimaVerificacion().toString()
    << setw(8) << aptoCircular
    << setw(12) << disponibilidad;

}

////////////////////////////////

std::vector<std::string> Camiones::catalogoMarcas() const{
    return{
        "Mercedez-Benz", "Volvo", "Scania", "Iveco", "Ford", "Volkswagen"
    };
}

void Camiones::listarMarcas()const{
    vector<std::string> marcas = catalogoMarcas();

    cout<<"Marcas disponibles"<<endl;

    for(size_t i = 0; i < marcas.size(); i++){
        cout<<" " << (i + 1) << "-" << marcas[i] << " | " ;
    }
    cout<<" "<< (marcas.size() + 1) << ") Otra (ingresar manualmente)";
}

std::string Camiones::validarMarca(int nro) const{
    std::string marcaSeleccionada;
    vector<std::string> marcas = catalogoMarcas();
    if (nro >= 1 && nro <= static_cast<int>(marcas.size())){
        marcaSeleccionada = marcas[nro - 1];
    } else{
        marcaSeleccionada = "Otra";
    }

    return marcaSeleccionada;
}


