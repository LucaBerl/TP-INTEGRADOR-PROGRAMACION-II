#include <iostream>
using namespace std;
#include <cstring>
#include "carga.h"

Carga::Carga(){

set_tipoCarga(0,"Bebidas");
set_tipoCarga(1,"Granos y cereales");
set_tipoCarga(2,"Cemento y Cal");
set_tipoCarga(3,"Arena");
set_tipoCarga(4,"Maderas");
set_tipoCarga(5,"Hierros/Aceros");
set_tipoCarga(6,"Vidrios/Cristales");
set_tipoCarga(7,"Maquinaria");
set_tipoCarga(8,"Electrodomesticos");
set_tipoCarga(9,"Electronicos");
set_tipoCarga(10,"Herramientas y ferreteria");
set_tipoCarga(11,"Muebles");
set_tipoCarga(12,"Neumaticos/Autopartes");
set_tipoCarga(13,"Pinturas y solventes");
set_tipoCarga(14,"Textiles");
set_tipoCarga(15,"Papeleria/Imprenta");
set_tipoCarga(16,"Jueguetes/Bazar");
set_tipoCarga(17,"Medicamentos");
set_tipoCarga(18,"Paqueteria");
set_tipoCarga(19,"Rodados");
set_tipoCarga(20,"Alimentos no perecederos");


}

void Carga::mostrar(){
    for(int i = 0; i < 21; i++) {
        cout << i+1 << ". " << _tipoCarga[i] << endl;
    }
}


void Carga::set_tipoCarga(int pos, std::string tipoCarga){

    strcpy(_tipoCarga[pos], tipoCarga.c_str());

}

std::string Carga::get_tipoCarga(int pos)const{
    return std::string(_tipoCarga[pos]);
}
