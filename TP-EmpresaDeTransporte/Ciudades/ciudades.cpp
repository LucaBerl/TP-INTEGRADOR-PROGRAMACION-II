#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath> // Para funciones matemáticas como sin, cos, sqrt, atan2
#include "ciudades.h"

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


const double R = 6371.0; // Radio de la Tierra en km


Ciudades::Ciudades(){

    codigo[50] = {};
    provincia[50] = {};
    ciudad[50] = {};
    double lat = 0;
    double lng = 0;

}

string Ciudades::getCodigo(){

    return codigo;

}
string Ciudades::getProvincia(){

    return provincia;

}
string Ciudades::getCiudad(){

    return ciudad;

}
double Ciudades::getLat(){

    return lat;

}
double Ciudades::getLng(){

    return lng;


}


string Ciudades::convertirMayusculas(string palabra){

    for (int i = 0; i < palabra.length(); i++){

        palabra[i] = toupper(static_cast<unsigned char>(palabra[i]));

    }

    return palabra;
}

void Ciudades::mostrarCoincidencias(string nombre){


        FILE *pfile;
        Ciudades ciudadd;
        char ciudadArchivo[50] = {};
        int cont;
        bool coincidenciaEncontrada = false;

        strcpy(ciudadArchivo,nombre.c_str());

        pfile = fopen("datos2.bin", "rb");

        if (pfile == nullptr) {
            cout << "Error al abrir el archivo." << endl;
            exit(-1);  // Salir con error si no se pudo abrir el archivo
        }

        cout << endl << "ERROR EN LA BUSQUEDA, ESTAS SON ALGUNAS SUGERENCIAS: " << endl;
        ///convertirMayusculas(ciudadArchivo);
        while (fread(&ciudadd, sizeof(Ciudades), 1, pfile) == 1) {

            ///convertirMayusculas(ciudadd.ciudad);

            cont = 0;

            for (int i = 0;i<strlen(ciudadArchivo);i++){


                if (ciudadd.ciudad[i] == ciudadArchivo[i] && ciudadd.ciudad[i] != ' '){

                    cont++;
                }

            }


             if (strlen(ciudadArchivo) < 6 ) {

                if (cont >= (strlen(ciudadArchivo) - 2 ) ){
                coincidenciaEncontrada = true;
                cout  << ciudadd.ciudad << " -- " << ciudadd.provincia <<  endl;
                }

            }

            else if (strlen(ciudadArchivo) < 9 && strlen(ciudadArchivo) > 5) {

                if (cont >= (strlen(ciudadArchivo) - 3 ) ){
                coincidenciaEncontrada = true;
                cout  << ciudadd.ciudad << " -- " << ciudadd.provincia <<  endl;
                }

            }
            else if (strlen(ciudadArchivo) >= 9 ){

                if (cont >= (strlen(ciudadArchivo) - 4 ) ){
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
        double lat1 = lat * M_PI / 180.0;
        double lon1 = lng * M_PI / 180.0;
        double lat2 = otraCiudad.lat * M_PI / 180.0;
        double lon2 = otraCiudad.lng * M_PI / 180.0;


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
        int desicion;

        pfile = fopen("datos2.bin", "rb");
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


                    cout << endl << "Esta es la ciudad buscada? 1 para SI y 0 para NO" << endl;
                    cin >> desicion;
                    cin.ignore();
                    cout << endl;
                    if(desicion == 1){ciudadEncontrada = true;
                        break;}
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




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int main() {
//
//    Ciudades ciudadd, ciudad1, ciudad2;
//
//    cout << endl << "Busqueda de la 1er ciudad" << endl << endl;
//    ciudad1 = ciudadd.buscarCiudad();
//    cout << endl << "Busqueda de la 2da ciudad:" << endl << endl;
//    ciudad2 = ciudadd.buscarCiudad();
//
//
//        // Calcular la distancia entre las dos ciudades
//        double distancia = 1.2*ciudad1.calcularDistancia(ciudad2);
//        cout << endl << endl << "Distancia entre " << ciudad1.getCiudad() << " y " << ciudad2.getCiudad() << ": " << distancia << " km" << endl;
//
//
//    return 0;
//}



