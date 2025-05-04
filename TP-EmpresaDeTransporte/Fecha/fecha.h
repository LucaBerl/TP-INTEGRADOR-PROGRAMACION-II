#pragma once


class Fecha{
    private:

        int _dia, _mes, _anio;

    public:

        Fecha();

        bool Cargar(int dia, int mes, int anio);
        void Mostrar();

        bool set_Dia(int dia);
        bool set_Mes(int mes);
        bool set_Anio(int anio);

        int get_Dia();
        int get_Mes();
        int get_Anio();

};
