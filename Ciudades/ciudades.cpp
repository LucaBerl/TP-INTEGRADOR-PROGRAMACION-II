#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath> // Para funciones matemáticas
#include "ciudades.h"
using namespace std;

const double PI = 3.14159265358979323846;

const double R = 6371.0; // Radio de la Tierra en km


Ciudades::Ciudades(){

    codigo[50] = {};
    provincia[50] = {};
    ciudad[50] = {};
    double lat = 0;
    double lng = 0;

}

string Ciudades::getCodigo()const{

    return codigo;

}
string Ciudades::getProvincia()const{

    return provincia;

}
string Ciudades::getCiudad()const{

    return ciudad;

}
double Ciudades::getLat()const{

    return lat;

}
double Ciudades::getLng()const{

    return lng;


}


string Ciudades::convertirMayusculas(string palabra){

    for (int i = 0; i < palabra.length(); i++){

        palabra[i] = toupper(static_cast<unsigned char>(palabra[i]));

    }

    return palabra;
}

void Ciudades::mostrarCoincidencias(string ciudadIngresada){


    FILE *pfile;
    Ciudades ciudadd;

    int cont;
    bool coincidenciaEncontrada = false;

    ciudadIngresada = convertirMayusculas(ciudadIngresada);

    pfile = fopen("Ciudades/datos2.bin", "rb");

    if (pfile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        exit(-1);  // Salir con error si no se pudo abrir el archivo
    }

    cout << endl << "ERROR EN LA BUSQUEDA, ESTAS SON ALGUNAS SUGERENCIAS: " << endl;

    while (fread(&ciudadd, sizeof(Ciudades), 1, pfile) == 1) {

        ///convertirMayusculas(ciudadd.ciudad);
        string ciudadArchivo = convertirMayusculas(string(ciudadd.ciudad));
        ///Vemos cual tiene menos caracteres para establecer el limite del for, si no capaz comparamos con basura.
        int minLen = min(ciudadArchivo.length(), ciudadIngresada.length());

        cont = 0;

        for (int i = 0;i<minLen;i++){


            if (ciudadArchivo[i] == ciudadIngresada[i] && ciudadArchivo[i] != ' '){

                cont++;
            }

        }


        if (ciudadIngresada.length() < 6 ) {

            if (cont >= (ciudadIngresada.length() - 2 ) ){
            coincidenciaEncontrada = true;
            cout  << ciudadd.ciudad << " -- " << ciudadd.provincia <<  endl;
            }

        }

        else if (ciudadIngresada.length() < 9 && ciudadIngresada.length() > 5) {

            if (cont >= (ciudadIngresada.length() - 3 ) ){
            coincidenciaEncontrada = true;
            cout  << ciudadd.ciudad << " -- " << ciudadd.provincia <<  endl;
            }

        }
        else if (ciudadIngresada.length() >= 9 ){

            if (cont >= (ciudadIngresada.length() - 4 ) ){
            coincidenciaEncontrada = true;
            cout  << ciudadd.ciudad << " -- " << ciudadd.provincia <<  endl;
            }

        }
    }

    if (coincidenciaEncontrada == true){
    cout << endl << endl << "Por favor, intentá de nuevo" << endl;
    }else{cout << endl << "No se encontraron sugerencias" << endl << endl;}
    fclose(pfile);

}


void Ciudades::mostrar_ciudad() {
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Provincia: " << getProvincia() << endl;
    cout << "Ciudad: " << getCiudad() << endl;
    cout << fixed << setprecision(6);
    cout << "Latitud: " <<  getLat() << endl;
    cout << "Longitud: " << getLng() << endl;
}


double Ciudades::calcularDistancia(const Ciudades& otraCiudad) {
    // Convertir grados a radianes
    double lat1 = lat * PI / 180.0;
    double lon1 = lng * PI / 180.0;
    double lat2 = otraCiudad.lat * PI / 180.0;
    double lon2 = otraCiudad.lng * PI / 180.0;


    // Diferencias de latitudes y longitudes
    double dlat = lat2 - lat1;
    double dlng = lon2 - lon1;


    // Fórmula de Haversine
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlng / 2) * sin(dlng / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Distancia en km
    return R * c;
}


Ciudades Ciudades::buscarCiudad(){

    Ciudades ciudadd;
    Ciudades ciudad;
    bool ciudadEncontrada = false;
    string nombreCiudad2;
    FILE *pfile;
    int opcion;

    pfile = fopen("Ciudades/datos2.bin", "rb");
    if (pfile == nullptr) {
    cout << "Error al abrir el archivo." << endl;
    return ciudadd;
    }

    do{
        cout << "Ingrese el nombre : ";
        getline(cin, nombreCiudad2);


        while (fread(&ciudadd, sizeof(Ciudades), 1, pfile) == 1) {
            if (convertirMayusculas(string(ciudadd.ciudad)) == convertirMayusculas(nombreCiudad2) && !ciudadEncontrada) {
                ciudad = ciudadd;
                ciudad.mostrar_ciudad();
                cout << endl << "Esta es la ciudad buscada? (SI = 1 / NO = 0)" << endl;
                while (true) {
                    cin >> opcion;

                    if (cin.fail() || (opcion != 1 && opcion != 0)) {
                        cin.clear(); // Limpia el estado de error
                        cin.ignore(1000, '\n'); // Descarta el resto de la línea
                        cout << endl << "Ingreso incorrecto, intente nuevamente: ";
                    }else if(opcion == 1){
                        cin.ignore(1000, '\n'); // Por si quedan residuos
                        ciudadEncontrada = true;
                        break; // Salir del bucle, entrada válida
                    }else if (opcion == 0){
                        cin.ignore(1000, '\n'); // Por si quedan residuos
                        ciudadEncontrada = false;
                        break;
                    }
                }

            }
        }
        if (ciudadEncontrada == false){

            ciudad.mostrarCoincidencias(nombreCiudad2);
            fseek(pfile, 0, SEEK_SET);
        }

    }while(ciudadEncontrada == false);


    fclose(pfile);
    return ciudad;

}


