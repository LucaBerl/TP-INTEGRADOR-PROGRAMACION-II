
#include  "Clientes.h"
#include  "ClientesArchivo.h"


int clientesArchivo::getCantidadClientes()
{
    int tamRegistro, total, cantidad;

    FILE* pFile;

    pFile=fopen("clientes.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tamRegistro = sizeof(Clientes);

    total = ftell(pFile);

    cantidad = total / sizeof(Clientes);

    fclose(pFile);

    return cantidad;
}


bool clientesArchivo::guardarCliente(const Clientes &cliente){


    FILE *pfile;
    bool guardo;

    pfile = fopen("clientes.dat","ab");

    if (pfile == nullptr){return false;}

    guardo = fwrite(&cliente,sizeof(Clientes),1,pfile);

    fclose(pfile);

    return guardo;

}

bool clientesArchivo::leerClientes(int pos, Clientes &cliente)
{
    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Clientes)*pos,SEEK_SET);

    lecturaCorrecta = fread(&cliente,sizeof(Clientes),1,pFile);

    fclose(pFile);

    return lecturaCorrecta;

}


int clientesArchivo::get_ultimoID(){

    FILE* pFile;

    Clientes cliente;

    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){return 0;}

    if (getCantidadClientes() == 0){
        fclose(pFile);
        return 0;
    }

    fseek(pFile,-sizeof(Clientes),SEEK_END);

    fread(&cliente,sizeof(Clientes),1,pFile);

    int ultimo = cliente.get_idCliente();

    fclose(pFile);

    return ultimo;

}

bool clientesArchivo::guardarClienteModificado(int pos, Clientes &cliente){

    FILE *pfile = fopen("clientes.dat", "rb+");
    if(pfile == NULL){
        return false;
    }
    fseek(pfile, sizeof(Clientes) * pos, SEEK_SET);
    bool modifico = fwrite(&cliente, sizeof(Clientes), 1, pfile);
    fclose(pfile);
    return modifico;

}


int clientesArchivo::buscarRegistro(int idCliente) {
    FILE* pfile = fopen("clientes.dat", "rb");
    if (pfile == nullptr) return -1;

    Clientes cliente;
    int pos = 0;

    while (fread(&cliente, sizeof(Clientes), 1, pfile)) {
        if (cliente.get_idCliente() == idCliente) {
            fclose(pfile);
            return pos;
        }
        pos++;
    }

    fclose(pfile);
    return -1; // No se encontró
}
