#pragma once
#include <string>

class Usuario {

private:

    char _nombre[11];
    char _salt[10];            // Salt aleatorio
    size_t _hashContrasena;    // Contraseña hasheada + salt
    int _idUsuario;
    int _rolUsuario;           // 1- Supervisor , 2- Operador
    bool _estado;

public:

    Usuario();

    bool set_nombre(std::string nombre);
    bool set_salt(std::string salt);
    void set_hashContrasena(size_t hashContrasena);
    void set_idUsuario(int ultimo);
    bool set_rolUsuario(int rol);
    void set_estado(bool estado);

    std::string get_nombre()const;
    std::string get_salt()const;
    size_t get_hashContrasena()const;
    int get_idUsuario()const;
    int get_rolUsuario()const;
    bool get_estado()const;

};

