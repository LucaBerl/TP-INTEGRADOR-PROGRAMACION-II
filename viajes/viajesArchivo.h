#pragma oce
#include "viajes.h"

class viajesArchivo {

public:
    bool guardarViaje(const Viajes &viaje);
    int get_cantidadRegistros();
    bool leerViaje(int pos, Viajes &viaje);
    int get_ultimoID();
    bool guardarViajeModificado(int pos, Viajes &viaje);

};
