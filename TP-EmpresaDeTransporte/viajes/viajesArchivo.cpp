#include "viajesArchivo.h"
#include "viajes.h"


bool viajesArchivo::guardarViaje(Viajes &viaje){


    FILE *pfile;
    bool guardo;

    pfile = fopen("viajes.dat","ab");

    if (pfile == nullptr){return false;}

    guardo = fwrite(&viaje,sizeof(Viajes),1,pfile);

    fclose(pfile);

    return guardo;

}

int viajesArchivo::get_cantidadRegistros(){

    int tamRegistro, total, cantidad;
    FILE* pFile;

    pFile = fopen("viajes.dat", "rb");

    if(pFile == nullptr){return 0;}

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    if(total == 0){return 0;}

    cantidad = total / sizeof(Viajes);

    fclose(pFile);

    return cantidad;


}

bool viajesArchivo::leerViaje(int pos,Viajes &viaje){

    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("viajes.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Viajes)*pos,SEEK_SET);

    lecturaCorrecta = fread(&viaje,sizeof(Viajes),1,pFile);

    fclose(pFile);

    return lecturaCorrecta;


}

int viajesArchivo::get_ultimoID(){

    FILE* pFile;

    Viajes viaje;

    pFile = fopen("viajes.dat", "rb");

    if(pFile == nullptr){return 0;}

    if (get_cantidadRegistros() == 0){
        fclose(pFile);
        return 0;
    }

    fseek(pFile,-sizeof(Viajes),SEEK_END);

    fread(&viaje,sizeof(Viajes),1,pFile);

    int ultimo = viaje.get_id();

    fclose(pFile);

    return ultimo;

}

bool viajesArchivo::guardarViajeModificado(int pos,const Viajes &viaje){

    FILE *pfile = fopen("viajes.dat", "rb+");
    if(pfile == NULL){
        return false;
    }
    fseek(pfile, sizeof(Viajes) * pos, SEEK_SET);
    bool modifico = fwrite(&viaje, sizeof(Viajes), 1, pfile);
    fclose(pfile);
    return modifico;

}

