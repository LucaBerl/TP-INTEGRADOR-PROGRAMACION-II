
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

bool clientesArchivo::leerClientes(int pos, Clientes &clientes)
{
    FILE* pFile;
    bool lecturaCorrecta;


    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){return false;}

    fseek(pFile,sizeof(Clientes)*pos,SEEK_SET);

    lecturaCorrecta = fread(&clientes,sizeof(Clientes),1,pFile);

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
