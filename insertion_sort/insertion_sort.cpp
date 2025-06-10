#include "insertion_sort.h"
#include <vector>
#include <cstdint>

void insertionSort(std::vector<int32_t>& A) {
    //Recorremos el arreglo desde la segunda posición hasta el final
    for (size_t i = 1; i < A.size(); ++i) {
        //Guardamos el valor actual que queremos insertar en la parte ordenada
        int32_t key = A[i];
        size_t j = i;
        //Desplazamos hacia la derecha los elementos mayores a la clave
        while (j > 0 && A[j - 1] > key) {
            A[j] = A[j - 1];
            --j;
        }
        //Insertamos la clave en la posición correcta
        A[j] = key;
    }
}
