#include <iostream>
using namespace std;
#include "camionesManager.h"
#include "../Fecha/fecha.h"
#include "camiones.h"


bool camionesManager::altaCamion(){

    system("cls");
//    int _idCamion;
//    char _patente[8];
//    char _marca[30];
//    char _modelo[30];
//    int _anio;
//    float _pesoCarga;
//    float _volumenCarga;
//    float _kmMensuales[12];
//    Fecha _ultimaVerificacion;
//    bool _aptoCircular;
//    bool _disponibilidad;


    Camiones camion;

    string marca, modelo, patente, anio;
    int dia, mes, anioFecha;
    float peso, volumen;

    cout << endl << "ATLA DE CAMION";

    cout << endl << endl << "Ingresar marca: ";
    cin.ignore();
    getline(cin, marca);
    cout << endl << endl << "Ingresar modelo: ";
    getline(cin, modelo);
    cout << endl << endl << "Ingresar patente (AA123AA o AAA123): ";
    getline(cin, patente);
    cout << endl << endl << "Ingresar año de patentamiento: ";
    getline(cin, anio);
    cout << endl << endl << "Ingresar fecha de última verificacion: ";
    cout << endl << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anioFecha;

    cout << endl << endl << "Peso máximo soportado (Entre 500 y 70.000 kg): ";
    cin >> peso;
    cout << endl << endl << "Volumen máximo de carga (Entre 1 y 150 mts\u00B3): ";
    cin >> volumen;

    system("cls");

    cout << "RESUMEN" << endl;

    cout << endl << "Marca: " << marca;
    cout << endl << "Modelo: " << modelo;
    cout << endl << "Modelo: " << patente;
    cout << endl << "Año: " << anio;
    cout << endl << "Fecha ultima verificacion: " << dia << "/" << mes << "/" << anio ;
    cout << endl << "Peso máximo: " << peso;
    cout << endl << "Volumen máximo: " << volumen;

    cout << endl << endl << "Confirmar alta de camion?";
    cout << endl << endl << "1 - Confirmar";
    cout << endl << "2 - Volver a ingresar" << endl << endl;




    system("pause");
}
