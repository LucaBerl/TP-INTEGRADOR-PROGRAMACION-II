#pragma once
#include <string>

class Carga{

private:
    char _tipoCarga[21][30];

public:
    Carga();
    void mostrar();

    void set_tipoCarga(int pos, std::string tipoCarga);
    std::string get_tipoCarga(int pos)const;


};
