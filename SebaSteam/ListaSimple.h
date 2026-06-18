#pragma once
#include "Dependencias.h"
#include "Nodo.h"
using namespace std;
template <typename T>
class ListaSimple {
private:
    Nodo<T>* cabeza;
    int tamano;
    void eliminarFinal() {
        if (cabeza == nullptr) return;
        if (cabeza->siguiente == nullptr) {
            delete cabeza;
            cabeza = nullptr;
            tamano = 0;
            return;
        }
        Nodo<T>* penultimo = cabeza;
        while (penultimo->siguiente->siguiente != nullptr) {
            penultimo = penultimo->siguiente;
        }
        delete penultimo->siguiente;
        penultimo->siguiente = nullptr;
        tamano--;
    }
public:
    ListaSimple() : cabeza(nullptr), tamano(0) {}
    ~ListaSimple() {
        while (cabeza != nullptr) {
            Nodo<T>* aux = cabeza->siguiente;
            delete cabeza;
            cabeza = aux;
        }
    }
    // Insertar con limite de 3 elementos
    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        tamano++;
        if (tamano > 3) {
            eliminarFinal();
        }
    }
    int getCapacidad() const { return tamano; }
    // Convierte los elementos a un vector para facilitar el pintado en WinForms
	vector <T> obtenerComentarios() const {
		vector<T> comentarios;
		Nodo<T>* actual = cabeza;
		while (actual != nullptr) {
			comentarios.push_back(actual->Dato);
			actual = actual->siguiente;
		}
		return comentarios;
	}
};