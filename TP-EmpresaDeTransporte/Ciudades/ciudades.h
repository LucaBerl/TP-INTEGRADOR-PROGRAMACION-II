#pragma once


class Ciudades{

private:

    char codigo[50];
    char provincia[50];
    char ciudad[50];
    double lat;
    double lng;

public:

    Ciudades();
    std::string getCodigo();
    std::string getProvincia();
    std::string getCiudad();
    double getLat();
    double getLng();


    std::string convertirMayusculas(std::string palabra);
    void mostrarCoincidencias(std::string nombre);
    void mostrar_ciudad();
    double calcularDistancia(const Ciudades& otraCiudad);
    Ciudades buscarCiudad();



};
