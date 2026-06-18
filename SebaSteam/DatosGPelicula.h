#pragma once
#include "Dependencias.h"
#include <random>
using namespace std;
class DatasetGenerador {
public:
    static void inicializarMetricasPelicula(int& vistasOut, float& calificacionOut, int& lanzamientoOut) {
        random_device rd;
        mt19937 gen(rd());
        // Lambdas para la generacion controlada de datos dinamicos
        auto generarVistas = [](mt19937& g) {
            uniform_int_distribution<> dist(500, 500000);
            return dist(g);
            };
        auto generarCalificacion = [](mt19937& g) {
            uniform_real_distribution<> dist(1.0, 5.0);
            return static_cast<float>(floor(dist(g) * 10.0f) / 10.0f);
            };
        auto generarLanzamiento = [](mt19937& g) {
            uniform_int_distribution<> dist(1980, 2026);
            return dist(g);
            };
        vistasOut = generarVistas(gen);
        calificacionOut = generarCalificacion(gen);
        lanzamientoOut = generarLanzamiento(gen);
    }
};