#pragma once
#include "Dependencias.h"

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