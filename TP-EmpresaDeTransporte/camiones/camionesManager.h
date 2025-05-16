
#pragma once
#include "../Fecha/fecha.h"


class camionesManager{


public:

    void altaCamion();
    bool verificacionVencida(Fecha &fecha);
    bool actualizarVerificacion();
    void listarTodos();



};
