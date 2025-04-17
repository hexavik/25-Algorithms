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
 * @brief Sorts an input array using selection sort algorithm.
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Unsorted input array
 */
template <std::size_t N>
void selection_sort(std::array<int, N>& arr) {
    if (arr.size() < 1) {
        std::cerr << "Error: Invalid Array Size\n";
        return;
    }

    for (int i = 0; i < arr.size() - 1; ++i) {
        size_t min_index = i;
        // Find the index of the minimum element
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Input array
    std::array<int, 9> arr = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    selection_sort(arr);
    display_array(arr);

    return 0;
}
