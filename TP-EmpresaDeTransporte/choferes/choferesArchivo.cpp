#include "choferesArchivo.h"

choferesArchivo::choferesArchivo()
{
    _nombreArchivo="choferes.dat";
}

choferesArchivo::choferesArchivo(std::string nombreArchivo)
{
    _nombreArchivo= nombreArchivo;
}

bool choferesArchivo::guardar(Choferes registro)
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

Choferes choferesArchivo::leer(int pos)
{
    FILE *pFile;

    Choferes reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, sizeof(Choferes)* pos, SEEK_SET);

    fread(&reg, sizeof(Choferes),1, pFile);

    fclose(pFile);

    return reg;
}
