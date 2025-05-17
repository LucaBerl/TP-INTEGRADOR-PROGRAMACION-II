
#pragma once
#include "../Fecha/fecha.h"


class camionesManager{


public:

    void altaCamion();
    void bajaCamion();
    bool verificacionVencida(Fecha &fecha);
    bool actualizarVerificacion();
    void listarTodos();



};
