#include <iostream>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <conio.h>
#include <iomanip>
#include "usuariosManager.h"
#include "usuariosArchivo.h"
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
        cout << "Nombre de usuario (letras y/o números, sin espacios, máximo 10 caracteres): ";
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

    const int MAX = 10; ///Cantidad máxima de caracteres
    char contrasena[MAX]; /// Cadena que contiene la contraseña
    char contrasena2[MAX];
    bool guardado = false;



    do{
        system("cls");
        int indice = 0; /// Indice del caracter que vamos ingresando
        char ch; /// Caracter que vamos ingresando


        cout << "Ingrese su contraseña (numeros y/o letras, sin espacios, máximo 10 caracteres): ";

        while (true) {
            ch = _getch(); /// Espera a que el usuario presione una tecla y la guarda en ch, sin mostrarla en pantalla.

            if (ch == 13) { /// ch == 13 seria el enter en codigo ASCII, se rompe bucle y termina de ingresar la contrasena
                break;

            } else if ((ch == 8 || ch == 127) && indice > 0) {

                indice--;          ///ch==8 y ch==127 son retrocesos, si se presionan y el indice es > 0 (o sea ya se escribio algo) el indice retrocede uno
                cout << "\b \b";  /// y aca borramos visualmente el último *

            } else if (indice < MAX - 1 && (isalpha(ch) || isdigit(ch))) {

                contrasena[indice++] = ch; /// Si no se ha alcanzado el limite de caracteres, y el ingresado es una letra o un numero, lo sumamos a la cadena
                cout << '*';               /// imprimimos un asterisco para que quede mas pro
            }
        }

        contrasena[indice] = '\0'; /// una vez que presionamos enter y salimos del bucle, guardamos el ultimo char como \0 para indicar la terminacion de la cadena




        int indice2 = 0;

        cout << endl << endl << "Ingrese nuevamente su contraseña: ";

        while (true) {
            ch = _getch(); /// Espera a que el usuario presione una tecla y la guarda en ch, sin mostrarla en pantalla.

            if (ch == 13) { /// ch == 13 seria el enter en codigo ASCII, se rompe bucle y termina de ingresar la contrasena
                break;

            } else if ((ch == 8 || ch == 127) && indice2 > 0) {

                indice2--;          ///ch==8 y ch==127 son retrocesos, si se presionan y el indice es > 0 (o sea ya se escribio algo) el indice retrocede uno
                cout << "\b \b";  /// y aca borramos visualmente el último *

            } else if (indice2 < MAX - 1 && (isalpha(ch) || isdigit(ch))) {

                contrasena2[indice2++] = ch; /// Si no se ha alcanzado el limite de caracteres, y el ingresado es una letra o un numero, lo sumamos a la cadena
                cout << '*';               /// imprimimos un asterisco para que quede mas pro
            }
        }

        contrasena2[indice2] = '\0'; /// una vez que presionamos enter y salimos del bucle, guardamos el ultimo char como \0 para indicar la terminacion de la cadena



        if (strcmp(contrasena, contrasena2) == 0){

            string salt = generarSalt();
            usuario.set_salt(salt);
            usuario.set_hashContrasena(calcularHash(contrasena,usuario.get_salt()));
            cout << endl << endl << "Contraseña guardada exitosamente ✔" << endl << endl;
            guardado = true;
            system("pause");


        }
        else{
            cout << endl << endl << "Contraseñas no coinciden, volver a ingresar" << endl << endl;
            system("pause");
        }

    }while(guardado == false);




}

void usuariosManager::establecerRol(Usuario &usuario){

    system("cls");
    cout << endl << "Establecer rol de usuario";
    cout << endl << endl << "1. Supervisor: Acceso a todas las funciones del programa.";
    cout << endl << "2. Operador: Acceso a todas las funciones, salvo creación de viajes." << endl << endl;
    cout << "Rol: ";

    int opcion;

    while (true) {
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcion == 1){
            system("cls");
            if(usuario.set_rolUsuario(opcion)){
                cout << "ROL (1) GUARDADO ✔ " << endl << endl  ;
                system("pause");
                break;
            }

        }else if(opcion == 2){
            system("cls");
            if(usuario.set_rolUsuario(opcion)){
                cout << "ROL (2) GUARDADO ✔ " << endl << endl  ;
                system("pause");
                break;
            }
        }

    }


}

void usuariosManager::resumen_y_guardado(Usuario &usuario){

    usuariosArchivo uArchivo;
    usuario.set_idUsuario(uArchivo.get_ultimoID());
    string rol;
    if (usuario.get_rolUsuario() == 1){rol = "Supervisor";}else{rol = "Operador";}

    cout << endl << "🆔 Usuario N°: " << usuario.get_idUsuario();
    cout << endl << "🧑‍✈️ Nombre: " << usuario.get_nombre();
    cout << endl << "📍 Rol: " << rol;
    cout << endl << endl;

    cout << endl << endl << "Confirmar usuario?" << endl;
    cout << endl << "1. SI" << endl << "2. NO" << endl << endl;
    int opcionNumerica;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){
            usuariosArchivo uArchivo;
            if(uArchivo.guardarUsuario(usuario)){
                system("cls");
                cout << "USUARIO GUARDADO CORRECTAMENTE ✔ " << endl << endl;
                system("pause");
                break;

            }

        }
        else if (opcionNumerica == 2){
            break;
        }

    }
}

void usuariosManager::listarUsuarios(){

    system("cls");

    usuariosArchivo uArchivo;
    Usuario usuario;

    cout << left;
    cout << setw(6) << "ID"
    << setw(15) << "NOMBRE"
    << setw(15) << "ROL";

    cout << endl << "------------------------------------------" << endl;


    int cantidadRegistros = uArchivo.get_cantidadRegistros();


    for(int i = 0;i < cantidadRegistros; i++){

        if(uArchivo.leerUsuario(i,usuario)){
            if (usuario.get_estado() == 1){
                string rol;
                if (usuario.get_rolUsuario() == 1){rol = "Supervisor";}else{rol = "Operador";}
                cout << setw(6) << usuario.get_idUsuario()
                << setw(15) << usuario.get_nombre()
                << setw(15) << rol;
                cout << endl;
            }
        }else{cout << "Lectura incorrecta";}

    }

    cout << endl << endl;
    system("pause");

}

int usuariosManager::validarUsuario(){

    usuariosArchivo uArchivo;
    Usuario usuario, usuarioValido;
    char contrasena[20];
    bool usuarioEncontrado = false;
    bool passCorrecta = false;
    string nombreUsuario, pass;
    int cont = 0;
    size_t passHasheada;

    int cantidadRegistros = uArchivo.get_cantidadRegistros();

    while (true){
        system("cls");
        cout << endl << "Nombre de usuario: ";
        cin >> nombreUsuario;
        usuarioEncontrado = false;
        for(int i = 0;i < cantidadRegistros; i++){

            if(uArchivo.leerUsuario(i,usuario)){
                if (usuario.get_estado() == 1 && usuario.get_nombre() == nombreUsuario){
                    usuarioValido = usuario;
                    usuarioEncontrado = true;
                    break;
                }
            }else{
                system("cls");
                cout << "Lectura incorrecta de registro" << endl << endl;
                system("pause");
                return 0;
            }

        }

        if (!usuarioEncontrado){
            cout << endl << endl << "Usuario incorrecto" << endl << endl;
            system("pause");
        }
        else{break;}

    }


    while (true){

        system("cls");
        cout << endl << "Contraseña: ";



        int indice = 0; /// Indice del caracter que vamos ingresando
        char ch; /// Caracter que vamos ingresando

        while (true) {
            ch = _getch(); /// Espera a que el usuario presione una tecla y la guarda en ch, sin mostrarla en pantalla.

            if (ch == 13) { /// ch == 13 seria el enter en codigo ASCII, se rompe bucle y termina de ingresar la contrasena
                break;

            } else if ((ch == 8 || ch == 127) && indice > 0) {

                indice--;          ///ch==8 y ch==127 son retrocesos, si se presionan y el indice es > 0 (o sea ya se escribio algo) el indice retrocede uno
                cout << "\b \b";  /// y aca borramos visualmente el último *

            }else if (indice < 19){
                contrasena[indice++] = ch;
                cout << '*'; // Mostrar asterisco
            }
        }
        contrasena[indice] = '\0';

        pass = contrasena;

        cont++;

        passHasheada = calcularHash(pass,usuarioValido.get_salt());

        if (passHasheada == usuarioValido.get_hashContrasena()){
            system("cls");
            cout << endl << "Acceso correcto, bienvenido" << endl << endl;
            system("pause");
            return usuarioValido.get_rolUsuario();
        }

        if (cont == 3){
            system("cls");
            cout << endl << "Demasiados intentos, volver a intentar mas tarde" << endl << endl;
            system("pause");
            return 0;
        }

    }


}

void usuariosManager::bajaUsuario(){

    listarUsuarios();

    int opcionNumerica;
    usuariosArchivo uArchivo;
    Usuario usuario;

    cout << endl << endl << "Por favor, seleccionar el ID de usuario a dar de baja: ";

    while (true) {

        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion, cantidadRegistros = uArchivo.get_cantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(uArchivo.leerUsuario(i,usuario)){
            if (usuario.get_idUsuario() == opcionNumerica && usuario.get_estado() == 1){
                cout << endl << endl << "Usuario: " << usuario.get_nombre();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Desea dar de baja este usuario?";
                cout << endl << "1. SI" << endl << "2. NO" << endl;
                break;
            }
        }else{
            system("cls");
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado){
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1){
            usuario.set_estado(0);
            if(uArchivo.guardarUsuarioModificado(posicion,usuario)){
                system("cls");
                cout << "USUARIO ELIMINADO ✔ " << endl << _getch() ;
                return;
            }else{
                system("cls");
                cout << "Error en la baja de usuario" << _getch() ;
                return;
            }
        }else if(opcionNumerica == 2){
            return;
        }

    }
}

void usuariosManager::cambiarRol(){

    listarUsuarios();

    int opcionNumerica;
    usuariosArchivo uArchivo;
    Usuario usuario;

    cout << endl << endl << "Por favor, seleccionar el ID de usuario que desea cambiarle el rol: ";

    while (true) {

        cin >> opcionNumerica;

        if (cin.fail() || opcionNumerica <= 0) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else{

            cin.ignore(1000, '\n'); // Por si quedan residuos
            cout << endl << "ID seleccionado: " << opcionNumerica << endl << endl;
            system("pause");
            break; // Salir del bucle, entrada válida
        }
    }

    system("cls");

    int posicion, cantidadRegistros = uArchivo.get_cantidadRegistros();
    bool idEncontrado = false;

    for(int i = 0;i < cantidadRegistros; i++){

        if(uArchivo.leerUsuario(i,usuario)){
            if (usuario.get_idUsuario() == opcionNumerica && usuario.get_estado() == 1){
                cout << endl << endl << "Usuario: " << usuario.get_nombre();
                posicion = i;
                idEncontrado = true;
                cout << endl << endl << "Que rol desea asignarle?";
                cout << endl << "1. Supervisor" << endl << "2. Operador" << endl;
                break;
            }
        }else{
            system("cls");
            cout << "Lectura incorrecta";
            system("pause");
            return;
        }

    }

    if(!idEncontrado){
        cout << endl << "El ID seleccionado no existe en los registros" << endl << endl;
        system("pause");
        return;
    }

    cout << endl;

    while (true) {
        cin >> opcionNumerica;

        if (cin.fail() || (opcionNumerica != 1 && opcionNumerica != 2)) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout << endl << "Ingreso incorrecto, intente nuevamente: ";
        }else if(opcionNumerica == 1 || opcionNumerica == 2){
            usuario.set_rolUsuario(opcionNumerica);
            if(uArchivo.guardarUsuarioModificado(posicion,usuario)){
                system("cls");
                cout << "USUARIO MODIFICADO ✔ " << endl << _getch() ;
                return;
            }else{
                system("cls");
                cout << "Error en la modificacion de usuario" << _getch() ;
                return;
            }
        }

    }

}
