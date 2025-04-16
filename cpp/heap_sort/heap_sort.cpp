/**
 * @file heap_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @brief 
 * Heap Sort is a comparison-based sorting algorithm that transforms 
 * the input array into a max-heap (a complete binary tree where each 
 * parent is greater than its children). Then, it repeatedly swaps the
 * root (maximum element) with the last unsorted element and reduces 
 * the heap size, restoring the heap property after each swap.
 *
 * Time Complexity: O(n log n) for all cases (best, average, and worst)
 * Space Complexity: O(1) (in-place sorting, iterative approach)
 * 
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>

void display_array(const int * arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * @brief Display an array in the form of heap tree
 * 
 * @param arr Input array
 * @param arr_len Input array size
 * NOTE: Use this function for logging and debugging
 */
// void display_heap(const int * arr, size_t arr_len) {
//     int level = 1;
//     for (size_t i = 0; i < arr_len; ++i) {
//         std::cout << arr[i] << ", ";
//         if (i == pow(2, level) - 2) {
//             std::cout << "\n";
//             level++;
//         }
//     }
//     std::cout << std::endl;
// }

/**
 * @brief  Retrieve the left and right child of the current node by 
 * 2n + 1 and 2n + 2 respectively, where `n` is the node's index.
 * The node will be swapped with the child node that is greather than 
 * it. This will give us largest element at the root node (index 0).
 * 
 * @param arr 
 * @param arr_size 
 * @param index 
 */
void heapify_down(int * arr, size_t arr_size, size_t index) {
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < arr_size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < arr_size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index)  {
        std::swap(arr[index], arr[largest]);
        heapify_down(arr, arr_size, largest);
    }
}

/**
 * @brief Since heap is the ordered binary tree it is necessary to 
 * convert the unsorted array into a max heap, to get an element of
 * maximum value to consider it as sorted. This will result us sorting
 * an array from max to min value. This process starts from the first
 * non-leaf node at the bottom which is retrieved by (n / 2) - 1 where
 * `n` is the index of the last element of the 0 index based array.
 * 
 * @param arr Input unsorted array
 * @param arr_size Size of the array
 */
void build_max_heap(int * arr, size_t arr_size) {
 
    for (int i = (arr_size / 2) - 1; i >= 0; --i) {
        heapify_down(arr, arr_size, i);
    }
}

/**
 * @brief Sorts an array using heap sorting.
 * After building max-heap, this function swaps the largest 
 * element which is at index 0 with the leaf node at the bottom (or 
 * last index of the input array).
 * 
 * @param arr Input unsorted array
 * @param arr_size Size of the array
 */
void heap_sort(int * arr, size_t arr_size) {
    build_max_heap(arr, arr_size);

    for (size_t i = arr_size - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        // Reduce heap size by 1 and re-heapify
        heapify_down(arr, i, 0);
    }
}

int main() {
    // Input array
    int arr[] = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    // Calculate the array length
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, arr_len);
    display_array(arr, arr_len);

    return 0;
}
