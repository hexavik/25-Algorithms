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

#include <array>
#include <iostream>
#include <utility>

template <std::size_t N>
void display_array(const std::array<int, N> arr) {
    for (auto val : arr) {
        std::cout << val << ", ";
    }
    std::cout << "\n";
}

/**
 * @brief Splits an array into two sub-array based on the elements
 * swapped based on the comparison against pivot element. All elements
 * smaller than the pivot are swapped to left and larger ones swapped
 * to the right.
 * 
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Unsorted input array
 * @param low Lowest index of the sub-array
 * @param high Highest index of the sub-array
 * @return int Split index to create two sub-arrays
 */
template <std::size_t N>
int split(std::array<int, N>& arr, int low, int high) {
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
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Unsorted input array
 * @param low Lowest index of the array or the sub-array
 * @param high Highest index of the array or the sub-array
 */
template <std::size_t N>
void quick_sort(std::array<int, N>& arr, int low, int high) {
    if (low < high) {
        auto split_index = split(arr, low, high);
        
        quick_sort(arr, low, split_index - 1);
        quick_sort(arr, split_index + 1, high);
    }
}

int main() {
    // Input array
    std::array<int, 9> arr = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    quick_sort(arr, 0, arr.size() - 1);
    display_array(arr);

    return 0;
}
