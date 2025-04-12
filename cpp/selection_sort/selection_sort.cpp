/**
 * @file selection_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @brief 
 * Selection sort sorts an array by setting up one current index and 
 * one minimum index. Minimum index updated by finding the minimum 
 * element from an array and then swaps it with the element at current
 * index. Then current index moved to the next location and minimum
 * index gets updated by finding the minimum element from the unsorted 
 * part. This process continues till the last element pf the array.
 * 
 */

#include <iostream>
#include <utility>

void display_array(const int * arr, size_t arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * @brief Sorts an input array using selection sort algorithm.
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * @param arr Unsorted input array
 * @param arr_size Input length of the array (must be greater than 0)
 */
void selection_sort(int * arr, size_t arr_size) {
    if (arr_size < 1) {
        std::cerr << "Error: Invalid Array Size\n";
        return;
    }

    for (int i = 0; i < arr_size - 1; ++i) {
        size_t min_index = i;
        // Find the index of the minimum element
        for (int j = i + 1; j < arr_size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Input array
    int arr[] = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    // Calculate the array length
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, arr_len);
    display_array(arr, arr_len);

    return 0;
}
