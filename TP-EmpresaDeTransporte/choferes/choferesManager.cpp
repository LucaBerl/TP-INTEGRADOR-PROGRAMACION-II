#include "choferesManager.h"
#include "choferes.h"
#include <string>
#include <iostream>
#include "choferesArchivo.h"
#include <sstream>
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

    while (true)
    {
        cout << endl << endl << "Ingresar ID: ";
        cin >> id;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (choferes.set_id(id))
        {
            cout << " Guardado correcto ✔" << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos

            break; // Salir del bucle, entrada válida
        }
        else
        {
            cout << "ID invalido." << endl;
        }
    }


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
void choferesManager::modificarChofer()
{

}

/*bool choferesManager::bajaChofer()
{
    Choferes reg;
    choferesArchivo archivo;

    int id;

    cout<<"Ingrese el ID del chofer para dar de baja: "<<endl;
    cin>>id;

    int pos = archivo.buscarRegistro(id);
    if(pos==-1) return false;

//leer registro del archivo choferes

//    reg=archivo.leer(pos);//en reg esta el registro a borrar
    reg.set_estado(false);
    return archivo.modificarChofer(reg, pos);
}*/


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
    << setw(20) << "EXPERIENCIA"
    << setw(20) << "VENCIMIENTO/LIC"
    << setw(10) << "APTO";

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

/*void choferesManager::listarDisponibles()
{
    choferesArchivo cArchivo;
    Choferes reg;

    int cantidad = cArchivo.getCantidadRegistros();
    cout<<"Los choferes disponibles son: "<<endl;
    for(int i=0; i<cantidad; i++)
    {
        reg=cArchivo.leer(i);

        if(reg.get_enViaje())
        {
            cout<<"----------"<<endl;
            cout<<"ID: "<<reg.get_id()<<endl;
            cout<<"dni: "<<reg.get_dni()<<endl;
            cout<<"Apellido: "<<reg.get_apellido()<<endl;
            cout<<"Nombre: "<<reg.get_nombre()<<endl;
            cout<<"Experiencia: "<<reg.get_experiencia()<<endl;
            cout<<"Es apto para circular: "<<reg.get_aptoCircular()<<endl;
        }
    }
}*/

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
