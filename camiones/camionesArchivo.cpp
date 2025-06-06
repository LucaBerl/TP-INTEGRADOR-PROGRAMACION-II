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

bool camionesArchivo::guardarCamionModificado(int pos, Camiones &camion){

    FILE *pfile = fopen("camiones.dat", "rb+");
    if(pfile == NULL){
        return false;
    }
    fseek(pfile, sizeof(Camiones) * pos, SEEK_SET);
    bool modifico = fwrite(&camion, sizeof(Camiones), 1, pfile);
    fclose(pfile);
    return modifico;

}

bool camionesArchivo::buscarCamionPorId(int idBuscado,Camiones &camionEncontrado){

    Camiones camion;
    int cantidad = get_cantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        if (leerCamion(i, camion)) {
            if (camion.get_idCamion() == idBuscado) {
                camionEncontrado = camion;
                return true;
            }
        }
    }

    return false;

}

int camionesArchivo::buscarRegistro(int id) {
    FILE *pFile;
    int tamRegistro = sizeof(Camiones);
    Camiones camion;
    int posicion = 0;

    pFile = fopen("camiones.dat", "rb");
    if (pFile == nullptr) {
        return -2;
    }

    while (fread(&camion, tamRegistro, 1, pFile) == 1) {
        if (camion.get_idCamion() == id) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}
