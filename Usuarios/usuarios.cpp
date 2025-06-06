#include <iostream>
using namespace std;
#include "usuarios.h"
#include <cstring>
#include <cctype>

Usuario::Usuario(){

    set_idUsuario(0);
    set_nombre("");
    set_salt("");
    set_hashContrasena(0);
    set_rolUsuario(2);
    set_estado(true);

}

bool Usuario::set_nombre(std::string nombre){

    if (nombre.length() < sizeof(_nombre)){

        for (char &c : nombre){

            if(!std::isdigit(c) && !std::isalpha(c)){
                return false;
            }
        }
        strcpy(_nombre, nombre.c_str());
        return true;
    } else {return false;}
}

bool Usuario::set_salt(std::string salt){
    if (salt.length() < sizeof(_salt)){
        strcpy(_salt,salt.c_str());
        return true;
    } else {return false;}
}

void Usuario::set_hashContrasena(size_t hashContrasena){
    _hashContrasena = hashContrasena;
}

void Usuario::set_idUsuario(int ultimo){
    _idUsuario = ultimo + 1;
}

bool Usuario::set_rolUsuario(int rol){
    if(rol == 1 || rol == 2){
        _rolUsuario = rol;
        return true;
    }else {return false;}
}

void Usuario::set_estado(bool estado){
    _estado = estado;
}



std::string Usuario::get_nombre()const{
    return _nombre;
}
std::string Usuario::get_salt()const{
    return _salt;
}
size_t Usuario::get_hashContrasena()const{
    return _hashContrasena;
}
int Usuario::get_idUsuario()const{
    return _idUsuario;
}
int Usuario::get_rolUsuario()const{
    return _rolUsuario;
}
bool Usuario::get_estado()const{
    return _estado;
}
