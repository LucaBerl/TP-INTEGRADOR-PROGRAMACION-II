
#include "viajesManager.h"
#include "viajesArchivo.h"
#include "../Carga/carga.h"
#include "../Ciudades/ciudades.h"
#include "../choferes/choferes.h"
#include "../choferes/choferesArchivo.h"
#include "../choferes/choferesManager.h"
#include "../camiones/camionesManager.h"
#include "../camiones/camionesArchivo.h"
#include "../Clientes/ClientesManager.h"
#include "../Clientes/Clientes.h"
#include "../Clientes/ClientesArchivo.h"
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void viajesManager::crearViaje(){


    cout << endl << "SECCION DE CREACION DE VIAJES" << endl;
    Viajes viaje;

    if(!actualizarEstados()){
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }


    seleccionarCarga(viaje);
    if(!seleccionarChofer(viaje)){return;}
    seleccionarCiudades(viaje);
    calcularTiempo(viaje);
    seleccionarCliente(viaje);
    mostrarResumen_GuardarViaje(viaje);

}

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

                cout << endl << "Opcion guardada '" << viaje.get_tipoCarga() << "'" << endl << endl;
            }
            else{cout << endl << "No se pudo guardar la carga" << endl;}
        }else{cout << endl << "Opcion invalida, presione cualquier tecla para volver a intentar ..." << _getch() <<  endl;}

    }while (opcionCarga<1 || opcionCarga>21);


    cout << endl << endl << "Indicar peso de la carga a transportar (máximo 70 mil kg.) : ";
    float pesoCarga;

    while (true) {
        cin >> pesoCarga;

        if (cin.fail() || pesoCarga <= 0 || pesoCarga > 70000 ) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{
            if(viaje.set_pesoTransportado(pesoCarga)){
                cin.ignore(1000, '\n'); // Por si quedan residuos
                cout << " Guardado correcto ✔" << endl;
                break; // Salir del bucle, entrada válida
            }
        }
    }

    cout << endl << endl << "Indicar volumen de la carga a transportar (máximo 150 mts\u00B3) : ";
    float volumenCarga;

    while (true) {
        cin >> volumenCarga;

        if (cin.fail() || volumenCarga <= 0 || volumenCarga > 150) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{
            if(viaje.set_volumenTransportado(volumenCarga)){
                cin.ignore(1000, '\n'); // Por si quedan residuos
                cout << " Guardado correcto ✔" << endl;
                break; // Salir del bucle, entrada válida
            }
        }
    }

}

bool viajesManager::seleccionarChofer(Viajes &viaje){

    system("cls");

    cout << endl << "A continuación, se mostrará una lista con los choferes disponibles para realizar el viaje";
    cout << endl << endl << "Recordar: ";
    cout << endl << endl << "- Para que un chofer aparezca como opción, debe tener un camion asignado previamente";
    cout << endl << "- Los choferes se mostrarán, si es que sus camiones pueden transportar la carga de acuerdo al peso y volumen.";
    cout << endl << "- El chofer estará disponible, solo si tiene vigente la licencia, y su camión tiene vigente la verificicación técnica.";
    cout << endl << endl;

    system("pause");

    if(!listarChoferesDisponibles(viaje)){
        return false;
    }

    cout << endl << endl << "Indicar ID de chofer para realizar el viaje : ";
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

    Choferes chofer;
    choferesArchivo cArchivo;
    bool idChoferEncontrado = false;
    int cantidadRegistrosChoferes = cArchivo.getCantidadRegistros();

    for(int i = 0;i < cantidadRegistrosChoferes; i++){
        if (cArchivo.leerChoferes(i, chofer)){
            if (chofer.get_id() == opcion){

                idChoferEncontrado = true;
                bool cumpleCondiciones =
                chofer.get_estado() &&   /// El chofer está dado de alta?
                chofer.get_asignado() &&    /// El chofer tiiene camion asignado?
                chofer.get_aptoCircular() &&    /// El chofer tiene la licencia vigente?
                !chofer.get_enViaje() &&    /// El chofer ya se encuentra en viaje ?
                chofer.get_camionAsignado().get_aptoCircular() &&   /// El camion asignado al chofer, tiene la verificacion vigente ?
                viaje.get_pesoTransportado() < chofer.get_camionAsignado().get_pesoCarga() &&   /// El camion asignado al chofer, soporta el peso de la carga?
                viaje.get_volumenTransportado() < chofer.get_camionAsignado().get_volumenCarga();   /// El camion asignado al chofer, soporta el volumen de la carga?

                if (cumpleCondiciones) {

                    viaje.set_chofer(chofer);
                    system("cls");
                    cout << "Chofer '" << viaje.get_chofer().get_nombre() << " " << viaje.get_chofer().get_apellido()
                    << "' asignado correctamente al viaje" << endl << endl;
                    system("pause");
                    return true;


                }else{
                    system("cls");
                    cout << "El chofer seleccionado no se encuentra actualmente disponible para este viaje" << endl << endl;
                    system("pause");
                    return false;
                }
            }
        } else {
            system("cls");
            cout << "Lectura incorrecta" << endl << endl;
            system("pause");
            return false;

        }
    }

    if (!idChoferEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un chofer al que se le pueda asignar un viaje" << endl << endl;
        system("pause");
        return false;
    }

}

void viajesManager::seleccionarCiudades(Viajes &viaje){

    system("cls");
    Ciudades ciudadd, ciudad1, ciudad2;

    //cin.ignore();
    cout << endl << endl << "Establecer origen y destino: " << endl << endl;

    cout << endl << "Búsqueda de la ciudad de origen" << endl << endl;
    ciudad1 = ciudadd.buscarCiudad();

    system("cls");

    cout << endl << "Búsqueda de la ciudad de destino:" << endl << endl;
    ciudad2 = ciudadd.buscarCiudad();


    // Calcular la distancia entre las dos ciudades
    double distancia = 1.2*ciudad1.calcularDistancia(ciudad2);
    cout << endl << endl << "Distancia entre " << ciudad1.getCiudad() << " y " << ciudad2.getCiudad() << ": " << distancia << " km" << endl << endl;

    viaje.set_ciudadOrigen(ciudad1);
    viaje.set_ciudadDestino(ciudad2);
    viaje.set_distancia(distancia);

    system("pause");

}

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
    //

    float segundos;
    const float velocidad_promedio = 90;
    float distancia = viaje.get_distancia();
    float tiempoEstimado = distancia / velocidad_promedio;
    int tiempoEstimadoHoras;

    tiempoEstimadoHoras = tiempoEstimado;

    int tiempoEstimadoMinutos = (tiempoEstimado-tiempoEstimadoHoras)*60;

    cout << "Tiempo Estimado: " << tiempoEstimadoHoras << "hs " << tiempoEstimadoMinutos << "min " << "(para una velocidad promedio de " << velocidad_promedio << " km/h)" << endl;


    /// A partir de aca lo que se hace es convertir el tiempo estimado a segundos, para agregarlo a la estructura "struct tm tm_info" en el campo "tm_sec".


    segundos = tiempoEstimado*3600;
    time_t t = time(NULL);                  /// time_t es el tipo de dato --> time(null) asigna los segundos transcurridos desde 1 de enero de 1970 hasta ahora.
    struct tm tm_info = *localtime(&t);     /// localtime me convierte esos segundos a una fecha legible, y al asignarlo a la struct tm me queda cada valor separado(int hora, int minutos, int segundos, etc)
    viaje.set_fechaSalida(tm_info);

    tm_info.tm_sec += segundos;             /// Le agrego a la estructura con la fecha y hora ACTUAL, los segundos del tiempo estimado.
    mktime(&tm_info);                       /// mktime() normaliza la estructura, es decir, convierte el exceso de segundos en horas y minutos.

    viaje.set_fechaLlegada(tm_info);

    cout << endl << "Fecha de llegada: "; /// Despues podemos mostrar cada campo de la estructura por separado para visualizar la fecha de llegada.

    cout << tm_info.tm_mday << "/" << (tm_info.tm_mon)+1 << "/" << (tm_info.tm_year)+1900;
    cout << " a las  ";
    if(tm_info.tm_hour < 10){cout << "0" <<tm_info.tm_hour<<":";}else{cout << tm_info.tm_hour<<":";}
    if(tm_info.tm_min < 10){cout << "0" <<tm_info.tm_min<<" hs";}else{cout << tm_info.tm_min<<" hs";}

    cout << endl << endl;

    ///Tambien podria hacerse directamente con la funcion asctime(&tm_info), pero devuelve todo en inglés.

    system("pause");


}

bool viajesManager::seleccionarCliente(Viajes &viaje){

    clientesManager clienteManager;
    clientesArchivo clienteArchivo;
    Clientes cliente;

    system("cls");

    cout << endl << "A continuación, se mostrará una lista de Clientes en nuestro sistema, si el cliente no existe, puede crear un nuevo Cliente en Menu de Clientes ";

    cout << endl << endl;

    system("pause");

    clienteManager.mostrarTodos();

    cout << endl << endl << "Indicar ID de Cliente  del Viaje : ";
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

    bool idChoferEncontrado = false;
    int cantidadRegistrosClientes = clienteArchivo.getCantidadClientes();

    for(int i = 0;i < cantidadRegistrosClientes; i++){
        if(clienteArchivo.leerClientes(i, cliente)){
            if(cliente.get_idCliente() == opcion){

                idChoferEncontrado = true;




                    viaje.set_cliente(cliente);
                    system("cls");
                    cout << "Cliente '" << viaje.get_cliente().get_Nombre_RazonSocial() << " " << viaje.get_cliente().get_Direccion()
                    << "' asignado correctamente al viaje" << endl << endl;
                    system("pause");
                    return true;



            }
        } else {
            system("cls");
            cout << "Lectura incorrecta" << endl << endl;
            system("pause");
            return false;

        }
    }

    if (!idChoferEncontrado){
        system("cls");
        cout << "El ID no existe o no pertenece a un Cliente " << endl << endl;
        system("pause");
        return false;
    }



}

void viajesManager::mostrarResumen_GuardarViaje(Viajes &viaje){


viajesArchivo vArchivo;

viaje.set_id(vArchivo.get_ultimoID());

system("cls");

cout << left << fixed << setprecision(0);

cout << endl << "🆔 Viaje: " << viaje.get_id();
cout << endl << "🧑‍✈️ Chofer: " << viaje.get_chofer().get_nombre() << "  " << viaje.get_chofer().get_apellido() << " (ID = " << viaje.get_chofer().get_id() << ")";
cout << endl << "📍 Origen: " << viaje.get_ciudadOrigen().getCiudad() << " -- " << viaje.get_ciudadOrigen().getProvincia();
cout << endl << "🏁 Destino: " << viaje.get_ciudadDestino().getCiudad() << " -- " << viaje.get_ciudadDestino().getProvincia();
cout << endl << "🛣️ Distancia: " << setprecision(1) << viaje.get_distancia() << " km";
cout << endl << "⏱️ Salida: " << viaje.get_fechaSalida().tm_mday << "/" << viaje.get_fechaSalida().tm_mon+1 << "/" << viaje.get_fechaSalida().tm_year+1900 << "   " << viaje.get_fechaSalida().tm_hour << ":" << viaje.get_fechaSalida().tm_min;
cout << endl << "⏱️ Llegada: " << viaje.get_fechaLlegada().tm_mday << "/" << viaje.get_fechaLlegada().tm_mon+1 << "/" << viaje.get_fechaLlegada().tm_year+1900 << "   " << viaje.get_fechaLlegada().tm_hour << ":" << viaje.get_fechaLlegada().tm_min;
cout << endl << "📦 Carga transportada: " << viaje.get_tipoCarga();
cout << endl << "⚖️ Peso transportado: " << viaje.get_pesoTransportado() << " KG";
cout << endl << "🧊 Volumen transportado: " << viaje.get_volumenTransportado() << " mts\u00B3";
cout << endl << "🧑‍✈️ Cliente: " << viaje.get_cliente().get_Nombre_RazonSocial();
cout << endl << endl;

cout << endl << endl << "Confirmar viaje?" << endl;
cout << endl << "1. SI" << endl << "2. NO" << endl << endl << "-->";
int opcionNumerica;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){

            ///Guardar viaje, guardar estados de camiones y choferes

            choferesArchivo cArchivo;
            int posicionChofer = cArchivo.buscarRegistro(viaje.get_chofer().get_id());
            camionesArchivo caArchivo;
            int posicionCamion = caArchivo.buscarRegistro(viaje.get_chofer().get_camionAsignado().get_idCamion());

            Choferes choferViaje = viaje.get_chofer();
            Camiones camionViaje = viaje.get_chofer().get_camionAsignado();

            choferViaje.set_enViaje(1);
            choferViaje.set_kmMensuales(viaje.get_distancia(),viaje.get_fechaLlegada().tm_mon+1);
            camionViaje.set_enViaje(1);
            camionViaje.set_kmMensuales(viaje.get_distancia(),viaje.get_fechaLlegada().tm_mon+1);

            if (vArchivo.guardarViaje(viaje) && cArchivo.guardarChoferModificado(posicionChofer,choferViaje) && caArchivo.guardarCamionModificado(posicionCamion,camionViaje)){

                cout << "🚚";
                Sleep(1000);
                for(int i = 0; i < 3; i++) {
                    cout << "💨";
                    Sleep(1000);
                }

                cout << " VIAJE CREADO CORRECTAMENTE  ✔️" << endl << endl;

                system("pause");
                return;
            }
            else{
                system("cls");
                cout << "Error en el guardado" << _getch() ;
                return;
            }
        }else if(opcionNumerica == 2){
            cout << " VIAJE CANCELADO " << endl << endl;
            system("pause");
            return;
        }

    }




}

bool viajesManager::actualizarEstados(){

    viajesArchivo vArchivo;
    Viajes viaje;

    int cantidadRegistros = vArchivo.get_cantidadRegistros();

    for(int i = 0;i < cantidadRegistros; i++){

        if(vArchivo.leerViaje(i,viaje)){

            if (viaje.get_estado() == 1 && viaje.segundosRestantes() == 0 ){

                viaje.set_estado(0);

                choferesArchivo cArchivo;
                int posicionChofer = cArchivo.buscarRegistro(viaje.get_chofer().get_id());
                camionesArchivo caArchivo;
                int posicionCamion = caArchivo.buscarRegistro(viaje.get_chofer().get_camionAsignado().get_idCamion());

                Choferes choferViaje;
                Camiones camionViaje;

                cArchivo.leerChoferes(posicionChofer, choferViaje);
                caArchivo.leerCamion(posicionCamion, camionViaje);

                choferViaje.set_enViaje(0);
                camionViaje.set_enViaje(0);

                // Actualiza cantidad de viajes en cliente
                Clientes cliente = viaje.get_cliente();

                 clientesArchivo clienteArchivo;
                int posCliente = clienteArchivo.buscarRegistro(cliente.get_idCliente());

                   if (posCliente >= 0) {
                       if (clienteArchivo.leerClientes(posCliente, cliente)) {
                           int cantidad = cliente.get_Cantidad_Viajes_Realizados();
                            cliente.set_CantidadViajesRealizados(cantidad + 1);

                             clienteArchivo.guardarClienteModificado(posCliente, cliente);


                              viaje.set_cliente(cliente);
                          }
                  }

                if(!vArchivo.guardarViajeModificado(i,viaje) || !cArchivo.guardarChoferModificado(posicionChofer,choferViaje) || !caArchivo.guardarCamionModificado(posicionCamion,camionViaje)){

                    return false;

                }


            }

        }else{return false;}

    }


    return true;

}

void viajesManager::listarActivos(){

    system("cls");
    viajesArchivo vArchivo;
    Viajes viaje;

    if(!actualizarEstados()){
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    int cantidadRegistros = vArchivo.get_cantidadRegistros();

    cout << left << fixed << setprecision(0);

    // Encabezado
   cout << left;
    cout << setw(3)  << "ID"
     << setw(40) << "Chofer"
     << setw(33) << "Origen"
     << setw(33) << "Destino"
     << setw(30) << "Carga"
     << setw(15) << "Llegada en"
     << setw(30) << "Cliente";

cout << endl << string(185, '-') << endl;


    for(int i = 0;i < cantidadRegistros; i++){

        if(vArchivo.leerViaje(i,viaje)){

            if(viaje.get_estado() == true){

                viaje.mostrarViajeActivo();

            }

        }else{cout << "No se pudo leer el viaje";}

    }

    cout << endl << endl;
    system("pause");
}

void viajesManager::listarHistorial(){

    system("cls");
    viajesArchivo vArchivo;
    Viajes viaje;


    clientesArchivo clienteArchivo;

    if(!actualizarEstados()){
        system("cls");
        cout << endl << endl << "Error en sincronización de datos" << endl << endl;
        system("pause");
        return;
    }

    int cantidadRegistros = vArchivo.get_cantidadRegistros();


    cout << left << fixed << setprecision(2);
    cout << setw(3)  << "ID"
     << setw(40) << "Chofer"
     << setw(33) << "Origen"
     << setw(33) << "Destino"
     << setw(30) << "Carga"
     << setw(15) << "Distancia"
     << setw(11) << "Salida"
     << setw(11) << "Llegada" ;

     // Línea separadora
    cout << endl << string(176, '-') << endl;

    for(int i = 0;i < cantidadRegistros; i++){

        if(vArchivo.leerViaje(i,viaje)){

             if(viaje.get_estado() == false){

                Clientes cliente = viaje.get_cliente();  // copia
                int cantidad = cliente.get_Cantidad_Viajes_Realizados();
                cliente.set_CantidadViajesRealizados(cantidad + 1);

                clienteArchivo.guardarClienteModificado(viaje.get_cliente().get_idCliente(),cliente);

                viaje.mostrarViaje();
                cout << endl;

            }

        }else{cout << "No se pudo leer el viaje";}

    }

    cout << endl << endl;

    cout << "Ingresar un ID de viaje para obtener informacion mas detallada del mismo, o '0' para salir..." << endl << endl;

    int opcion;

    while (true) {
        cin >> opcion;

        if (cin.fail() || opcion < 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{
            if (opcion == 0){return;}
            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcion << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }



    bool  viajeEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(vArchivo.leerViaje(i,viaje)){

            if(viaje.get_estado() == false && viaje.get_id() == opcion){

                cout << endl << "Viaje N°: " << opcion << endl << endl << endl;
                viajeEncontrado = true;
                cout << endl << "Ciudad Origen: " << viaje.get_ciudadOrigen().getCiudad() << endl
                << "Ciudad Destino: " << viaje.get_ciudadDestino().getCiudad() << endl
                << "Distancia: " << viaje.get_distancia() << endl
                << "Tipo de carga: " << viaje.get_tipoCarga() << endl
                << "Peso: " << viaje.get_pesoTransportado() << endl
                << "Volumen: " << viaje.get_volumenTransportado() << endl
                << "Chofer: " << viaje.get_chofer().get_nombre() << " " << viaje.get_chofer().get_apellido() << endl
                << "Experiencia: " << viaje.get_chofer().get_experiencia() << endl
                << "Dni: " << viaje.get_chofer().get_dni() << endl
                << "Camión: " << viaje.get_chofer().get_camionAsignado().get_marca() << " " << viaje.get_chofer().get_camionAsignado().get_modelo() << endl
                << "Patente: " << viaje.get_chofer().get_camionAsignado().get_patente() << endl
                << "Cliente: " << viaje.get_cliente().get_Nombre_RazonSocial() << endl << endl;
                break;

            }

        }else{cout << "No se pudo leer el viaje";}

    }

    if (!viajeEncontrado){
        system("cls");
        cout << "El ID de viaje seleccionado no existe ... " << endl << endl;
        system("pause");
        return;
    }

    system("pause");
}

bool viajesManager::listarChoferesDisponibles(Viajes &viaje){

    choferesManager cManager;
    choferesArchivo cArchivo;
    Choferes chofer;
    camionesManager caManager;

    cout << left << fixed << setprecision(0);

    ///Actualizar en viaje o no

    if(!cManager.actualizarLicencia()){
        cout << "Error al actualizar datos";
        system("pause");
        return false;
    }

    if(!caManager.actualizarVerificacion()){
        cout << "Error al actualizar datos";
        system("pause");
        return false;
    }

    if(!cManager.sincronizarCamionesAsignados()){
        cout << "Error al actualizar datos";
        system("pause");
        return false;
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
    int contador = 0;

    for(int i = 0; i < cantidadRegistros; i++) {
        if (cArchivo.leerChoferes(i, chofer)) {
            bool cumpleCondiciones =
                chofer.get_estado() &&   /// El chofer está dado de alta?
                chofer.get_asignado() &&    /// El chofer tiiene camion asignado?
                chofer.get_aptoCircular() &&    /// El chofer tiene la licencia vigente?
                !chofer.get_enViaje() &&    /// El chofer ya se encuentra en viaje ?
                chofer.get_camionAsignado().get_aptoCircular() &&   /// El camion asignado al chofer, tiene la verificacion vigente ?
                viaje.get_pesoTransportado() < chofer.get_camionAsignado().get_pesoCarga() &&   /// El camion asignado al chofer, soporta el peso de la carga?
                viaje.get_volumenTransportado() < chofer.get_camionAsignado().get_volumenCarga();   /// El camion asignado al chofer, soporta el volumen de la carga?

            if (cumpleCondiciones) {
                chofer.mostrar();
                contador++;
                cout << endl;
            }
        } else {
            cout << "Lectura incorrecta";
        }
    }

    if (contador == 0){
        system("cls");
        cout << endl << endl << "No hay choferes disponibles en este momento" << endl << endl;
        system("pause");
        return false;
    }

    cout << endl << endl;
    system("pause");

    return true;


}

