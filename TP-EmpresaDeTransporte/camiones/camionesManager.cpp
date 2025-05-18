#include <iostream>
using namespace std;
#include "camionesManager.h"
#include "camiones.h"
#include "camionesArchivo.h"
#include <ctime>
#include <conio.h>
#include <iomanip>


void camionesManager::altaCamion(){

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
            cout << endl << "Patente inválida. Debe tener 6 O 7 caracteres. Intente de vuelta" << endl;
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
    }else{cout << endl << "Apto Circular ✔";}

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

    if (opcion == 1){
        if(caArchivo.guardarCamion(camion)){
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;

        }
    }
    else {return;}

}

void camionesManager::bajaCamion(){

    system("cls");

    Camiones camion;
    camionesArchivo caArchivo;

    int opcionNumerica;

    actualizarVerificacion();
    listarTodos();

    cout << endl << endl << "Por favor, seleccionar el ID del camión a dar de baja: ";

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion, cantidadRegistros = caArchivo.get_cantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_idCamion() == opcionNumerica && camion.get_estado() == 1){
                camion.mostrar();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea dar de baja este camion?";
                cout << endl << "1. SI" << endl << "2. NO" << endl;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado){
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){
            camion.set_estado(0);
            if(caArchivo.guardarCamionModificado(posicion,camion)){
                system("cls");
                cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;
                return;
            }else{
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }else if(opcionNumerica == 2){
            return;
        }

    }

}

bool camionesManager::verificacionVencida(const Fecha &fecha){

    struct tm fechaVencimiento = {};
    /// Fecha de vencimiento = fecha original + 1 año

    fechaVencimiento.tm_year = fecha.get_Anio() - 1900 + 1;
    fechaVencimiento.tm_mon  = fecha.get_Mes() - 1;
    fechaVencimiento.tm_mday = fecha.get_Dia();

    time_t tiempoVencimiento = mktime(&fechaVencimiento);
    time_t tiempoActual = time(NULL);

    return (tiempoActual >= tiempoVencimiento); /// Devuelve true si la verificacion está vencida, y false si todavia no lo está. (1 año de vigencia)
}

bool camionesManager::actualizarVerificacion(){

    camionesArchivo caArchivo;
    Camiones camion;

    int cantidadRegistros = caArchivo.get_cantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){

            if (camion.get_estado() == true && camion.get_aptoCircular() == true){

                Fecha ultimaVerificacion = camion.get_ultimaVerificacion();
                if(verificacionVencida(ultimaVerificacion)){

                    camion.set_aptoCircular(0);
                    if(!caArchivo.guardarCamion(camion)){

                        cout << "Actualizacion incorrecta";
                        system("pause");
                        break;
                    }
                }
            }
        }else{cout << "Lectura incorrecta";}

    }

    bool actualizacionCorrecta = true;
    return actualizacionCorrecta;

}

void camionesManager::listarTodos(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(10) << "PATENTE"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO"
    << setw(7) << "AÑO"
    << setw(7) << "PESO"
    << setw(10) << "VOLUMEN"
    << setw(16) << "VERIFICACION"
    << setw(6) << "APTO"
    << setw(6) << "DISP.";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1){
                camion.mostrar();
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");
}

void camionesManager::listarEnViaje(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO" << endl;

    cout << "--------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1 && camion.get_enViaje() == 1){
                cout << setw(3) << camion.get_idCamion()
                << setw(30) << camion.get_marca()
                << setw(30) << camion.get_modelo()
                << setw (10) << "En viaje 🚚🧭";

            }
            cout << endl;
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");



}

void camionesManager::listarSinAsignar(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(10) << "PATENTE"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO"
    << setw(8) << "AÑO"
    << setw(7) << "PESO"
    << setw(10) << "VOLUMEN"
    << setw(16) << "VERIFICACION"
    << setw(6) << "APTO";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();
    string aptoCircular;

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1 && camion.get_choferAsignado() == 0){
                if (camion.get_aptoCircular() == 1){aptoCircular = "✔";}else{aptoCircular = "🚫";}
                cout << setw(3) << camion.get_idCamion()
                << setw(10) << camion.get_patente()
                << setw(30) << camion.get_marca()
                << setw(30) << camion.get_modelo()
                << setw(7) << camion.get_anio()
                << setw(7) << camion.get_pesoCarga()
                << setw(10) << camion.get_volumenCarga()
                << setw(16) << camion.get_ultimaVerificacion().toString()
                << setw(6) << aptoCircular;
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");

}

void camionesManager::mostrarKmPorCamion(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO"
    << setw(5) << "ENE"
    << setw(5) << "FEB"
    << setw(5) << "MAR"
    << setw(5) << "ABR"
    << setw(5) << "MAY"
    << setw(5) << "JUN"
    << setw(5) << "JUL"
    << setw(5) << "AGO"
    << setw(5) << "SEP"
    << setw(5) << "OCT"
    << setw(5) << "NOV"
    << setw(5) << "DIC" << endl;

    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();
    const float *km;
    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1){
                km = camion.get_kmMensuales();
                cout << setw(3) << camion.get_idCamion()
                << setw(30) << camion.get_marca()
                << setw(30) << camion.get_modelo();
                for (int j = 0;j < 12; j++){
                    cout << setw(5) << km[i];
                }

            }
            cout << endl;
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");

}

void camionesManager::mostrarVerificaciones(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO"
    << setw(15) << "ULT. VERIF."
    << setw(10) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();
    string  estado;

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1){
                if (verificacionVencida(camion.get_ultimaVerificacion())){estado = "❗VENCIDA";}else{estado = "✔";}
                cout << setw(3) << camion.get_idCamion()
                << setw(30) << camion.get_marca()
                << setw(30) << camion.get_modelo()
                << setw(15) << camion.get_ultimaVerificacion().toString()
                << setw (10) << estado;

            }
            cout << endl;
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");


}

void camionesManager::modificarVerificacion(){

    camionesArchivo caArchivo;
    Camiones camion;

    ///Actualizar en viaje o no

    if(!actualizarVerificacion()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
    << setw(30) << "MARCA"
    << setw(30) << "MODELO"
    << setw(15) << "ULT. VERIF."
    << setw(10) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = caArchivo.get_cantidadRegistros();
    string  estado = "❗VENCIDA";

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_estado() == 1 && verificacionVencida(camion.get_ultimaVerificacion()) == 1){
                cout << setw(3) << camion.get_idCamion()
                << setw(30) << camion.get_marca()
                << setw(30) << camion.get_modelo()
                << setw(15) << camion.get_ultimaVerificacion().toString()
                << setw (10) << estado;
                cout << endl;
            }

        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;

    cout << endl << endl << "Por favor, seleccionar el ID del camión para actualizar verificación: ";

    int opcionNumerica;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicion;
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_idCamion() == opcionNumerica){
                posicion = i;
                idEncontrado = true;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un camion que tenga que actualizar su verificacion" << endl << endl;
        system("pause");
        return;
    }
    else{
        system("cls");

        cout << "SE ACTUALIZARA LA FECHA DEL CAMION PARA EL DIA DE HOY" << endl;
        cout << endl << "1.Confirmar";
        cout << endl << "2.Volver";

        while (true) {
            cin >> opcionNumerica;

            if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descarta el resto de la línea
                cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            }else if(opcionNumerica == 1){
                Fecha fechaHoy; /// Aca tego que hacer una fecha para qe me tome la fecha de hoy y se la pase  a ultimaVerificacion
                camion.set_ultimaVerificacion(fechaHoy);
                if(caArchivo.guardarCamionModificado(posicion,camion)){
                    system("cls");
                    cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;
                    return;
                }else{
                    cout << "Error en el guardado" << _getch() ;
                    return;
                }
            }else if(opcionNumerica == 2){
                return;
            }

        }
    }

}
