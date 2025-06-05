#pragma once

class usuariosArchivo{

public:

    int get_cantidadRegistros();
    int get_ultimoID();
    bool leerUsuario(int pos, Usuario &usuario);
    bool guardarUsuario(const Usuario &usuario);
    bool guardarUsuarioModificado(int pos,Usuario &usuario);
    bool buscarUsuarioPorId(int idBuscado,Usuario &usuarioEncontrado);
    int buscarRegistro(int id);


};
