#include <iostream>
using namespace std;
#include "camionesManager.h"
#include "camiones.h"
#include "camionesArchivo.h"
#include <ctime>


bool camionesManager::altaCamion(){

    system("cls");

    Camiones camion;
    Fecha fechaVerificacion;
    camionesArchivo caArchivo;

    string marca, modelo, patente;
    int dia, mes, anioFecha,anio;
    float peso, volumen;
    bool validacion;

///MARCA/////////////////////////////////////////////////////////////////////////////////////////////

    cout << endl << "ALTA DE CAMION";
     do {
        cout << endl << endl << "Ingresar marca: ";
        cin.ignore();
        getline(cin, marca);

        validacion = camion.set_marca(marca);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Nombre inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    } while (!validacion);

///MODELO////////////////////////////////////////////////////////////////////////////////////////////

    do{
    cout << endl << endl << "Ingresar modelo: ";
    getline(cin, modelo);
    validacion = camion.set_modelo(modelo);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Nombre inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }while (!validacion);

///PATENTE///////////////////////////////////////////////////////////////////////////////////////////

    do{
    cout << endl << endl << "Ingresar patente (AA123AA o AAA123): ";
    getline(cin, patente);
    validacion = camion.set_patente(patente);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Patente inválida. Debe tener 6 u 8 caracteres. Intente de vuelta" << endl;
        }

    }while (!validacion);

///AÑO///////////////////////////////////////////////////////////////////////////////////////////////

    do{
    cout << endl << endl << "Ingresar año de patentamiento: ";
    cin >> anio;
    validacion = camion.set_anio(anio);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Año invalido, ingrese de vuelta (Rango 1960 a 2025)" << endl;
        }

    }while (!validacion);

///VERIFICACION//////////////////////////////////////////////////////////////////////////////////////

    cout << endl << endl << "Ingresar fecha de última verificacion: ";
    do{
    cout << endl << "Dia: ";
    cin >> dia;
    validacion = fechaVerificacion.set_Dia(dia);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Dia invalido, ingrese nuevamente" << endl;
        }

    }while (!validacion);



    do{
    cout << "Mes: ";
    cin >> mes;
     validacion = fechaVerificacion.set_Mes(mes);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Mes invalido, ingrese nuevamente" << endl;
        }

    }while (!validacion);

    do{
    cout << "Año: ";
    cin >> anioFecha;
     validacion = fechaVerificacion.set_Anio(anioFecha);


        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Año invalido, ingrese nuevamente" << endl;
        }

    }while (!validacion);
    camion.set_ultimaVerificacion(fechaVerificacion);

///PESO//////////////////////////////////////////////////////////////////////////////////////////////

    do{
    cout << endl << endl << "Peso máximo soportado (Entre 500 y 70.000 kg): ";
    cin >> peso;
     validacion = camion.set_pesoCarga(peso);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Peso fuera de rango, intente de vuelta" << endl;
        }

    }while (!validacion);

/// VOLUMEN /////////////////////////////////////////////////////////////////////////////////////////

    do{
    cout << endl << endl << "Volumen máximo de carga (Entre 1 y 150 mts\u00B3): ";
    cin >> volumen;
    validacion = camion.set_volumenCarga(volumen);

        if (validacion) {
            cout << " Guardado correcto ✔" << endl;
        } else {
            cout << endl << "Volumen fuera de rango, intente de vuelta" << endl;
        }

    }while (!validacion);

    camion.set_idCamion(caArchivo.get_ultimoID());
    system("cls");

/// RESUMEN /////////////////////////////////////////////////////////////////////////////////////////


    cout << "RESUMEN" << endl;

    cout << endl << "ID: " << camion.get_idCamion();

    cout << endl << "Marca: " << camion.get_marca();

    cout << endl << "Modelo: " << camion.get_modelo();

    cout << endl << "Patente: " << camion.get_patente();

    cout << endl << "Año: " << camion.get_anio();

    cout << endl << "Fecha ultima verificacion: ";
    fechaVerificacion.Mostrar();
    if(verificacionVencida(fechaVerificacion)){
        cout << endl << "Verificacion vencida, el camion se dará de alta como 'no apto para circular' hasta modificar la verificacion.";
        camion.set_aptoCircular(0);
    }

    cout << endl << "Peso máximo: " << camion.get_pesoCarga();

    cout << endl << "Volumen máximo: " << camion.get_volumenCarga();

/// CONFIRMACION Y GUARDADO /////////////////////////////////////////////////////////////////////////

    cout << endl << endl << "Confirmar alta de camion?";

    int opcion;

    do{
        cout << endl << "1 - Confirmar";
        cout << endl << "2 - Volver a ingresar" << endl;
        cout << endl;
        cin >> opcion;
    }while (opcion != 1 && opcion != 2);

    system("pause");

}

bool camionesManager::verificacionVencida(Fecha &fecha){

    struct tm fechaVencimiento = {};
    /// Fecha de vencimiento = fecha original + 1 año

    fechaVencimiento.tm_year = fecha.get_Anio() - 1900 + 1;
    fechaVencimiento.tm_mon  = fecha.get_Mes() - 1;
    fechaVencimiento.tm_mday = fecha.get_Dia();

    time_t tiempoVencimiento = mktime(&fechaVencimiento);
    time_t tiempoActual = time(NULL);

    return (tiempoActual >= tiempoVencimiento); /// Devuelve true si la verificacion está vencida, y false si todavia no lo está. (1 año de vigencia)
}


