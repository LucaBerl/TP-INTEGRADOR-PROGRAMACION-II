
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
///Paso 5:
calcularTiempo(viaje);
///Paso 6 y 7
mostrarResumen(viaje);

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
//system("pause");
}while (opcionCarga<1 || opcionCarga>21);

cout << endl << viaje.get_tipoCarga() << endl << endl;

system("pause");

}

///Paso 2 y 3:

void viajesManager::seleccionarChofer(Viajes &viaje){

system("cls");
cout << endl << "Aca vamos a elegir al chofer, cuando tengamos los archivos listos" << endl << endl;

/// Hace falta la clase chofer casi terminada. Aca se va a guardar el chofer asignado. Es necesario leer el archivo choferes.
system("pause");

}

/// Paso 4:

void viajesManager::seleccionarCiudades(Viajes &viaje){

system("cls");
Ciudades ciudadd, ciudad1, ciudad2;

cin.ignore();

cout << endl << "Busqueda de la 1er ciudad" << endl << endl;
ciudad1 = ciudadd.buscarCiudad();

cout << endl << "Busqueda de la 2da ciudad:" << endl << endl;
ciudad2 = ciudadd.buscarCiudad();


// Calcular la distancia entre las dos ciudades
double distancia = 1.2*ciudad1.calcularDistancia(ciudad2);
cout << endl << endl << "Distancia entre " << ciudad1.getCiudad() << " y " << ciudad2.getCiudad() << ": " << distancia << " km" << endl << endl;

viaje.set_ciudadOrigen(ciudad1);
viaje.set_ciudadDestino(ciudad2);
viaje.set_distancia(distancia);

system("pause");

}

//Paso 5:

void viajesManager::calcularTiempo(Viajes &viaje){

system("cls");

 //time_t es long long int

//    struct tm {
//  int tm_sec;   // segundos (0–60)
//  int tm_min;   // minutos (0–59)
//  int tm_hour;  // horas (0–23)
//  int tm_mday;  // día del mes (1–31)
//  int tm_mon;   // mes (0–11)  --> enero = 0, diciembre = 11
//  int tm_year;  // años desde 1900 --> para 2025, valor = 125
//  int tm_wday;  // día de la semana (0–6) --> domingo = 0
//  int tm_yday;  // día del año (0–365)
//  int tm_isdst; // horario de verano (positivo si está activo, 0 si no)
//};

    float segundos;

    const float velocidad_promedio = 90;

    float distancia = viaje.get_distancia();

    float tiempoEstimado = distancia / velocidad_promedio;

    int tiempoEstimadoHoras;

    tiempoEstimadoHoras = tiempoEstimado;

    int tiempoEstimadoMinutos = (tiempoEstimado-tiempoEstimadoHoras)*60;

    cout << "Tiempo Estimado: " << tiempoEstimadoHoras << ":" << tiempoEstimadoMinutos << " horas " << "(para una velocidad promedio de " << velocidad_promedio << " km/h)" << endl;

    /// A partir de aca lo que se hace es convertir el tiempo estimado a segundos, para agregarlo a la estructura "struct tm tm_info" en el campo "tm_sec".


    segundos = tiempoEstimado*3600;


    time_t t = time(NULL);  /// time_t es el tipo de dato --> time(null) asigna los segundos transcurridos desde 1 de enero de 1970 hasta ahora.


    struct tm tm_info = *localtime(&t);  /// localtime me convierte esos segundos a una fecha legible, y al asignarlo a la struct tm me queda cada valor separado(int hora, int minutos, int segundos, etc)


    tm_info.tm_sec += segundos; ///Le agrego a la estructura con la fecha y hora ACTUAL, los segundos del tiempo estimado.


    mktime(&tm_info);  /// mktime() normaliza la estructura, es decir, convierte el exceso de segundos en horas y minutos.


    cout << endl << "Fecha de llegada: "; /// Despues podemos mostrar cada campo de la estructura por separado para visualizar la fecha de llegada.

    cout << tm_info.tm_mday << "/" << (tm_info.tm_mon)+1 << "/" << (tm_info.tm_year)+1900;
    cout << " a las  ";
    if(tm_info.tm_hour < 10){cout << "0" <<tm_info.tm_hour<<":";}else{cout << tm_info.tm_hour<<":";}
    if(tm_info.tm_min < 10){cout << "0" <<tm_info.tm_min<<" hs";}else{cout << tm_info.tm_min<<" hs";}

    cout << endl << endl;

    ///Tambien podria hacerse directamente con la funcion asctime(&tm_info), pero devuelve todo en inglés.

    system("pause");

}

// Paso 6 y 7:

void viajesManager::mostrarResumen(Viajes &viaje){

/// Aca vamos a mostrar el resumen del viaje y confirmarlo. Luego lo guardamos en archivo.

system("cls");
cout << endl << "Espacio para mostrar resumen y guardar viaje." << endl << endl;
system("pause");

}
