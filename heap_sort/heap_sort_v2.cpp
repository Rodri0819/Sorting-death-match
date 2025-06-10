#include "heap_sort_v2.h"
#include <vector>
#include <cstdint>

// Función que mantiene la propiedad del heap en el subárbol con raíz en el índice 'i'
void heapify(std::vector<int32_t>& A, int n, int i) {
    int largest = i;           // Inicialmente asumimos que el mayor es la raíz
    int l = 2 * i + 1;         // Índice del hijo izquierdo
    int r = 2 * i + 2;         // Índice del hijo derecho

    // Si el hijo izquierdo existe y es mayor que el actual mayor
    if (l < n && A[l] > A[largest])
        largest = l;

    // Si el hijo derecho existe y es mayor que el actual mayor
    if (r < n && A[r] > A[largest])
        largest = r;

    // Si el mayor no es la raíz, intercambiamos y aplicamos heapify recursivamente
    if (largest != i) {
        std::swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

// Función principal que implementa el algoritmo Heap Sort
void heapSort(std::vector<int32_t>& A) {
    int n = A.size();

    // Construcción del heap (reordenamos el arreglo en un Max-Heap)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(A, n, i);

    // Extraemos los elementos del heap uno por uno
    for (int i = n - 1; i > 0; --i) {
        std::swap(A[0], A[i]);     // Movemos el mayor elemento al final
        heapify(A, i, 0);          // Restauramos la propiedad del heap
    }
}
