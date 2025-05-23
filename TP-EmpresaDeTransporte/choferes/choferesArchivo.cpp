#include "choferesArchivo.h"
#include <iostream>
using namespace std;

choferesArchivo::choferesArchivo()
{
    _nombreArchivo="choferes.dat";
}

choferesArchivo::choferesArchivo(std::string nombreArchivo)
{
    _nombreArchivo= nombreArchivo;
}

bool choferesArchivo::guardarChofer(Choferes registro)
{
    FILE*pFile;
    bool result;

    pFile=fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr)
    {
        return false;
    }

    result = fwrite(&registro, sizeof(Choferes), 1, pFile);

    fclose(pFile);
    return result;

}

int choferesArchivo::getCantidadRegistros()
{
    int tamRegistro, total, cantidad;

    FILE* pFile;

    pFile=fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tamRegistro = sizeof(Choferes);

    total = ftell(pFile);

    cantidad = total / sizeof(Choferes);

    fclose(pFile);

    return cantidad;
}

bool choferesArchivo::leerChoferes(int pos, Choferes &choferes)
{
    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("choferes.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Choferes)*pos,SEEK_SET);

    lecturaCorrecta = fread(&choferes,sizeof(Choferes),1,pFile);

    fclose(pFile);

    return lecturaCorrecta;
}

int choferesArchivo::buscarRegistro(int id) {
    FILE *pFile;
    int tamRegistro = sizeof(Choferes);
    Choferes registro;
    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        cout << "No se pudo abrir el archivo" << endl;
        return -2;
    }

    while (fread(&registro, tamRegistro, 1, pFile) == 1) {
        if (registro.get_id() == id) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}

bool choferesArchivo::modificarChofer(Choferes reg, int pos) {
    FILE* pFile;
    pFile = fopen("choferes.dat", "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, pos * sizeof(Choferes), 0);
    bool escribio = fwrite(&reg, sizeof(Choferes), 1, pFile);
    fclose(pFile);
    return escribio;
}

