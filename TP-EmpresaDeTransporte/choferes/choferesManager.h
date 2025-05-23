#pragma once
#include <string>
#include "../Fecha/fecha.h"
class choferesManager{
private:

public:

void cargarChofer();
bool licenciaVencida(const Fecha &fecha);
bool bajaChofer();
void modificarChofer();
void mostrarCantidadRegistros();
void listarTodos();
void listarDisponibles();
void listarEnViaje();
};
