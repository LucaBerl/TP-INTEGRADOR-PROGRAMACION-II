#include <iostream>
using namespace std;
#include "fecha.h"

Fecha::Fecha(){

    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    set_Dia(dia);
    set_Mes(mes);
    set_Anio(anio);
}

bool Fecha::set_Dia(int dia){
    if (dia > 0 && dia < 32){
        _dia=dia;
        return true;
    }
    else{return false;}
}
bool Fecha::set_Mes(int mes){
    if(mes > 0 && mes < 13){
        _mes=mes;
        return true;
    }
    else{return false;}
}
bool Fecha::set_Anio(int anio){
    if (anio > 1900 && anio < 2100){
        _anio=anio;
        return true;
    }
    else{return false;}
}

int Fecha::get_Dia()const{return _dia;}

int Fecha::get_Mes()const{return _mes;}

int Fecha::get_Anio()const{return _anio;}

string Fecha::toString()const{

    int dia = get_Dia();
    int mes = get_Mes();
    int anio = get_Anio();
    string Fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);

    return Fecha;

}

void Fecha::Mostrar()const{

    if(_dia < 10){cout << "0" <<_dia<<"/";}else{cout << _dia<<"/";}
    if(_mes < 10){cout << "0" <<_mes<<"/";}else{cout << _mes<<"/";}
    cout << _anio ;
}

void Fecha::Mostrar(int dia, int mes, int anio)const{

    if(dia < 10){cout << "0" <<dia<<"/";}else{cout << dia<<"/";}
    if(mes < 10){cout << "0" <<mes<<"/";}else{cout << mes<<"/";}
    cout << anio ;

}

bool Fecha::Cargar(int dia, int mes, int anio){

    if(!set_Dia(dia)){
        cout << "Dia incorrecto";
        return false;
    }
    if(!set_Mes(mes)){
        cout << "Mes incorrecto";
        return false;
    }
    if(!set_Anio(anio)){
        cout << "Año incorrecto";
        return false;
    }
    return true;
}

// Validar Fecha

bool Fecha::validarFecha(int dia, int mes, int anio){
    // Años
    if(anio < 1900 || anio > 2050) return false;

    // Meses
    if(mes< 1 || mes > 12) return false;

    // Dias

    int cantDias[] = {31,28,31,30,31,30,31,31,30,31,30,31}; // Dias de cada mes en años normales

    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){ // calculo para febrero en año bisiesto
        cantDias[1] = 29; // Febrero pasa a tener 1 dia mas
    }

    if (dia <1 || dia > cantDias[mes - 1]) return false; // aca se valida el dia finalmente

    return true; // Si ninguno de los pasos dio FALSE se returna TRUE
}
