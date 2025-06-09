
#include "radix_sort.h"
#include <vector>
#include <algorithm>
#include <cmath>

void radixSort(std::vector<int32_t>& arr) {
    const int base = 256;  // 8-bit base
    const int passes = 4;  // 32 bits / 8 = 4

    std::vector<int32_t> buffer(arr.size());
    for (int pass = 0; pass < passes; ++pass) {
        int count[base] = {};
        int shift = pass * 8;

        for (int32_t num : arr)
            ++count[(num >> shift) & 0xFF];

        for (int i = 1; i < base; ++i)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; --i) {
            int byte = (arr[i] >> shift) & 0xFF;
            buffer[--count[byte]] = arr[i];
        }

        arr.swap(buffer);
    }
}
