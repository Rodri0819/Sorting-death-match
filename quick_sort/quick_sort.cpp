#include "quick_sort.h"
#include <vector>
#include <cstdint>
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <chrono>    // medir tiempo

static size_t comparaciones = 0;
static size_t intercambios = 0;

int partition(std::vector<int32_t>& A, int low, int high) {
    //Elegir pivote aleatorio y moverlo al final
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(A[randomIndex], A[high]);

    int32_t pivot = A[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparaciones++;
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]);
            intercambios++;
        }
    }

    std::swap(A[i + 1], A[high]);
    intercambios++;
    return i + 1;
}

void quickSortAux(std::vector<int32_t>& A, int low, int high) {
    while (low < high) {
        int pi = partition(A, low, high);

        if (pi - low < high - pi) {
            quickSortAux(A, low, pi - 1);
            low = pi + 1;
        } else {
            quickSortAux(A, pi + 1, high);
            high = pi - 1;
        }
    }
}

void quickSort(std::vector<int32_t>& A) {
    srand(time(nullptr));
    comparaciones = 0;
    intercambios = 0;

    auto start = std::chrono::high_resolution_clock::now();
    quickSortAux(A, 0, A.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duracion = end - start;

}
