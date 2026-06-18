#pragma once
// Clase Nodo genérica como base para Usuario y Pelicula
template <typename T>
class Nodo {
public:
    T Dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
    Nodo(T valor) : Dato(valor), siguiente(nullptr), anterior(nullptr) {}
};