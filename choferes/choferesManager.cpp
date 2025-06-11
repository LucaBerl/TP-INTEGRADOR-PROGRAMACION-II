#include "choferesManager.h"
#include "choferes.h"
#include <iostream>
#include "choferesArchivo.h"
#include "../camiones/camiones.h"
#include "../camiones/camionesManager.h"
#include "../camiones/camionesArchivo.h"
#include "../viajes/viajesManager.h"
#include "../menues/menuChoferes.h"
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

///BAJA CHOFER////////////////////////////////////////////////////

void choferesManager::bajaChofer()
{

    system("cls");

    Choferes choferes;
    choferesArchivo cArchivo;


    int opcionNumerica;

    listarTodos();

    cout << endl << endl << "Por favor, seleccionar el ID del camión a dar de baja: ";

    while (true)
    {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0)
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else
        {

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion, cantidadRegistros = cArchivo.getCantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,choferes))
        {
            if (choferes.get_id() == opcionNumerica && choferes.get_estado() == 1)
            {
                choferes.mostrar();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea dar de baja este chofer?";
                cout << endl << "1. SI" << endl << "2. NO" << endl;
                break;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado)
    {
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true)
    {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2))
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else if(opcionNumerica == 1)
        {

            if (choferes.get_asignado() == true)
            {

                camionesArchivo caArchivo;
                Camiones camion;
                if (caArchivo.buscarCamionPorId(choferes.get_camionAsignado().get_idCamion(), camion))
                {

                    int posicionCamion = caArchivo.buscarRegistro(choferes.get_camionAsignado().get_idCamion());

                    if (posicionCamion >= 0)
                    {

                        camion.set_choferAsignado(0);
                        if(caArchivo.guardarCamionModificado(posicionCamion,camion))
                        {
                            choferes.set_estado(0);
                        }
                        else
                        {
                            cout << endl << "Sincronización incorrecta" << endl;
                            system("pause");
                            return;
                        }
                    }
                }
            }
            if(cArchivo.guardarChoferModificado(posicion,choferes))
            {
                system("cls");
                cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;
                return;
            }
            else
            {
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }
        else if(opcionNumerica == 2)
        {
            return;
        }

    }

}

///MOSTRAR CANTIDAD DE REGISTROS///////////////////////////////////////////////////

void choferesManager::mostrarCantidadRegistros()
{
    choferesArchivo cArchivo;

    int cantidadRegistros=cArchivo.getCantidadRegistros();

    cout<<"La cantidad de registros son: "<<cantidadRegistros<<endl;
}

///LISTAR TODOS////////////////////////////////////////////////////

void choferesManager::listarTodos()
{


    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    viajesManager vManager;
    if(!vManager.actualizarEstados())
    {
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    if(!actualizarLicencia())
    {
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
         << setw(30) << "CAMIÓN"
         << setw(8) << "APTO"
         << setw(12) << "EN VIAJE";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,choferes))
        {
            if (choferes.get_estado() == 1)
            {
                choferes.mostrar();
                cout << endl;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
        }

    }

    cout << endl << endl;
    system("pause");
}

///LISTAR SIN CAMION/////////////////////////////////////////////////////////

void choferesManager::listarSinCamion()
{
    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    viajesManager vManager;
    if(!vManager.actualizarEstados())
    {
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    if(!actualizarLicencia())
    {
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
         << setw(30) << "CAMIÓN"
         << setw(8) << "APTO"
         << setw(12) << "EN VIAJE";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,choferes))
        {
            if (choferes.get_estado() == true && choferes.get_asignado() == false)
            {
                choferes.mostrar();
                cout << endl;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
        }

    }

    cout << endl << endl;
    system("pause");
}

///LISTAR CON CAMION////////////////////////////////////////////////////////

void choferesManager::listarConCamion()
{

    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    viajesManager vManager;
    if(!vManager.actualizarEstados())
    {
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    if(!actualizarLicencia())
    {
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
         << setw(30) << "CAMIÓN"
         << setw(8) << "APTO"
         << setw(12) << "EN VIAJE";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,choferes))
        {
            if (choferes.get_estado() == true && choferes.get_asignado() == true)
            {
                choferes.mostrar();
                cout << endl;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
        }

    }

    cout << endl << endl;
    system("pause");

}

///LISTAR EN VIAJE//////////////////////////////////////////////////////

void choferesManager::listarEnViaje()
{

    choferesArchivo cArchivo;
    Choferes choferes;
    cout << left << fixed << setprecision(0);

    viajesManager vManager;
    if(!vManager.actualizarEstados())
    {
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    if(!actualizarLicencia())
    {
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
         << setw(30) << "CAMIÓN"
         << setw(8) << "APTO"
         << setw(12) << "EN VIAJE";

    cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,choferes))
        {
            if (choferes.get_estado() == true && choferes.get_enViaje() == true)
            {
                choferes.mostrar();
                cout << endl;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
        }

    }

    cout << endl << endl;
    system("pause");
}

///LICENCIA VENCIDA///////////////////////////////////////////////////////

bool choferesManager::licenciaVencida(const Fecha &fecha)
{

    struct tm fechaVencimiento = {};
    /// Fecha de vencimiento

    fechaVencimiento.tm_year = fecha.get_Anio() - 1900;
    fechaVencimiento.tm_mon  = fecha.get_Mes() - 1;
    fechaVencimiento.tm_mday = fecha.get_Dia();

    time_t tiempoVencimiento = mktime(&fechaVencimiento);
    time_t tiempoActual = time(NULL);

    return (tiempoActual > tiempoVencimiento); /// Devuelve true si la licencia está vencida, y false si todavia no lo está.
}

///ACTUALIZAR LICENCIA////////////////////////////////////////////

bool choferesManager::actualizarLicencia()
{

    choferesArchivo cArchivo;
    Choferes chofer;

    int cantidadRegistros = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {

            if (chofer.get_estado() == true && chofer.get_aptoCircular() == true)
            {

                Fecha ultimaRenovacion = chofer.get_vencimientoLicencia();
                if(licenciaVencida(ultimaRenovacion))
                {

                    chofer.set_aptoCircular(0);
                    if(!cArchivo.modificarChofer(chofer,i))
                    {

                        cout << "Actualizacion incorrecta";
                        system("pause");
                        return false;
                    }
                }
            }
            else if(chofer.get_estado() == true && chofer.get_aptoCircular() == false)
            {

                Fecha ultimaRenovacion = chofer.get_vencimientoLicencia();
                if(!licenciaVencida(ultimaRenovacion))
                {
                    chofer.set_aptoCircular(1);
                    if(!cArchivo.modificarChofer(chofer,i))
                    {

                        cout << "Actualizacion incorrecta";
                        system("pause");
                        return false;
                    }
                }

            }
        }
        else
        {
            cout << "Lectura incorrecta en la posicion: " << i << endl;
            return false;
        }

    }


    return true;

}

///MOSTRAR LICENCIAS///////////////////////////////////////////////
void choferesManager::mostrarLicencias()
{

    choferesArchivo cArchivo;
    Choferes chofer;
    cout << left << fixed << setprecision(0);

    if(!actualizarLicencia())
    {
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(15) << "ULT. ACT."
         << setw(10) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();
    string  estado;

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_estado() == 1)
            {
                if (licenciaVencida(chofer.get_vencimientoLicencia()))
                {
                    estado = "❗VENCIDA";
                }
                else
                {
                    estado = "✔";
                }
                cout << setw(3) << chofer.get_id()
                     << setw(30) << chofer.get_nombre()
                     << setw(30) << chofer.get_apellido()
                     << setw(15) << chofer.get_vencimientoLicencia().toString()
                     << setw (10) << estado;
                cout << endl;
            }

        }
        else
        {
            cout << "Lectura incorrecta en la posicion: " << i << endl;
            system("pause");
            break;
        }

    }

    cout << endl << endl;
    system("pause");


}
///MODIFICAR LICENCIA/////////////////////////////////////////////
void choferesManager::modificarLicencia()
{

    choferesArchivo cArchivo;
    Choferes chofer;
    cout << left << fixed << setprecision(0);


    if(!actualizarLicencia())
    {
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(15) << "ULT. ACT."
         << setw(10) << "ESTADO" << endl;

    cout << "---------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = cArchivo.getCantidadRegistros();
    string  estado = "❗VENCIDA";

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_estado() == 1 && licenciaVencida(chofer.get_vencimientoLicencia()) == 1)
            {
                cout << setw(3) << chofer.get_id()
                     << setw(30) << chofer.get_nombre()
                     << setw(30) << chofer.get_apellido()
                     << setw(15) << chofer.get_vencimientoLicencia().toString()
                     << setw (10) << estado;
                cout << endl;
            }

        }
        else
        {
            cout << "Lectura incorrecta en la posicion: " << i << endl;
            system("pause");
            break;
        }

    }

    cout << endl << endl;

    cout << endl << endl << "Por favor, seleccionar el ID del chofer para actualizar la licencia de conducir: ";

    int opcionNumerica;

    while (true)
    {
        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0)
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else
        {

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicion;
    bool idEncontrado = false;

    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_id() == opcionNumerica && licenciaVencida(chofer.get_vencimientoLicencia()) == 1)
            {
                posicion = i;
                idEncontrado = true;
                break;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idEncontrado)
    {
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer que tenga que actualizar su licencia" << endl << endl;
        system("pause");
        return;
    }
    else
    {
        system("cls");

        time_t t = time(NULL);
        struct tm tiempoHoy = *localtime(&t);

        Fecha fechaHoy(tiempoHoy.tm_mday,tiempoHoy.tm_mon+1,tiempoHoy.tm_year+1905);


        cout << "SE ACTUALIZARA LICENCIA DEL CHOFER PARA EL DIA DE HOY CON CINCO AÑOS MAS DE VIGENCIA" << fechaHoy.toString() << endl;

        cout << endl << "1.Confirmar";
        cout << endl << "2.Volver" << endl;

        while (true)
        {
            cin >> opcionNumerica;

            if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2))
            {
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descarta el resto de la línea
                cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            }
            else if(opcionNumerica == 1)
            {
                chofer.set_vencimientoLicencia(fechaHoy);
                if(cArchivo.guardarChoferModificado(posicion,chofer))
                {
                    system("cls");
                    cout << "GUARDADO CORRECTO ✔ " << endl << _getch() ;
                    return;
                }
                else
                {
                    cout << "Error en el guardado" << _getch() ;
                    return;
                }
            }
            else if(opcionNumerica == 2)
            {
                return;
            }

        }
    }

}
///ASIGNAR CAMION///////////////////////////////////////////////

void choferesManager::asignarCamion()
{

    choferesArchivo cArchivo;
    Choferes chofer;

    if(!buscarChoferesParaAsignar())
    {
        system("cls");
        cout << "Actualmente, no hay choferes disponibles para asignar" << endl << endl;
        system("pause");
        return;
    }

    listarSinCamion();

    cout << endl << endl << "Por favor, seleccionar ID de chofer para asignarle camión: ";

    int opcion;

    while (true)
    {
        cin >> opcion;

        if (cin.fail() || opcion <= 0)
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else
        {

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionChofer;
    bool idChoferEncontrado = false;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistrosChoferes; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_id() == opcion && chofer.get_estado() == true && chofer.get_asignado() == false)
            {
                posicionChofer = i;
                idChoferEncontrado = true;
                break;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idChoferEncontrado)
    {
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

    while (true)
    {
        cin >> opcion;

        if (cin.fail() || opcion <= 0)
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else
        {

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionCamion;
    bool idCamionEncontrado = false;
    int cantidadRegistrosCamiones = caArchivo.get_cantidadRegistros();

    for(int i = 0; i < cantidadRegistrosCamiones; i++)
    {

        if(caArchivo.leerCamion(i,camion))
        {
            if (camion.get_idCamion() == opcion && camion.get_estado() == true)
            {
                posicionCamion = i;
                idCamionEncontrado = true;
                break;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idCamionEncontrado)
    {
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer al que se le pueda asignar un camión" << endl << endl;
        system("pause");
        return;
    }

    /// Resumen

    system("cls");

    cout << "Al chofer: '" << chofer.get_nombre() << " " << chofer.get_apellido() << "' Se le asignará el camion: '" << camion.get_marca()
         << " " << camion.get_modelo() << "'" << endl << endl << "1. Confirmar" << endl << "2.Volver" << endl;

    while (true)
    {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2))
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else if(opcion == 1)
        {
            camion.set_choferAsignado(1);
            chofer.set_asignado(1);
            chofer.set_camionAsignado(camion);
            if(caArchivo.guardarCamionModificado(posicionCamion,camion) && cArchivo.modificarChofer(chofer,posicionChofer))
            {
                system("cls");
                cout << "ASIGNACIÓN CORRECTA ✔ " << endl << _getch() ;
                return;
            }
            else
            {
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }
        else if(opcion == 2)
        {
            return;
        }

    }

    system("pause");



}


///DESASIGNAR CAMION////////////////////////////////////////////

void choferesManager::desasignarCamion()
{

    choferesArchivo cArchivo;
    Choferes chofer;

    if(!buscarChoferesParaDesasignar())
    {
        system("cls");
        cout << "Actualmente, no hay choferes con camión asignado" << endl << endl;
        system("pause");
        return;
    }


    listarConCamion();

    cout << endl << endl << "Por favor, seleccionar ID de chofer para quitar camión asignado: ";

    int opcion;

    while (true)
    {
        cin >> opcion;

        if (cin.fail() || opcion <= 0)
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else
        {

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    int posicionChofer;
    bool idChoferEncontrado = false;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistrosChoferes; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_id() == opcion && chofer.get_estado() == true && chofer.get_asignado() == true)
            {
                posicionChofer = i;
                idChoferEncontrado = true;
                break;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if (!idChoferEncontrado)
    {
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



    while (true)
    {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2))
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }
        else if(opcion == 1)
        {

            int cantidadRegistrosCamiones = caArchivo.get_cantidadRegistros();
            int idCamion = chofer.get_camionAsignado().get_idCamion();
            int posicionCamion;

            for(int i = 0; i < cantidadRegistrosCamiones; i++)
            {

                if(caArchivo.leerCamion(i,camion))
                {
                    if (camion.get_idCamion() == idCamion && camion.get_estado() == true)
                    {
                        posicionCamion = i;
                        break;
                    }
                }
                else
                {
                    cout << "Lectura incorrecta";
                    system("pause");
                    return;
                }

            }
            camion.set_choferAsignado(0);
            chofer.set_asignado(0);
            chofer.set_camionAsignado(Camiones());
            if(caArchivo.guardarCamionModificado(posicionCamion,camion) && cArchivo.modificarChofer(chofer,posicionChofer))
            {
                system("cls");
                cout << "DESASIGNACIÓN CORRECTA ✔ " << endl << _getch() ;
                return;
            }
            else
            {
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }
        else if(opcion == 2)
        {
            return;
        }

    }

    system("pause");


}

///SINCRONIZAR CAMIONES ASIGNADOS////////////////////////////////////////////////

bool choferesManager::sincronizarCamionesAsignados()
{

    choferesArchivo cArchivo;
    camionesArchivo caArchivo;
    Choferes chofer;
    Camiones camion;

    int cantidadChoferes = cArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidadChoferes; i++)
    {

        if (cArchivo.leerChoferes(i, chofer))
        {

            if (chofer.get_estado() && chofer.get_asignado())
            {

                int idCamion = chofer.get_camionAsignado().get_idCamion();

                if (caArchivo.buscarCamionPorId(idCamion, camion))
                {

                    if (camion.get_estado())
                    {
                        chofer.set_camionAsignado(camion);
                    }
                    else
                    {
                        chofer.set_camionAsignado(Camiones());
                        chofer.set_asignado(0);
                    }

                    if (!cArchivo.modificarChofer(chofer, i))
                    {

                        cout << "Error actualizando chofer en posición " << i << endl;
                        return false;

                    }
                }
            }
        }
    }

    return true;
}


///MOSTRAR KM////////////////////////////////////////////////////

void choferesManager::mostrarKmPorChofer()
{

    choferesArchivo chArchivo;
    Choferes chofer;
    cout << left << fixed << setprecision(0);

    viajesManager vManager;
    if(!vManager.actualizarEstados())
    {
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    if(!actualizarLicencia())
    {
        cout << "Error al actualizar datos";
        return;
    }

    system("cls");

    cout << left;
    cout << setw(3) << "ID"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(7) << "ENE"
         << setw(7) << "FEB"
         << setw(7) << "MAR"
         << setw(7) << "ABR"
         << setw(7) << "MAY"
         << setw(7) << "JUN"
         << setw(7) << "JUL"
         << setw(7) << "AGO"
         << setw(7) << "SEP"
         << setw(7) << "OCT"
         << setw(7) << "NOV"
         << setw(7) << "DIC" << endl;

    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


    int cantidadRegistros = chArchivo.getCantidadRegistros();
    const float *km;
    for(int i = 0; i < cantidadRegistros; i++)
    {

        if(chArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_estado() == 1)
            {
                km = chofer.get_kmMensuales();
                cout << setw(3) << chofer.get_id()
                     << setw(30) << chofer.get_nombre()
                     << setw(30) << chofer.get_apellido();
                for (int j = 0; j < 12; j++)
                {
                    cout << setw(7) << km[j];
                }
                cout << endl;
            }

        }
        else
        {
            cout << "Lectura incorrecta";
        }

    }

    cout << endl << endl;
    system("pause");

}

///BUSCAR CHOFER PARA ASIGNAR////////////////////////////////////////////


bool choferesManager::buscarChoferesParaAsignar()
{

    choferesArchivo cArchivo;
    Choferes chofer;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistrosChoferes; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_estado() == true && chofer.get_asignado() == false)
            {
                return 1;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return 0;
        }

    }

    return 0;

}

///BUSCAR CHOFER PARA DESASIGNAR///////////////////////////////////////////

bool choferesManager::buscarChoferesParaDesasignar()
{

    choferesArchivo cArchivo;
    Choferes chofer;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistrosChoferes; i++)
    {

        if(cArchivo.leerChoferes(i,chofer))
        {
            if (chofer.get_estado() == true && chofer.get_asignado() == true)
            {
                return 1;
            }
        }
        else
        {
            cout << "Lectura incorrecta";
            system("pause");
            return 0;
        }

    }

    return 0;

}

void choferesManager::editarChofer(){

    system("cls");

    Choferes chofer;
    choferesArchivo chArchivo;

    int opcionNumerica;

    listarTodos();

    cout << endl << endl << "Por favor, seleccionar el ID del chofer que desea editar: ";

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

    int posicion, cantidadRegistros = chArchivo.getCantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(chArchivo.leerChoferes(i,chofer)){
            if (chofer.get_id() == opcionNumerica && chofer.get_estado() == 1){
                chofer.mostrarResumido();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea editar éste chofer?";
                cout << endl << "1. SI" << endl << "2. NO" << endl << endl << "--> ";
                break;
            }
        }else{
            system("cls");
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

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 2){
            return;
        }else if(opcionNumerica == 1){
            menuChoferes menu;
            menu.menu_edicion(posicion);
            break;
        }

    }

}

void choferesManager::editarDni(int posicion){

    system("cls");

    choferesArchivo chArchivo;
    Choferes chofer;

    chArchivo.leerChoferes(posicion,chofer);
    int dni;
    int opcionNumerica;

    while (true){
        cout << endl << endl << "Ingresar nuevo DNI: ";
        cin >> dni;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (chofer.set_dni(dni))
        {
            system("cls");
            cout << " Guardado correcto ✔" << endl << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos
            system("pause");

            break; // Salir del bucle, entrada válida
        }
        else
        {
            system("cls");
            cout << "DNI invalido." << endl << endl;
            system("pause");
        }
    }

    system("cls");
    chofer.mostrarResumido();
    cout << endl << endl << "¿Confirmar edición? :";
    cout << endl << "1. SI" << endl << "2. NO" << endl << endl << "--> ";


    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 2){
            return;
        }else if(opcionNumerica == 1){
            if(chArchivo.guardarChoferModificado(posicion,chofer)){
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl << endl;
            system("pause");
            return;
            }
            else{
                system("cls");
                cout << "ERROR EN EL GUARDADO ❌ " << endl << endl;
                system("pause");
                return;
            }
        }

    }


}

void choferesManager::editarNombre(int posicion){

    system("cls");

    choferesArchivo chArchivo;
    Choferes chofer;

    chArchivo.leerChoferes(posicion,chofer);
    string nombre,apellido;
    int opcionNumerica;

    while (true) {
        cout << endl << endl << "Ingresar nueva nombre: ";

        getline(cin >> ws, nombre);

        if (chofer.set_nombre(nombre)) {
            system("cls");
            cout << " Guardado correcto ✔" << endl << endl;
            system("pause");
            break;
        } else {
            system("cls");
            cout << endl << "Nombre inválido, o demasiado largo. Intente de vuelta" << endl << endl;
            system("pause");
        }

    }

    while (true) {
        cout << endl << endl << "Ingresar nuevo apellido: ";

        getline(cin >> ws, apellido);

        if (chofer.set_apellido(apellido)) {
            system("cls");
            cout << " Guardado correcto ✔" << endl << endl;
            system("pause");
            break;
        } else {
            system("cls");
            cout << endl << "Apellido inválido, o demasiado largo. Intente de vuelta" << endl << endl;
            system("pause");
        }

    }

    system("cls");
    chofer.mostrarResumido();
    cout << endl << endl << "¿Confirmar edición? :";
    cout << endl << "1. SI" << endl << "2. NO" << endl << endl << "--> ";

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 2){
            return;
        }else if(opcionNumerica == 1){
            if(chArchivo.guardarChoferModificado(posicion,chofer)){
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl << endl;
            system("pause");
            return;
            }
            else{
                system("cls");
                cout << "ERROR EN EL GUARDADO ❌ " << endl << endl;
                system("pause");
                return;
            }
        }

    }

}

void choferesManager::editarExperiencia(int posicion){

    system("cls");

    choferesArchivo chArchivo;
    Choferes chofer;

    chArchivo.leerChoferes(posicion,chofer);
    int experiencia;
    int opcionNumerica;

    while (true){
        cout << endl << endl << "Ingresar nueva experiencia: ";
        cin >> experiencia;
        if (cin.fail())
        {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
            continue;
        }
        if (chofer.set_experiencia(experiencia))
        {
            system("cls");
            cout << " Guardado correcto ✔" << endl << endl;
            cin.ignore(1000, '\n'); // Por si quedan residuos
            system("pause");

            break; // Salir del bucle, entrada válida
        }
        else
        {
            system("cls");
            cout << "Ingreso invalido, intente de nuevo." << endl << endl;
            system("pause");
        }
    }

    system("cls");
    chofer.mostrarResumido();
    cout << endl << endl << "¿Confirmar edición? :";
    cout << endl << "1. SI" << endl << "2. NO" << endl << endl << "--> ";


    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 2){
            return;
        }else if(opcionNumerica == 1){
            if(chArchivo.guardarChoferModificado(posicion,chofer)){
            system("cls");
            cout << "GUARDADO CORRECTO ✔ " << endl << endl;
            system("pause");
            return;
            }
            else{
                system("cls");
                cout << "ERROR EN EL GUARDADO ❌ " << endl << endl;
                system("pause");
                return;
            }
        }

    }

}
