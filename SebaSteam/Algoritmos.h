#pragma once
#include "Pelicula.h"

class ClaseAlgoritmos {
private:
    static void mergeVistas(vector<Pelicula*>& vec, int izq, int medio, int der) {
        int n1 = medio - izq + 1;
        int n2 = der - medio;

        vector<Pelicula*> L(n1);
        vector<Pelicula*> R(n2);

        for (int i = 0; i < n1; i++) L[i] = vec[izq + i];
        for (int j = 0; j < n2; j++) R[j] = vec[medio + 1 + j];

        int i = 0, j = 0, k = izq;
        // Criterio de ordenamiento: Mayor numero de vistas primero
        while (i < n1 && j < n2) {
            if (L[i]->getVistas() >= R[j]->getVistas()) {
                vec[k] = L[i];
                i++;
            }
            else {
                vec[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) { vec[k] = L[i]; i++; k++; }
        while (j < n2) { vec[k] = R[j]; j++; k++; }
    }

public:
    static void mergeSort(vector<Pelicula*>& vec, int izq, int der) {
        if (izq < der) {
            int medio = izq + (der - izq) / 2;
            mergeSort(vec, izq, medio);
            mergeSort(vec, medio + 1, der);
            mergeVistas(vec, izq, medio, der);
        }
    }
};