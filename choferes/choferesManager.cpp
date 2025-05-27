#include "choferesManager.h"
#include "choferes.h"
#include <iostream>
#include "choferesArchivo.h"
#include "../camiones/camiones.h"
#include "../camiones/camionesManager.h"
#include "../camiones/camionesArchivo.h"
#include <ctime>
#include <conio.h>
#include <iomanip>

using namespace std;

void choferesManager::cargarChofer()
{

    system("cls");

    Choferes choferes; //crea el objeto llamando al constructor vacio
    choferesArchivo cArchivo;
    Fecha fechaVencimiento;

    int id, dni, experiencia, dia, mes, anioFecha, anio;
    string nombre, apellido;
    bool aptoCircular, disponibilidad, estado, validacion;

///ALTA CHOFER//////////////////////////////////////////////////////////////

    cout<< endl << "ALTA CHOFER";

///ID///////////////////////////////////////////////////////////////////////

//    while (true)
//    {
//        cout << endl << endl << "Ingresar ID: ";
//        cin >> id;
//        if (cin.fail())
//        {
//            cin.clear(); // Limpia el estado de error
//            cin.ignore(1000, '\n'); // Descarta el resto de la línea
//            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
//            continue;
//        }
//        if (choferes.set_id(id))
//        {
//            cout << " Guardado correcto ✔" << endl;
//            cin.ignore(1000, '\n'); // Por si quedan residuos
//
//            break; // Salir del bucle, entrada válida
//        }
//        else
//        {
//            cout << "ID invalido." << endl;
//        }
//    }

/// Creacion de ID automatica

    choferes.set_id(cArchivo.get_ultimoID());


///DNI///////////////////////////////////////////////////////////

    while (true)
    {
        cout << endl << endl << "Ingresar DNI: ";
        cin >> dni;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (choferes.set_dni(dni))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "DNI invalido." << endl;
        }
    }

///NOMBRE//////////////////////////////////////////////////////

    do
    {
        cout << endl << endl << "Ingresar nombre/s: ";
        getline(cin, nombre);

        validacion = choferes.set_nombre(nombre);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Nombre inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///APELLIDO//////////////////////////////////////////////////

    do
    {
        cout << endl << endl << "Ingresar apellido/s: ";
        getline(cin, apellido);

        validacion = choferes.set_apellido(apellido);

        if (validacion)
        {
            cout << " Guardado correcto ✔" << endl;
        }
        else
        {
            cout << endl << "Apellido inválido, o demasiado largo. Intente de vuelta" << endl;
        }

    }
    while (!validacion);

///AÑOS EXPERIENCIA////////////////////////////////////////

    while (true)
    {
        cout << endl << endl << "Ingresar años de experiencia: ";
        cin >> experiencia;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (choferes.set_experiencia(experiencia))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "Invalido." << endl;
        }
    }

///VENCIMIENTO LICENCIA//////////////////////////////////////

    cout << endl << endl << "Ingresar la fecha del vencimiento de la licencia de conducir: ";

    while (true)
    {
        cout << endl << "Dia: ";
        cin >> dia;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (fechaVencimiento.set_Dia(dia))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "Dia inválido, ingrese nuevamente" << endl;
        }
    }

    while (true)
    {
        cout << endl << "Mes: ";
        cin >> mes;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (fechaVencimiento.set_Mes(mes))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "Mes inválido, ingrese nuevamente" << endl;
        }
    }

    while (true)
    {
        cout << "Año: ";
        cin >> anioFecha;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (fechaVencimiento.set_Anio(anioFecha))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "Año inválido, ingrese nuevamente" << endl;
        }
    }

    choferes.set_vencimientoLicencia(fechaVencimiento);

    system ("cls");

///RESUMEN///////////////////////////////////////

    cout << "RESUMEN" << endl;

    cout << endl << "ID: " << choferes.get_id();

    cout << endl << "DNI: " << choferes.get_dni();

    cout << endl << "Nombre/s: " << choferes.get_nombre();

    cout << endl << "Apellido/s: " <<choferes.get_apellido();

    cout << endl << "Años de experiencia: " << choferes.get_experiencia();

    cout << endl << "Fecha de vencimiento de la licencia de conducir: ";
    fechaVencimiento.Mostrar();
    if(licenciaVencida(fechaVencimiento))
    {
        cout << endl << "Licencia de conducir vencida, el chofer se dará de alta como 'no apto para circular' hasta renovar la licencia de conducir.";
        choferes.set_aptoCircular(0);
    }
    else
    {
        cout << endl << "Apto Circular ✔";
    }

///CONFIRMACION Y GUARDADO//////////////////////////////////


    cout << endl << endl << "Confirmar alta de chofer?";

    int opcion;

    do
    {
        cout << endl << "1 - Confirmar";
        cout << endl << "2 - Volver a ingresar" << endl;
        cout << endl;
        cin >> opcion;
    }
    while (opcion != 1 && opcion != 2);

    if (opcion == 1)
    {
        if(cArchivo.guardarChofer(choferes))
        {
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl;

        }
    }
    else
    {
        return;
    }

}

//BAJA/////////////////////////////////////////
void choferesManager::bajaChofer(){

    system("cls");

    Choferes choferes;
    choferesArchivo cArchivo;

    int opcionNumerica;

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

    int posicion, cantidadRegistros = cArchivo.getCantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(cArchivo.leerChoferes(i,choferes)){
            if (choferes.get_id() == opcionNumerica && choferes.get_estado() == 1){
                choferes.mostrar();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea dar de baja este chofer?";
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
            choferes.set_estado(0);
            if(cArchivo.guardarChoferModificado(posicion,choferes)){
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



void choferesManager::mostrarCantidadRegistros()
{
    choferesArchivo cArchivo;

    int cantidadRegistros=cArchivo.getCantidadRegistros();

    cout<<"La cantidad de registros son: "<<cantidadRegistros<<endl;
}


void choferesManager::listarTodos()
{


    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    ///Actualizar en viaje o no

    if(!actualizarLicencia()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(6) << "ID"
    << setw(10) << "DNI"
    << setw(20) << "NOMBRE"
    << setw(20) << "APELLIDO"
    << setw(7) << "EXP."
    << setw(15) << "VENC. LIC."
    << setw(8) << "APTO"
    << setw(12) << "EN VIAJE"
    << setw(30) << "CAMIÓN";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(cArchivo.leerChoferes(i,choferes)){
            if (choferes.get_estado() == 1){
                choferes.mostrar();
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");
}

void choferesManager::listarSinCamion()
{
    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    ///Actualizar en viaje o no

    if(!actualizarLicencia()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(6) << "ID"
    << setw(10) << "DNI"
    << setw(20) << "NOMBRE"
    << setw(20) << "APELLIDO"
    << setw(7) << "EXP."
    << setw(15) << "VENC. LIC."
    << setw(8) << "APTO"
    << setw(12) << "EN VIAJE"
    << setw(30) << "CAMIÓN";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(cArchivo.leerChoferes(i,choferes)){
            if (choferes.get_estado() == true && choferes.get_asignado() == false){
                choferes.mostrar();
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");
}
void choferesManager::listarConCamion(){

    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    ///Actualizar en viaje o no

    if(!actualizarLicencia()){
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(6) << "ID"
    << setw(10) << "DNI"
    << setw(20) << "NOMBRE"
    << setw(20) << "APELLIDO"
    << setw(7) << "EXP."
    << setw(15) << "VENC. LIC."
    << setw(8) << "APTO"
    << setw(12) << "EN VIAJE"
    << setw(30) << "CAMIÓN";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(cArchivo.leerChoferes(i,choferes)){
            if (choferes.get_estado() == true && choferes.get_asignado() == true){
                choferes.mostrar();
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");

}


/*void choferesManager::listarEnViaje()
{
    choferesArchivo cArchivo;
    Choferes registro;

    int cantidad = cArchivo.getCantidadRegistros();
    cout<<"Los choferes en viaje son: "<<endl;
    for(int i=0; i<cantidad; i++)
    {
        registro=cArchivo.leer(i);

        if(registro.get_enViaje())
        {
            cout<<"----------"<<endl;
            cout<<"ID: "<<registro.get_id()<<endl;
            cout<<"dni: "<<registro.get_dni()<<endl;
            cout<<"Apellido: "<<registro.get_apellido()<<endl;
            cout<<"Nombre: "<<registro.get_nombre()<<endl;
            cout<<"Experiencia: "<<registro.get_experiencia()<<endl;
            cout<<"Es apto para circular: "<<registro.get_aptoCircular()<<endl;
        }
    }
}*/

bool choferesManager::licenciaVencida(const Fecha &fecha)
{

    struct tm fechaVencimiento = {};
    /// Fecha de vencimiento = fecha original + 1 año

    fechaVencimiento.tm_year = fecha.get_Anio() - 1900 + 1;
    fechaVencimiento.tm_mon  = fecha.get_Mes() - 1;
    fechaVencimiento.tm_mday = fecha.get_Dia();

    time_t tiempoVencimiento = mktime(&fechaVencimiento);
    time_t tiempoActual = time(NULL);

    return (tiempoActual >= tiempoVencimiento); /// Devuelve true si la licencia está vencida, y false si todavia no lo está.
}

bool choferesManager::actualizarLicencia(){

    choferesArchivo cArchivo;
    Choferes chofer;

    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(cArchivo.leerChoferes(i,chofer)){

            if (chofer.get_estado() == true && chofer.get_aptoCircular() == true){

                Fecha ultimaVerificacion = chofer.get_vencimientoLicencia();
                if(licenciaVencida(ultimaVerificacion)){

                    chofer.set_aptoCircular(0);
                    if(!cArchivo.modificarChofer(chofer,i)){

                        cout << "Actualizacion incorrecta";
                        system("pause");
                        return false;
                    }
                }
            }else if(chofer.get_estado() == true && chofer.get_aptoCircular() == false){

                Fecha ultimaVerificacion = chofer.get_vencimientoLicencia();
               if(!licenciaVencida(ultimaVerificacion)){
                    chofer.set_aptoCircular(1);
                    if(!cArchivo.modificarChofer(chofer,i)){

                        cout << "Actualizacion incorrecta";
                        system("pause");
                        return false;
                    }
                }

            }
        }else{
            cout << "Lectura incorrecta en la posicion: " << i << endl;
            return false;
        }

    }


    return true;

}

void choferesManager::asignarCamion(){

    choferesArchivo cArchivo;
    Choferes chofer;

    listarSinCamion();

    cout << endl << endl << "Por favor, seleccionar ID de chofer para asignarle camión: ";

    int opcion;

    while (true) {
        cin >> opcion;

        if (cin.fail() || opcion <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionChofer;
    bool idChoferEncontrado = false;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistrosChoferes; i++){

        if(cArchivo.leerChoferes(i,chofer)){
            if (chofer.get_id() == opcion && chofer.get_estado() == true && chofer.get_asignado() == false){
                posicionChofer = i;
                idChoferEncontrado = true;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idChoferEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer al que se le pueda asignar un camión" << endl << endl;
        system("pause");
        return;
    }

    system("cls");

    Camiones camion;
    camionesManager caManager;
    camionesArchivo caArchivo;

    caManager.listarSinAsignar();

    cout << endl << endl << "Por favor, seleccionar el ID de camión para asignarle al chofer: ";

    while (true) {
        cin >> opcion;

        if (cin.fail() || opcion <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionCamion;
    bool idCamionEncontrado = false;
    int cantidadRegistrosCamiones = caArchivo.get_cantidadRegistros();

    for(int i = 0;i < cantidadRegistrosCamiones; i++){

        if(caArchivo.leerCamion(i,camion)){
            if (camion.get_idCamion() == opcion && camion.get_estado() == true){
                posicionCamion = i;
                idCamionEncontrado = true;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idCamionEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer al que se le pueda asignar un camión" << endl << endl;
        system("pause");
        return;
    }

    /// Resumen

    system("cls");

    cout << "Al chofer: '" << chofer.get_nombre() << " " << chofer.get_apellido() << "' Se le asignará el camion: '" << camion.get_marca()
    << " " << camion.get_modelo() << "'" << endl << endl << "1. Confirmar" << endl << "2.Volver" << endl;

    while (true) {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcion == 1){
            camion.set_choferAsignado(1);
            chofer.set_asignado(1);
            chofer.set_camionAsignado(camion);
            if(caArchivo.guardarCamionModificado(posicionCamion,camion) && cArchivo.modificarChofer(chofer,posicionChofer)){
                system("cls");
                cout << "ASIGNACIÓN CORRECTA ✔ " << endl << _getch() ;
                return;
            }else{
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }else if(opcion == 2){
            return;
        }

    }

    system("pause");



}

void choferesManager::desasignarCamion(){

    choferesArchivo cArchivo;
    Choferes chofer;

    listarConCamion();

    cout << endl << endl << "Por favor, seleccionar ID de chofer para quitar camión asignado: ";

    int opcion;

    while (true) {
        cin >> opcion;

        if (cin.fail() || opcion <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionChofer;
    bool idChoferEncontrado = false;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistrosChoferes; i++){

        if(cArchivo.leerChoferes(i,chofer)){
            if (chofer.get_id() == opcion && chofer.get_estado() == true && chofer.get_asignado() == true){
                posicionChofer = i;
                idChoferEncontrado = true;
                break;
            }
        }else{
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idChoferEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer al que se le pueda quitar la asignación de un camión" << endl << endl;
        system("pause");
        return;
    }

    system("cls");

    Camiones camion;
    camionesManager caManager;
    camionesArchivo caArchivo;

    cout << "Al chofer: '" << chofer.get_nombre() << " " << chofer.get_apellido() << "' Se le quitará la asignación del camion: '" << chofer.get_camionAsignado().get_marca()
    << " " << chofer.get_camionAsignado().get_modelo() << "'" << endl << endl << "1. Confirmar" << endl << "2.Volver" << endl;



    while (true) {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcion == 1){

            int cantidadRegistrosCamiones = caArchivo.get_cantidadRegistros();
            int idCamion = chofer.get_camionAsignado().get_idCamion();
            int posicionCamion;

            for(int i = 0;i < cantidadRegistrosCamiones; i++){

                if(caArchivo.leerCamion(i,camion)){
                    if (camion.get_idCamion() == idCamion && camion.get_estado() == true){
                        posicionCamion = i;
                        break;
                    }
                }else{
                    cout << "Lectura incorrecta";
                    system("pause");
                    return;
                }

            }
            camion.set_choferAsignado(0);
            chofer.set_asignado(0);
            chofer.set_camionAsignado(Camiones());
            if(caArchivo.guardarCamionModificado(posicionCamion,camion) && cArchivo.modificarChofer(chofer,posicionChofer)){
                system("cls");
                cout << "DESASIGNACIÓN CORRECTA ✔ " << endl << _getch() ;
                return;
            }else{
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }else if(opcion == 2){
            return;
        }

    }

    system("pause");


}

bool choferesManager::sincronizarCamionesAsignados() {

    choferesArchivo cArchivo;
    camionesArchivo caArchivo;
    Choferes chofer;
    Camiones camion;

    int cantidadChoferes = cArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidadChoferes; i++) {

        if (cArchivo.leerChoferes(i, chofer)) {

            if (chofer.get_estado() && chofer.get_asignado()) {

                int idCamion = chofer.get_camionAsignado().get_idCamion();

                if (caArchivo.buscarCamionPorId(idCamion, camion)) {

                    chofer.set_camionAsignado(camion);

                    if (!cArchivo.modificarChofer(chofer, i)) {

                        cout << "Error actualizando chofer en posición " << i << endl;
                        return false;

                    }
                }
            }
        }
    }

    return true;
}
