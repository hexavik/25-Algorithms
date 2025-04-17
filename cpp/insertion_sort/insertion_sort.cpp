/**
 * @file insertion_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @brief
 * Insertion sort sorts an array by traversing through each element 
 * one by one and comparing it with all the elements to its left and 
 * swaps them the current element is lesser than the element towards 
 * left.
 *
 * 1. Pick up the element at index 1 and store it in temp.
 * 2. Compare temp with the all elements on the left side of it.
 * 2A. If the element is lesser than the left element then swap 
 *     the position.
 * 3. Comtinue until the element on the left is lesser than the temp.
 * 4. Pick up the element at next index and follow the same steps
 *    from 2 till 3.
 * 5. Display the sorted array.
 *
 */

#include <array>
#include <iostream>

template <std::size_t N>
void display_array(const std::array<int, N> arr) {
    for (auto val : arr) {
        std::cout << val << ", ";
    }
    std::cout << "\n";
}

/**
 * @brief Sorts an array using insertion sorting algorithm.
 * 
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Unsorted input array
 */
template <std::size_t N>
void insertion_sort(std::array<int, N>& arr) {
    if (arr.size() < 1) {
        std::cerr << "Error: Invalid Array Size\n";
        return;
    }

    int temp = 0;
    for (int i = 1; i < arr.size(); ++i) {
        temp = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            if (temp < arr[j]) {
                std::swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main() {
    // Input array
    std::array<int, 9> arr = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    insertion_sort(arr);
    display_array(arr);

    return 0;
}
