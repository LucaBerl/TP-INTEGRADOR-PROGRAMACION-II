
#pragma once
#include "../Fecha/fecha.h"


class camionesManager{


public:

    void altaCamion();
    void bajaCamion();
    bool verificacionVencida(const Fecha &fecha);
    bool actualizarVerificacion();
    void listarTodos();
    void mostrarKmPorCamion();
    void listarEnViaje();
    void listarSinAsignar();
    void mostrarVerificaciones();
    void modificarVerificacion();
    void mostrarPorAntiguedad();



};
