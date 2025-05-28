
#pragma once
#include "clientes.h"

class clientesArchivo{



public:

    bool guardarCliente(const Clientes &cliente);

    int getCantidadClientes();

    bool leerClientes(int pos, Clientes &clientes);

    int get_ultimoID();











};
