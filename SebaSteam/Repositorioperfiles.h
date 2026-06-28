#pragma once
#include "Dependencias.h"
// IMPORTANTE: a proposito NO se pone "using namespace std;" aqui.
// Este archivo se incluye desde SeleccionPerfil.h, y un "using namespace std;"
// a nivel global se filtra a TODO archivo que lo incluya despues (incluyendo
// el bloque "namespace SebaSteam"), chocando con el array<T>^ de C++/CLI.
// Por eso todo aqui se califica explicitamente con "std::".

// Repositorio simple para los "perfiles" creados por el usuario en la
// pantalla de Selecci\xf3n de Perfil. A diferencia de RepositorioUsuario,
// aqu\xed NO se maneja clave: solo un nombre, persistido en un archivo
// de texto (uno por l\xednea), igual de simple que Usuarios.txt.
class RepositorioPerfiles {
private:
    std::string rutaArchivo;
    std::vector<std::string> perfiles;

    // Las comas se usan como separador en otros archivos del proyecto,
    // asi que no se permiten en el nombre del perfil para evitar problemas
    bool contieneComa(const std::string& cadena) {
        for (char c : cadena) {
            if (c == ',') return true;
        }
        return false;
    }

public:
    RepositorioPerfiles(std::string archivo) {
        rutaArchivo = archivo;
    }

    // Carga inicial de los perfiles ya creados desde el archivo de texto
    void cargarDesdeArchivo() {
        perfiles.clear();
        std::ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) return;

        std::string linea;
        while (std::getline(archivo, linea)) {
            // Se descartan posibles lineas vacias al final del archivo
            if (!linea.empty()) {
                perfiles.push_back(linea);
            }
        }
        archivo.close();
    }

    std::vector<std::string> obtenerPerfiles() {
        return perfiles;
    }

    bool existePerfil(const std::string& nombre) {
        for (size_t i = 0; i < perfiles.size(); ++i) {
            if (perfiles[i] == nombre) return true;
        }
        return false;
    }

    // Registra un nuevo perfil y lo persiste de inmediato en el archivo.
    // Si el nombre ya existe simplemente no se duplica (no es un error).
    bool registrarPerfil(const std::string& nombre) {
        if (nombre.empty() || contieneComa(nombre)) {
            return false;
        }
        if (existePerfil(nombre)) {
            return false;
        }

        perfiles.push_back(nombre);

        std::ofstream archivo(rutaArchivo, std::ios::app);
        if (archivo.is_open()) {
            archivo << nombre << "\n";
            archivo.close();
        }
        return true;
    }
};