#pragma once
#include <string>
#include "choferes.h"


class choferesArchivo
{

private:
    std::string _nombreArchivo;

public:
    choferesArchivo();
    choferesArchivo(std::string nombreArchivo);

    bool guardarChofer(Choferes registro);
    int getCantidadRegistros();
    int buscarRegistro(int id);
    bool modificarChofer(Choferes reg, int pos);

    bool leerChoferes(int pos,  Choferes &choferes);
    int get_ultimoID();
};
