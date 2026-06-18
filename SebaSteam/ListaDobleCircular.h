#pragma once
#include "Nodo.h"

template <typename T>
class ListaDobleCircular {
private:
    Nodo<T>* cabeza;
    int cantidad;

public:
    ListaDobleCircular() : cabeza(nullptr), cantidad(0) {}

    ~ListaDobleCircular() {
        if (cabeza == nullptr) return;
        Nodo<T>* actual = cabeza;
        for (int i = 0; i < cantidad; ++i) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
        else {
            Nodo<T>* ultimo = cabeza->anterior;
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
        }
        cantidad++;
    }

    Nodo<T>* getCabeza() { return cabeza; }
    int getCantidad() const { return cantidad; }
};