#include "quick_sort.h"
#include <vector>
#include <cstdint>
#include <iostream>

int partition(std::vector<int32_t>& A, int low, int high) {
    int32_t pivot = A[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSortAux(std::vector<int32_t>& A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSortAux(A, low, pi - 1);
        quickSortAux(A, pi + 1, high);
    }
}

void quickSort(std::vector<int32_t>& A) {
    std::cout << "Entrando a QuickSort con " << A.size() << " elementos\n";
    quickSortAux(A, 0, A.size() - 1);
}


