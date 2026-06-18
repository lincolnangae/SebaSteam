#pragma once
#include "Dependencias.h"
#include "ListaSimple.h"
using namespace std;
class Pelicula {
private:
    string peliculaID;
    string nombre;
    string idImagen;
    vector<string> categorias;
    string sinopsis;
    int vistas;
    float calificacion;
    int lanzamiento;
    ListaSimple<string> comentarios;
public:
    Pelicula() : peliculaID(""), nombre(""), idImagen(""), sinopsis(""), vistas(0), calificacion(0.0f), lanzamiento(2026) {}
    Pelicula(string id, string nom, string idImg, vector<string> cats, string sin, int vis, float cal, int an) {
        peliculaID = id;
        nombre = nom;
        idImagen = idImg;
        categorias = cats;
        sinopsis = sin;
        vistas = vis;
        calificacion = cal;
        lanzamiento = an;
    }
	// Getters y setters
    string getPeliculaID() const { return peliculaID; }
    string getNombre() const { return nombre; }
    string getIdImagen() const { return idImagen; }
    string getSinopsis() const { return sinopsis; }
    int getVistas() const { return vistas; }
    float getCalificacion() const { return calificacion; }
    int getAnio() const { return lanzamiento; }
    vector<string> getCategorias() const { return categorias; }
    ListaSimple<string>& getComentarios() { return comentarios; }
    void incrementarVistas() { vistas++; }
    void actualizarCalificacion(float nuevaNota) { calificacion = nuevaNota; }
    bool operator==(const Pelicula& otra) const {
        return peliculaID == otra.peliculaID;
    }
    bool operator==(const string& id) const {
        return peliculaID == id;
    }
};