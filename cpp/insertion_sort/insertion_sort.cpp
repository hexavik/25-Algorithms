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

#include <iostream>
#include <utility>

void display_array(int * arr, size_t arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * @brief Implements insertion sort to sort the input array
 * 
 * @param arr Unsorted input array
 * @param arr_size Input length of the array (must be greater than 0)
 */
void insertion_sort(int * arr, size_t arr_size) {
    if (arr_size < 1) {
        std::cerr << "Error: Invalid Array Size\n";
        return;
    }

    int temp = 0;
    for (int i = 1; i < arr_size; ++i) {
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
    int arr[] = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    // Calculate the array length
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, arr_len);
    display_array(arr, arr_len);

    return 0;
}
