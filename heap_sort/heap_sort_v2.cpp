#include "heap_sort_v2.h"
#include <vector>
#include <cstdint>

void heapify(std::vector<int32_t>& A, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[largest])
        largest = l;

    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        std::swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(std::vector<int32_t>& A) {
    int n = A.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}
