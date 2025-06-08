#pragma once
#include <string>
#include "usuarios.h"

class usuariosManager{


public:

    std::string generarSalt();
    size_t calcularHash(const std::string& contrasena, const std::string& salt);
    void crearUsuario();
    void establecerNombre(Usuario &usuario);
    void establecerContrasena(Usuario &usuario);
    void establecerRol(Usuario &usuario);
    void resumen_y_guardado(Usuario &usuario);
    void listarUsuarios();
    int validarUsuario();
    void bajaUsuario();
    void cambiarRol();
    bool nombreUsuarioExistente(std::string nombreUsuario);

};
