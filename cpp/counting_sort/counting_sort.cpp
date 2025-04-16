/**
 * @file counting_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @brief 
 * This program demonstrates the Counting Sort algorithm, which is efficient
 * for sorting arrays of non-negative integers with a known small range.
 *
 * Key Features:
 * - Uses `std::array` for fixed input and `std::vector` for dynamic internals
 * - Identifies the largest element to size the count array
 * - Constructs a stable sorted output using a cumulative count array
 * - Includes debug output to trace index and sorting progress
 *
 * Constraints:
 * - Assumes all input values are non-negative integers
 * - Best suited for datasets with a relatively small maximum value
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

template <std::size_t N>
void counting_sort(std::array<int, N>& arr) {
    std::vector<int> sorted_arr(arr.size());

    //
    // Find the largest element in an array
    //
    int largest = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    //
    // Create a vector to store the occurrence of all the elements in
    // an array, and initialize it with zero
    //
    std::vector<int> count_array(largest + 1, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
        count_array[arr[i]]++;
    }

    //
    // Update the count array by summing it up with previous element 
    // value
    //
    for (int i = 1; i <= largest; ++i) {
        count_array[i] += count_array[i - 1];
    }

    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        auto index = count_array[arr[i]]--;
        sorted_arr[index - 1] = arr[i];
    }

    for (size_t i = 0 ; i < arr.size(); ++i) {
        std::cout << sorted_arr[i] << ", ";
    }
    std::cout << "\n";
}

int main() {
    // Input array
    std::array<int, 9> arr {5, 2, 9, 1, 5, 6, 7, 3, 2};

    counting_sort(arr);

    return 0;
}
