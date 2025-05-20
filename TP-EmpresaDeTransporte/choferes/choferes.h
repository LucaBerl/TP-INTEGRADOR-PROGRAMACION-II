#pragma once

#include "../camiones/camiones.h"
#include "../Fecha/fecha.h"
#include <string>

class Choferes
{

private:
    int _id; //En revision, se puede quitar
    bool _asignado;  //booleano para verificar si tiene o no tiene camion asignado
    Camiones _camionAsignado;  //Objeto del camion que se le asigna al chofer
    int _dni;
    char _nombre[30];
    char _apellido[30];
    int _experiencia;
    Fecha _vencimientoLicencia;
    bool _aptoCircular;
    bool _disponibilidad;
    float _kmMensuales[12];
    bool _estado; //define si el registro esta o no activo

public:
    //Constructor:

    Choferes();

    //Setters:

    void set_id(int id);
    void set_asignado(bool asignado);
    void set_camionAsignado(const Camiones& camionasignado);
    bool set_dni(int dni);
    bool set_nombre(std::string nombre);
    bool set_apellido(std::string apellido);
    bool set_experiencia(int experiencia);
    void set_vencimientoLicencia(const Fecha &fechaVencimiento);
    void set_aptoCircular(bool aptoCircular);
    void set_disponibilidad(bool disponibilidad);
    bool set_kmMensuales(float km,int mes); //Lo saremos para ir sumando los kilometros mensuales
    void set_kmMensuales(); //inicializa el vector en 0
    std::string toCSV();
    bool set_estado(bool e){_estado=e;}

    //Getters:

    int get_id()const;
    const Camiones& get_camionAsignado()const;
    int get_dni()const;
    std::string get_nombre()const;
    std::string get_apellido()const;
    int get_experiencia()const;
    const Fecha& get_vencimientoLicencia()const;
    bool get_aptoCircular()const;
    bool get_disponibilidad()const;
    const float* get_kmMensuales()const; //Devuelve el vector entero
    bool get_estado(){return _estado;}



};
