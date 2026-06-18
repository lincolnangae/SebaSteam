#pragma once
#include "Dependencias.h"
using namespace std;
// Clase base de usuario
class Usuario
{
private:
    // Atributos comunes a todos los usuarios
    string UsuarioID;
    string Clave_usuario;
public:
    // Constructor por defecto
    Usuario() {
        UsuarioID = "";
        Clave_usuario = "";
    }
    // Constructor con parámetros
    Usuario(string id, string clave) {
        UsuarioID = id;
        Clave_usuario = clave;
    }
    // Getters
    string getUsuarioID() const {
        return UsuarioID;
    }
    string getClave() const {
        return Clave_usuario;
    }
    // Sobrecarga 1: Para insertar (Compara Usuario vs Usuario)
    bool operator==(const Usuario& otro) const {
        return UsuarioID == otro.UsuarioID;
    }
    // Sobrecarga 2: Para buscar y eliminar (Compara Usuario vs string)
    bool operator==(const string& id) const {
        return UsuarioID == id;
    }
};