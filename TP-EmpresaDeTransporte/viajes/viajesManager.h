#pragma once
#include "viajes.h"


class viajesManager{

public:
    void crearViaje();
    void seleccionarCarga(Viajes &viaje);
    void seleccionarChofer(Viajes &viaje);
    void seleccionarCiudades(Viajes &viaje);
    void calcularTiempo(Viajes &viaje);
    void mostrarResumen(Viajes &viaje);
    bool actualizarEstados();
    void listarActivos();
    void listarHistorial();

};
