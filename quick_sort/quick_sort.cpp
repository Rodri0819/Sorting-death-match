#include "quick_sort.h"
#include <vector>
#include <cstdint>
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <chrono>    // medir tiempo

//Variables globales para contar comparaciones e intercambios
static size_t comparaciones = 0;
static size_t intercambios = 0;

//Función que realiza la partición del arreglo y retorna el indice del pivote
int partition(std::vector<int32_t>& A, int low, int high) {
    //Elegimos un indice aleatorio y lo usamos como pivote
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(A[randomIndex], A[high]); //Movemos el pivote al final

    int32_t pivot = A[high]; //Valor del pivote
    int i = low - 1;         //Indice del menor elemento

    //Recorremos y colocamos los menores a la izquierda del pivote
    for (int j = low; j <= high - 1; j++) {
        comparaciones++; //Conteo de comparaciones (no tan relevante en el analisis)
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]); //Intercambiamos si es menor que el pivote
            intercambios++;
        }
    }

    // olocamos el pivote en su posición final
    std::swap(A[i + 1], A[high]);
    intercambios++;
    return i + 1;
}

//Función auxiliar recursiva de Quick Sort
void quickSortAux(std::vector<int32_t>& A, int low, int high) {
    while (low < high) {
        int pi = partition(A, low, high); //Obtenemos el indice del pivote

        //Recursamos primero sobre la sublista más pequeña para optimizar espacio
        if (pi - low < high - pi) {
            quickSortAux(A, low, pi - 1); //Sublista izquierda
            low = pi + 1; //Ajustamos limites derecho
        } else {
            quickSortAux(A, pi + 1, high); //Sublista derecha
            high = pi - 1; //Ajustamos limites izquiedo
        }
    }
}

// Función principal de Quick Sort
void quickSort(std::vector<int32_t>& A) {
    srand(time(nullptr));      //Inicializamos la semilla para pivote aleatorio
    comparaciones = 0;
    intercambios = 0;

    auto start = std::chrono::high_resolution_clock::now();   //Medición de tiempo inicio
    quickSortAux(A, 0, A.size() - 1);                          //Ordenar el arreglo
    auto end = std::chrono::high_resolution_clock::now();     //Medición de tiempo fin

    std::chrono::duration<double, std::milli> duracion = end - start; //Duración total en milisegundos
}
