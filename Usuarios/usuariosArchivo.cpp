#include "usuarios.h"
#include "usuariosManager.h"
#include "usuariosArchivo.h"

int usuariosArchivo::get_cantidadRegistros(){

    int  total, cantidad;
    FILE* pFile;

    pFile = fopen("usuarios.dat", "rb");

    if(pFile == nullptr){return 0;}

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    if(total == 0){return 0;}

    cantidad = total / sizeof(Usuario);

    fclose(pFile);

    return cantidad;


}

int usuariosArchivo::get_ultimoID(){

    FILE* pFile;

    Usuario usuario;

    pFile = fopen("usuarios.dat", "rb");

    if(pFile == nullptr){return 0;}

    if (get_cantidadRegistros() == 0){
        fclose(pFile);
        return 0;
    }

    fseek(pFile,-sizeof(Usuario),SEEK_END);

    fread(&usuario,sizeof(Usuario),1,pFile);

    int ultimo = usuario.get_idUsuario();

    fclose(pFile);

    return ultimo;

}

bool usuariosArchivo::leerUsuario(int pos, Usuario &usuario){

    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("usuarios.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Usuario)*pos,SEEK_SET);

    lecturaCorrecta = fread(&usuario,sizeof(Usuario),1,pFile);

    fclose(pFile);

    return lecturaCorrecta;


}

bool usuariosArchivo::guardarUsuario(const Usuario &usuario){


    FILE *pfile;
    bool guardo;

    pfile = fopen("usuarios.dat","ab");

    if (pfile == nullptr){return false;}

    guardo = fwrite(&usuario,sizeof(Usuario),1,pfile);

    fclose(pfile);

    return guardo;

}

bool usuariosArchivo::guardarUsuarioModificado(int pos, Usuario &usuario){

    FILE *pfile = fopen("usuarios.dat", "rb+");
    if(pfile == NULL){
        return false;
    }
    fseek(pfile, sizeof(Usuario) * pos, SEEK_SET);
    bool modifico = fwrite(&usuario, sizeof(Usuario), 1, pfile);
    fclose(pfile);
    return modifico;

}

bool usuariosArchivo::buscarUsuarioPorId(int idBuscado,Usuario &usuarioEncontrado){

    Usuario usuario;
    int cantidad = get_cantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        if (leerUsuario(i, usuario)) {
            if (usuario.get_idUsuario() == idBuscado) {
                usuarioEncontrado = usuario;
                return true;
            }
        }
    }

    return false;

}

int usuariosArchivo::buscarRegistro(int id) {
    FILE *pFile;
    int tamRegistro = sizeof(Usuario);
    Usuario usuario;
    int posicion = 0;

    pFile = fopen("usuarios.dat", "rb");
    if (pFile == nullptr) {
        return -2;
    }

    while (fread(&usuario, tamRegistro, 1, pFile) == 1) {
        if (usuario.get_idUsuario() == id) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}
