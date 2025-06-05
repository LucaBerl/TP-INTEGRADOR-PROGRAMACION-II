#include <iostream>
#include <cstring>
#include <cstdlib>
#include <functional>
#include "usuariosManager.h"
using namespace std;

string usuariosManager::generarSalt() {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string salt;
    for (int i = 0; i < 6; ++i) {
        salt += caracteres[rand() % (sizeof(caracteres) - 1)];
    }
    return salt;
}

size_t usuariosManager::calcularHash(const string& contrasena, const string& salt) {

    std::hash<std::string> hasher;
    return hasher(salt + contrasena); // Hash = salt + contraseña

}

void usuariosManager::crearUsuario(){

    Usuario usuario;

    establecerNombre(usuario);
    establecerContrasena(usuario);
    establecerRol(usuario);
    resumen_y_guardado(usuario);


}

void usuariosManager::establecerNombre(Usuario &usuario){

    string nombreUsuario;

    while (true){
        system("cls");
        cout << "Nombre de usuario (letras y/o números, sin espacios): ";
        cin >> nombreUsuario;
        if (usuario.set_nombre(nombreUsuario)){
            cout << endl << endl << "Usuario válido: " << usuario.get_nombre() << endl << endl;
            break;
        }
        else{
            cout << endl << endl << "Usuario incorrecto, intente nuevamente" << endl << endl;
            system("pause");
        }
    }

    cout << endl << endl << "1. Confirmar / " << "2.Volver  --> " ;
    int opcion;

    while (true) {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcion == 1){
                system("cls");
                cout << "NOMBRE GUARDADO ✔ " << endl << endl  ;
                system("pause");
                break;

        }else if(opcion == 2){
            return;
        }

    }

}

void usuariosManager::establecerContrasena(Usuario &usuario){

}

void usuariosManager::establecerRol(Usuario &usuario){

}

void usuariosManager::resumen_y_guardado(Usuario &usuario){

}
