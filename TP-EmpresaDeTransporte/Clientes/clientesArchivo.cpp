#include  "clientes.h"
#include  "clientesArchivo.h"





bool clientesArchivo::guardarCliente(const Clientes &cliente){


    FILE *pfile;
    bool guardo;

    pfile = fopen("clientes.dat","ab");

    if (pfile == nullptr){return false;}

    guardo = fwrite(&cliente,sizeof(Clientes),1,pfile);

    fclose(pfile);

    return guardo;

}
