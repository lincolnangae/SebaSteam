#pragma once
#include "RepositorioUsuario.h"

using namespace std;

public ref class ControladoraPrincipal {
private:
    RepositorioUsuario* repositorio;

public:
    ControladoraPrincipal() {
        repositorio = new RepositorioUsuario("Usuarios.txt");
        repositorio->cargarDesdeArchivo();
    }

    // Destructor general 
    ~ControladoraPrincipal() {
        this->!ControladoraPrincipal();
    }

	// Efectuar el borrado de recursos no administrados
    !ControladoraPrincipal() {
        if (repositorio != nullptr) {
            delete repositorio;
            repositorio = nullptr;
        }
    }

    // Validacion de credenciales
    bool autenticarUsuario(String^ id, String^ clave) {
        string idStd = marshal_as<string>(id);
        string claveStd = marshal_as<string>(clave);

        Usuario* user = repositorio->obtenerUsuario(idStd);
        if (user != nullptr) {
            return user->getClave() == claveStd;
        }
        return false;
    }

    // Registro de datos para el boton de Registrar
    bool agregarUsuario(String^ id, String^ clave) {
        string idStd = marshal_as<string>(id);
        string claveStd = marshal_as<string>(clave);

        return repositorio->registrarUsuario(idStd, claveStd);
    }
};