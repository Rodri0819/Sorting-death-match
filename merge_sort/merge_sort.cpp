#include <vector>
#include <cstdint>
#include "merge_sort.h"


void merge(std::vector<int32_t>& A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int32_t> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }
}

void mergeSortAux(std::vector<int32_t>& A, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortAux(A, left, mid);
    mergeSortAux(A, mid + 1, right);
    merge(A, left, mid, right);
}

void mergeSort(std::vector<int32_t>& A) {
    if (!A.empty())
        mergeSortAux(A, 0, A.size() - 1);
}
