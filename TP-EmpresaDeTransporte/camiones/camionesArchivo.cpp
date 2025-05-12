#include "camionesArchivo.h"
#include "camiones.h"


int camionesArchivo::get_cantidadRegistros(){

    int  total, cantidad;
    FILE* pFile;

    pFile = fopen("camiones.dat", "rb");

    if(pFile == nullptr){return 0;}

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    if(total == 0){return 0;}

    cantidad = total / sizeof(Camiones);

    fclose(pFile);

    return cantidad;


}

int camionesArchivo::get_ultimoID(){

    FILE* pFile;

    Camiones camion;

    pFile = fopen("camiones.dat", "rb");

    if(pFile == nullptr){return 0;}

    if (get_cantidadRegistros() == 0){
        fclose(pFile);
        return 0;
    }

    fseek(pFile,-sizeof(Camiones),SEEK_END);

    fread(&camion,sizeof(Camiones),1,pFile);

    int ultimo = camion.get_idCamion();

    fclose(pFile);

    return ultimo;

}

bool camionesArchivo::leerCamion(int pos, Camiones &camion){

    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("camiones.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Camiones)*pos,SEEK_SET);

    lecturaCorrecta = fread(&camion,sizeof(Camiones),1,pFile);

    fclose(pFile);

    return lecturaCorrecta;


}

bool camionesArchivo::guardarCamion(const Camiones &camion){


    FILE *pfile;
    bool guardo;

    pfile = fopen("camiones.dat","ab");

    if (pfile == nullptr){return false;}

    guardo = fwrite(&camion,sizeof(Camiones),1,pfile);

    fclose(pfile);

    return guardo;

}
