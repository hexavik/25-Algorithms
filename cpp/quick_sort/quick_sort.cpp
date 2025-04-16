/**
 * @file quick_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @brief 
 * Quick Sort is a divide-and-conquer sorting algorithm that works by 
 * selecting a pivot element, partitioning the array around it such 
 * that all elements less than the pivot come before it and all 
 * greater come after, then recursively applying the same strategy to 
 * the subarrays.
 *
 * This implementation chooses the last element as the pivot.
 *
 * Average Time Complexity: O(n log n)
 * Worst-case Time Complexity: O(n^2) (when the pivot is always the smallest/largest)
 * Space Complexity: O(log n) (due to recursive call stack, in-place sorting)
 * 
 */

#include <iostream>
#include <utility>

void display_array(const int * arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * @brief Splits an array into two sub-array based on the elements
 * swapped based on the comparison against pivot element. All elements
 * smaller than the pivot are swapped to left and larger ones swapped
 * to the right.
 * 
 * @param arr Input unsorted array
 * @param low Lowest index of the sub-array
 * @param high Highest index of the sub-array
 * @return int Split index
 */
int split(int * arr, int low, int high) {
    //
    // Select the pivot
    //
    int pivot = arr[high];

    //
    // Index of a smaller element and points to the right position of
    // pivot found til now.
    //
    int i = low - 1;

    //
    // Traverses through an array from the lowest index till the index
    // before pivot. If the current element is greater than the pivot
    // go to the next position else increment the smaller element
    // index and swap the current element with it.
    //
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[j], arr[++i]);
        }
    }

    //
    // Update the pivot element to the next position of the smaller
    // number index.
    //
    std::swap(arr[++i], arr[high]);

    return i;
}

/**
 * @brief Sorts an array using quick sort algorithm in recursive 
 * approach.
 * 
 * @param arr Input unsorted array
 * @param low Lowest index of the array (initially zero)
 * @param high Highest index of the array (total size of the array - 1)
 */
void quick_sort(int * arr, int low, int high) {
    if (low < high) {
        auto split_index = split(arr, low, high);
        
        quick_sort(arr, low, split_index - 1);
        quick_sort(arr, split_index + 1, high);
    }
}

int main() {
    // Input array
    int arr[] = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    // Calculate the array length
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, arr_len - 1);
    display_array(arr, arr_len);

    return 0;
}
