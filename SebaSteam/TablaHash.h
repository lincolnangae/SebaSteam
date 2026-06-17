#pragma once
#include "Dependencias.h"
#include "Nodo.h"

using namespace std;

template <typename T>
class TablaHash {
private:
    vector<list<Nodo<T>>> Lista;
    int capacidad;

    // Función de hash polinomial
    int calcularHashPolinomial(const string& clave) const {
        long long hash_value = 0;
        long long p = 31;
        long long p_pow = 1;

        for (char c : clave) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % capacidad;
            p_pow = (p_pow * p) % capacidad;
        }
        return abs(static_cast<int>(hash_value));
    }

public:
    TablaHash(int cap = 11) : capacidad(cap) {
        Lista.resize(capacidad);
    }

    void insertar(const string& clave, const T& valor) {
        int indice = calcularHashPolinomial(clave);

        for (const auto& nodo : Lista[indice]) {
            if (nodo.Dato == valor) {
                return;
            }
        }

        Lista[indice].push_back(Nodo<T>(valor));
    }

    T* buscar(const string& clave) {
        int indice = calcularHashPolinomial(clave);

        for (auto& nodo : Lista[indice]) {
            if (nodo.Dato == clave) {
                return &(nodo.Dato);
            }
        }
        return nullptr;
    }

    bool eliminar(const string& clave) {
        int indice = calcularHashPolinomial(clave);

        for (auto it = Lista[indice].begin(); it != Lista[indice].end(); ++it) {
            if (it->Dato == clave) {
                Lista[indice].erase(it);
                return true;
            }
        }
        return false;
    }
};