#pragma once
#include <string>

class Fecha{
    private:

        int _dia, _mes, _anio;

    public:

        Fecha();
        Fecha(int dia, int mes, int anio);

        bool Cargar(int dia, int mes, int anio);
        void Mostrar()const;
        void Mostrar(int dia, int mes, int anio)const;

        std::string toString()const;

        bool set_Dia(int dia);
        bool set_Mes(int mes);
        bool set_Anio(int anio);
        bool validarFecha(int dia, int mes, int anio);

        int get_Dia()const;
        int get_Mes()const;
        int get_Anio()const;


};
