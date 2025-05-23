#pragma once
#include <string>
#include "../Fecha/fecha.h"
class choferesManager{
private:

public:

void cargarChofer();
bool licenciaVencida(const Fecha &fecha);
bool actualizarLicencia();
bool bajaChofer();
void modificarChofer();
void mostrarCantidadRegistros();
void listarTodos();
void listarSinCamion();
void listarEnViaje();
void asignarCamion();
};
