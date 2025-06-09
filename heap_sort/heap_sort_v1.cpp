#ifndef HEAP_SORT_V1_H
#define HEAP_SORT_V1_H

#include <vector>
#include <cstdint>

class priorityQueue {
private:
    std::vector<int32_t> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapDown(int i) {
        int minIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap[l] < heap[minIndex]) minIndex = l;
        if (r < heap.size() && heap[r] < heap[minIndex]) minIndex = r;

        if (i != minIndex) {
            std::swap(heap[i], heap[minIndex]);
            heapDown(minIndex);
        }
    }

public:
    void insert(int32_t value) {
        heap.push_back(value);
        heapUp(heap.size() - 1);
    }

    int32_t extractPriority() {
        int32_t top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapDown(0);
        return top;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

// Adaptación para tu sistema de benchmarking
void heapSort(std::vector<int32_t>& arr) {
    priorityQueue pq;
    for (int32_t val : arr)
        pq.insert(val);
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = pq.extractPriority();
}

#endif
