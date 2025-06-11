#pragma once
#include <string>
#include "../Fecha/fecha.h"


class choferesManager{


public:

void cargarChofer();
bool licenciaVencida(const Fecha &fecha);
bool actualizarLicencia();
void mostrarLicencias();
void modificarLicencia();
void bajaChofer();
void mostrarCantidadRegistros();
void listarTodos();
void listarSinCamion();
void listarConCamion();
void listarEnViaje();
void asignarCamion();
void desasignarCamion();
bool sincronizarCamionesAsignados();
void mostrarKmPorChofer();
bool buscarChoferesParaAsignar();
bool buscarChoferesParaDesasignar();
void editarChofer();
void editarDni(int posicion);
void editarNombre(int posicion);
void editarExperiencia(int posicion);
};
