
#pragma once
#include "../Fecha/fecha.h"
#include<string>

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
    void editarCamion();
    void editarMarca(int posicion);
    void editarPatente(int posicion);
    void editarAnio(int posicion);
    void editarPesoVolumen(int posicion);

};
