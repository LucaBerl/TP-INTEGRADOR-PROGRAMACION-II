
#pragma once
#include "camiones.h"

class camionesArchivo{




public:

    int get_cantidadRegistros();
    int get_ultimoID();
    bool leerCamion(int pos, Camiones &camion);
    bool guardarCamion(const Camiones &camion);
    bool guardarCamionModificado(int pos,Camiones &camion);



};
