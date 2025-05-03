/*
#include "camiones.h"
#include <cstring>


// Setters:

void Camiones::set_idCamion(int idCamion){
    _idCamion = idCamion;
}
bool Camiones::set_patente(std::string patente){
    if (patente.length() < sizeof(_patente) && patente.length() >= 6){
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
    if ( anio > 1960 && anio < 2026){
        _anio = anio;
        return true;
    }else{return false;}
}
bool Camiones::set_pesoCarga(float pesoCarga){
    if (pesoCarga > 500 && pesoCarga < 70000){
        _pesoCarga = pesoCarga;
        return true;
    }else{return false;}
}
bool Camiones::set_volumenCarga(float volumenCarga){
    if(volumenCarga > 1 && volumenCarga < 150 ){
        _volumenCarga = volumenCarga;
        return true;
    }else{return false;}
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
void Camiones::set_disponibilidad(bool disponibilidad){
    _disponibilidad = disponibilidad;
}

*/
