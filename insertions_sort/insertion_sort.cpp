#include "insertion_sort.h"
#include <cstdint>

void insertionSort(std::vector<int32_t>& A) {
    for (size_t i = 1; i < A.size(); ++i) {
        int32_t key = A[i];
        size_t j = i;

        while (j > 0 && A[j - 1] > key) {
            A[j] = A[j - 1];
            --j;
        }
        A[j] = key;
    }
}
