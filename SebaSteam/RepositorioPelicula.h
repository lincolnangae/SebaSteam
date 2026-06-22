#pragma once
#include "Dependencias.h"
#include "TablaHash.h"
#include "Pelicula.h"
#include "DatosGPelicula.h"
#include <fstream>
#include <sstream>
using namespace std;
class RepositorioPelicula {
private:
	TablaHash<Pelicula>* tablaPeliculas;
	string rutaArchivo;
	// Verificacion de la existencia del archivo fisico
	void asegurarArchivo() {
		ifstream archivo(rutaArchivo);
		if (!archivo) {
			ofstream nuevoArchivo(rutaArchivo);
			nuevoArchivo.close();
		}
	}
public:
	RepositorioPelicula(string archivo) {
		rutaArchivo = archivo;
		asegurarArchivo();
		tablaPeliculas = new TablaHash<Pelicula>(101);
	}
	~RepositorioPelicula() {
		delete tablaPeliculas;
	}
	void cargarDesdeArchivo(vector<Pelicula>* vecDestino = nullptr) {
		ifstream archivo(rutaArchivo);
		if (!archivo.is_open()) return;
		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string id, nombre, idImagen, catsStr, sinopsis, idImagenTMP;
			idImagen = "Imagenes/Peliculas/";
			if (getline(ss, id, ',') &&
				getline(ss, nombre, ',') &&
				getline(ss, idImagenTMP, ',') &&
				getline(ss, catsStr, ',') &&
				getline(ss, sinopsis, ',')) {
				idImagen += (idImagenTMP + ".jpg");
				int vistas = 0;
				float calificacion = 0.0f;
				int anio = 2026;
				DatasetGenerador::inicializarMetricasPelicula(vistas, calificacion, anio);
				vector<string> categorias;
				stringstream ssCats(catsStr);
				string cat;
				while (getline(ssCats, cat, '|')) {
					categorias.push_back(cat);
				}
				Pelicula p(id, nombre, idImagen, categorias, sinopsis, vistas, calificacion, anio);
				tablaPeliculas->insertar(id, p);
				if (vecDestino != nullptr) {
					vecDestino->push_back(p);
				}
			}
		}
		archivo.close();
	}
	// Almacenamiento definitivo del estado modificado del catalogo
	void guardarEnArchivo(const vector<Pelicula>& catalogoCompleto) {
		ofstream archivo(rutaArchivo, ios::trunc);
		if (!archivo.is_open()) return;
		for (const auto& p : catalogoCompleto) {
			string catsStr = "";
			vector<string> cats = p.getCategorias();
			for (size_t i = 0; i < cats.size(); ++i) {
				catsStr += cats[i];
				if (i < cats.size() - 1) catsStr += "|";
			}
			archivo << p.getPeliculaID() << ","
				<< p.getNombre() << ","
				<< p.getIdImagen() << ","
				<< catsStr << ","
				<< p.getSinopsis() << ","
				<< p.getVistas() << ","
				<< p.getCalificacion() << ","
				<< p.getAnio() << "\n";
		}
		archivo.close();
	}
	// Recuperacion indexada mediante la clave unica hash
	Pelicula* obtenerPelicula(string id) {
		if (id.empty()) return nullptr;
		return tablaPeliculas->buscar(id);
	}
};