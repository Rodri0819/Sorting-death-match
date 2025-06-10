#include "radix_sort.h"
#include <vector>
#include <algorithm>
#include <cmath>

void radixSort(std::vector<int32_t>& A) {
    const int base = 256;    // Base 256 (8 bits)
    const int passes = 4;    // 32 bits / 8 bits = 4 pasadas

    std::vector<int32_t> buffer(A.size());  // Arreglo auxiliar

    // Se realizan 4 pasadas, una por cada byte (desde el menos significativo al más significativo)
    for (int pass = 0; pass < passes; ++pass) {
        int count[base] = {};         // Contador de ocurrencias por byte
        int shift = pass * 8;         // Desplazamiento de bits para aislar el byte actual

        // Contar ocurrencias de cada valor de byte en esta pasada
        for (int32_t num : A)
            ++count[(num >> shift) & 0xFF];

        // Sumar los conteos acumulados (para determinar posiciones)
        for (int i = 1; i < base; ++i)
            count[i] += count[i - 1];

        // Colocar los elementos en el buffer en orden estable
        for (int i = A.size() - 1; i >= 0; --i) {
            int byte = (A[i] >> shift) & 0xFF;
            buffer[--count[byte]] = A[i];
        }

        // Copiar resultados al arreglo original
        A.swap(buffer);
    }
}
