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

    bool guardar(Choferes registro);
    int getCantidadRegistros();

    Choferes leer(int pos);
};
