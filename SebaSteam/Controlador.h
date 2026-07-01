#pragma once
#include "RepositorioUsuario.h"
#include "RepositorioPelicula.h"
#include "ListaDobleCircular.h"
#include "Algoritmos.h"
#include <algorithm>
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
    // Recientemente Agregados
    ListaDobleCircular<Pelicula*>* listaRecientes;
    Nodo<Pelicula*>* pivoteRecientes;
    // Recomendados
    ListaDobleCircular<Pelicula*>* listaRecomendados;
    Nodo<Pelicula*>* pivoteRecomendados;
public:
    ControladoraPrincipal() {
        repositorio = new RepositorioUsuario("Usuarios.txt");
        repositorio->cargarDesdeArchivo();
        vectorBasePeliculas = new vector<Pelicula>();
        repoPelicula = new RepositorioPelicula("peliculas.txt");
        repoPelicula->cargarDesdeArchivo(vectorBasePeliculas);
        listaMasVistos = new ListaDobleCircular<Pelicula*>();
        pivoteMasVistos = nullptr;
        listaRecientes = new ListaDobleCircular<Pelicula*>();
        pivoteRecientes = nullptr;
        listaRecomendados = new ListaDobleCircular<Pelicula*>();
        pivoteRecomendados = nullptr;
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
        if(listaRecientes != nullptr)
        {
            delete listaRecientes;
            listaRecientes = nullptr;
        }
        if(listaRecomendados != nullptr)
        {
            delete listaRecomendados;
            listaRecomendados = nullptr;
        }
    }
    void InicializarCatalogoInicio() {
        // Temporal para copiar los datos
        vector<Pelicula*> punterosTemporales;
        for (size_t i = 0; i < vectorBasePeliculas->size(); ++i) {
            punterosTemporales.push_back(&(*vectorBasePeliculas)[i]);
        }
        if (!punterosTemporales.empty()) {
            //ordenamiento merge para visitas
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

		// Los 15 recientes agregados de manera ordenada en la lista doble circular
        int limiteRecientes = vectorBasePeliculas->size() < 15 ? vectorBasePeliculas->size() : 15;
        for(int i = 0; i < limiteRecientes; ++i)
        {
            // Se insertan de atras hacia adelante
            listaRecientes->insertar(&(*vectorBasePeliculas)[vectorBasePeliculas->size() - 1 - i]);
        }
		// El pivote de recientes
        if(listaRecientes->getCabeza() != nullptr)
        {
            pivoteRecientes = listaRecientes->getCabeza();
        }

		// los 15 recomendados de manera aleatoria en la lista doble circular
        random_shuffle(punterosTemporales.begin(), punterosTemporales.end());
        int limiteRecomendados = punterosTemporales.size() < 15 ? punterosTemporales.size() : 15;
        for(int i = 0; i < limiteRecomendados; ++i)
        {
            listaRecomendados->insertar(punterosTemporales[i]);
        }
		// El pivote de recomendados
        if(listaRecomendados->getCabeza() != nullptr)
        {
            pivoteRecomendados = listaRecomendados->getCabeza();
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

    void AvanzarCarruselRecientes()
    {
        if(pivoteRecientes != nullptr) pivoteRecientes = pivoteRecientes->siguiente;
    }
    void RetrocederCarruselRecientes()
    {
        if(pivoteRecientes != nullptr) pivoteRecientes = pivoteRecientes->anterior;
    }
    Pelicula* ObtenerPeliculaFilaRecientes(int offset)
    {
        if(pivoteRecientes == nullptr) return nullptr;
        Nodo<Pelicula*>* actual = pivoteRecientes;
        for(int i = 0; i < offset; ++i) actual = actual->siguiente;
        return actual->Dato;
    }


    void AvanzarCarruselRecomendados()
    {
        if(pivoteRecomendados != nullptr) pivoteRecomendados = pivoteRecomendados->siguiente;
    }
    void RetrocederCarruselRecomendados()
    {
        if(pivoteRecomendados != nullptr) pivoteRecomendados = pivoteRecomendados->anterior;
    }
    Pelicula* ObtenerPeliculaFilaRecomendados(int offset)
    {
        if(pivoteRecomendados == nullptr) return nullptr;
        Nodo<Pelicula*>* actual = pivoteRecomendados;
        for(int i = 0; i < offset; ++i) actual = actual->siguiente;
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
    string printMasVistas(int indx) {
        if (pivoteMasVistos == nullptr) return "";
        Nodo<Pelicula*>* curr = pivoteMasVistos;
        for (int i = 0; i < indx; i++) curr = curr->siguiente;
        return curr->Dato->getIdImagen();

    }
    void guardarArchivos() {
        if(repoPelicula == nullptr) return;
		repoPelicula->guardarEnArchivo(*vectorBasePeliculas);
    }
};