#pragma once
#include "viajes.h"


class viajesManager{

public:
    void crearViaje();
    void seleccionarCarga(Viajes &viaje);
    bool seleccionarChofer(Viajes &viaje);
    void seleccionarCiudades(Viajes &viaje);
    void calcularTiempo(Viajes &viaje);
    void mostrarResumen_GuardarViaje(Viajes &viaje);
    bool actualizarEstados();
    void listarActivos();
    void listarHistorial();
    bool listarChoferesDisponibles(Viajes &viaje);
    bool seleccionarCliente(Viajes &viaje);

};
