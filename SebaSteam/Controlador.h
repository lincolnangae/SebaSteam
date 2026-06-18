#pragma once
#include "RepositorioUsuario.h"
#include "RepositorioPelicula.h"
#include "ListaDobleCircular.h"
#include "Algoritmos.h"
#include <msclr/marshal_cppstd.h>
#include <vector>

using namespace std;
using namespace System;
using namespace msclr::interop;

public ref class ControladoraPrincipal {
private:
    RepositorioUsuario* repositorio;
    RepositorioPelicula* repoPelicula;

    // Almacenamiento central de todas las peliculas del dataset
    vector<Pelicula>* vectorBasePeliculas;

    // LosMasVistos
    ListaDobleCircular<Pelicula*>* listaMasVistos;

    // Puntero que mueve la lista de una categoria
    Nodo<Pelicula*>* pivoteMasVistos;

public:
    ControladoraPrincipal() {
        repositorio = new RepositorioUsuario("Usuarios.txt");
        repositorio->cargarDesdeArchivo();

        vectorBasePeliculas = new vector<Pelicula>();

        repoPelicula = new RepositorioPelicula("peliculas.txt");

        repoPelicula->cargarDesdeArchivo(vectorBasePeliculas);

        listaMasVistos = new ListaDobleCircular<Pelicula*>();
        pivoteMasVistos = nullptr;

        InicializarCatalogoInicio();
    }

    ~ControladoraPrincipal() {
        this->!ControladoraPrincipal();
    }

    !ControladoraPrincipal() {
        if (repositorio != nullptr) {
            delete repositorio;
            repositorio = nullptr;
        }
        if (repoPelicula != nullptr) {
            delete repoPelicula;
            repoPelicula = nullptr;
        }
        if (vectorBasePeliculas != nullptr) {
            delete vectorBasePeliculas;
            vectorBasePeliculas = nullptr;
        }
        if (listaMasVistos != nullptr) {
            delete listaMasVistos;
            listaMasVistos = nullptr;
        }
    }

    void InicializarCatalogoInicio() {
        // Temporal para copiar los datos
        vector<Pelicula*> punterosTemporales;

        for (size_t i = 0; i < vectorBasePeliculas->size(); ++i) {
            punterosTemporales.push_back(&(*vectorBasePeliculas)[i]);
        }

        if (!punterosTemporales.empty()) {
            ClaseAlgoritmos::mergeSort(punterosTemporales, 0, punterosTemporales.size() - 1);
        }

		// Los 15 mas vistos de manera ordenada en la lista doble circular
        int limite = punterosTemporales.size() < 15 ? punterosTemporales.size() : 15;
        for (int i = 0; i < limite; ++i) {
            listaMasVistos->insertar(punterosTemporales[i]);
        }

        // El pivote de mas vistos
        if (listaMasVistos->getCabeza() != nullptr) {
            pivoteMasVistos = listaMasVistos->getCabeza();
        }
    }


    void AvanzarCarruselMasVistos() {
        if (pivoteMasVistos != nullptr) {
            pivoteMasVistos = pivoteMasVistos->siguiente;
        }
    }

    void RetrocederCarruselMasVistos() {
        if (pivoteMasVistos != nullptr) {
            pivoteMasVistos = pivoteMasVistos->anterior;
        }
    }

    Pelicula* ObtenerPeliculaFilaMasVistos(int offset) {
        if (pivoteMasVistos == nullptr) return nullptr;

        Nodo<Pelicula*>* actual = pivoteMasVistos;
        for (int i = 0; i < offset; ++i) {
            actual = actual->siguiente;
        }
        return actual->Dato;
    }

    void RegistrarVisualizacion(Pelicula* p) {
        if (p != nullptr) {
            p->incrementarVistas();
        }
    }

    bool autenticarUsuario(String^ id, String^ clave) {
        string idStd = marshal_as<string>(id);
        string claveStd = marshal_as<string>(clave);

        Usuario* user = repositorio->obtenerUsuario(idStd);
        if (user != nullptr) {
            return user->getClave() == claveStd;
        }
        return false;
    }

    // Registro de un nuevo usuario en el sistema de persistencia
    bool agregarUsuario(String^ id, String^ clave) {
        string idStd = marshal_as<string>(id);
        string claveStd = marshal_as<string>(clave);

        return repositorio->registrarUsuario(idStd, claveStd);
    }
};