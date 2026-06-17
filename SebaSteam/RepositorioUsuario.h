#pragma once
#include "Dependencias.h"
#include "TablaHash.h"
#include "Usuario.h"

using namespace std;

class RepositorioUsuario {
private:
    TablaHash<Usuario>* tablaUsuarios;
    string rutaArchivo;

    // Validacion de espacios en blanco en las cadenas
    bool contieneEspacios(const string& cadena) {
        for (char c : cadena) {
            if (c == ' ') return true;
        }
        return false;
    }

    // Verificacion de restricciones en los campos de texto
    bool esEstructuraValida(const string& id, const string& clave) {
        if (id.empty() || clave.empty()) return false;
        if (contieneEspacios(id)) return false;
        return true;
    }

public:
    RepositorioUsuario(string archivo) {
        rutaArchivo = archivo;
        tablaUsuarios = new TablaHash<Usuario>(13);
    }

    ~RepositorioUsuario() {
        delete tablaUsuarios;
    }

    // Carga inicial de datos desde el almacenamiento fisico
    void cargarDesdeArchivo() {
        ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) return;

        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string usuario, id, clave;

            if (getline(ss, id, ',') && getline(ss, clave, ',')) {
                Usuario user(id, clave);
                tablaUsuarios->insertar(id, user);
            }
        }
        archivo.close();
    }

    // Registro de un nuevo usuario en el sistema
    bool registrarUsuario(string id, string clave) {
        if (!esEstructuraValida(id, clave)) {
            return false;
        }

        if (tablaUsuarios->buscar(id) != nullptr) {
            return false;
        }

        Usuario nuevo( id, clave);
        tablaUsuarios->insertar(id, nuevo);

        // Persistencia inmediata en el archivo de texto
        ofstream archivo(rutaArchivo, ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << clave << "\n";
            archivo.close();
        }
        return true;
    }

    // Busqueda directa en memoria para la validacion de credenciales
    Usuario* obtenerUsuario(string id) {
        if (contieneEspacios(id) || id.empty()) return nullptr;
        return tablaUsuarios->buscar(id);
    }
};