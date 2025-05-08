
#include "viajesManager.h"
#include "../Carga/carga.h"
#include "../Ciudades/ciudades.h"
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


///Paso 1:
seleccionarCarga(viaje);
///Paso 2 y 3:
seleccionarChofer(viaje);
///Paso 4:
seleccionarCiudades(viaje);

system("pause");
}

/// Paso 1:

void viajesManager::seleccionarCarga(Viajes &viaje){

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

///Paso 2 y 3:

void viajesManager::seleccionarChofer(Viajes &viaje){

/// Hace falta la clase chofer casi terminada. Aca se va a guardar el chofer asignado. Es necesario leer el archivo choferes.

}

/// Paso 4:

void viajesManager::seleccionarCiudades(Viajes &viaje){


Ciudades ciudadd, ciudad1, ciudad2;

cin.ignore();

cout << endl << "Busqueda de la 1er ciudad" << endl << endl;
ciudad1 = ciudadd.buscarCiudad();
cout << endl << "Busqueda de la 2da ciudad:" << endl << endl;
ciudad2 = ciudadd.buscarCiudad();


// Calcular la distancia entre las dos ciudades
double distancia = 1.2*ciudad1.calcularDistancia(ciudad2);
cout << endl << endl << "Distancia entre " << ciudad1.getCiudad() << " y " << ciudad2.getCiudad() << ": " << distancia << " km" << endl;



}

