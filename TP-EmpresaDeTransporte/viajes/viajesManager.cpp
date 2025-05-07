
#include "viajesManager.h"
#include "viajes.h"
#include "../Carga/carga.h"
#include <iostream>
using namespace std;

void viajesManager::crearViaje(){


    cout << endl << "SECCION DE CREACION DE VIAJES" << endl;
    Viajes viaje;

//    Pasos:
//
//        Paso 1: Elegir tipo de carga(lista predefinida), peso y volumen.
//        Paso 2 : Mostrar choferes disponibles segun: disponibilidad, peso maximo de camion asignado y volumen maximo de camion asignado.
//        Paso 3 : Elegir chofer para viaje
//        Paso 4: Seleccionar ciudades origen/destino
//        Paso 5: Calcular distancia y tiempo de viaje
//        Paso 6: Mostrar resumen de todos los datos
//        Paso 7: Confirmar viaje y guardar en archivos (archivos viajes.dat, choferes.dat y camiones.dat )



/// Paso 1:

int opcionCarga;
Carga tCarga;
do{
system("cls");
cout << endl << "Por favor, seleccionar el ID de tipo de carga a transportar: " << endl << endl;

tCarga.mostrar();

cout << endl;
cin >> opcionCarga;

if(opcionCarga>0 && opcionCarga<22){
    if(viaje.set_tipoCarga(tCarga.get_tipoCarga(opcionCarga-1))){
        cout << endl << "Opcion guardada" << endl;
    }
    else{cout << endl << "No se pudo guardar la carga" << endl;}
}else{cout << endl << "Opcion invalida, intente de vuelta" << endl;}
system("pause");
}while (opcionCarga<1 || opcionCarga>21);

cout << endl << viaje.get_tipoCarga();



system("pause");

}
