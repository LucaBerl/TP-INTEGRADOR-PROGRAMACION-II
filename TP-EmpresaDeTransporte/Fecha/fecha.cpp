#include <iostream>
using namespace std;
#include "fecha.h"

Fecha::Fecha(){

    _dia = 0;
    _mes = 0;
    _anio = 0;
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

int Fecha::get_Dia(){return _dia;}

int Fecha::get_Mes(){return _mes;}

int Fecha::get_Anio(){return _anio;}


void Fecha::Mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
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
