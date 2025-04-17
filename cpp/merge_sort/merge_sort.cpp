/**
 * @file merge_sort.cpp
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @brief 
 * Merge Sort is a divide-and-conquer sorting algorithm. It 
 * recursively splits the array into halves, sorts them, and then 
 * merges the sorted halves. This implementation uses index-based 
 * recursion and a temporary vector for merging.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * 
 */

#include <array>
#include <iostream>
#include <vector>

template <std::size_t N>
void display_array(const std::array<int, N> arr) {
    for (auto val : arr) {
        std::cout << val << ", ";
    }
    std::cout << "\n";
}

/**
 * @brief Merge two sub-arrays into one array and modify the original
 * array content by the sorted array. This will not affect the size
 * of the array and only the elements within given indices will be 
 * affected (between index `l` to index `r`).
 * 
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Unsorted input array
 * @param l Lowest index value at left
 * @param m Median index value
 * @param r Largest index value at right
 */
template <std::size_t N>
void merge(std::array<int, N>& arr, int l, int m, int r) {
    //
    // Create a vector for a temporary storage. This is cleaner and 
    // safer than the dynamic allocation for the merging two array
    // slices.
    //
    std::vector<int> vec_arr;
    
    //
    // Compare the elements against each other from both sub-arrays
    // and then push the incrementally into the vector to create a
    // sorted array which is considered as a merged array.
    //
    int i = l;
    int j = m;
    while (i < m && j < r) {
        if (arr[i] < arr[j]) {
            vec_arr.emplace_back(arr[i++]);
        } else {
            vec_arr.emplace_back(arr[j++]);
        }
    }

    //
    // Push the remaining elements of the sub-array if all elements
    // from the other sub-array are already pushed to the vector.
    // 
    while (i < m) {
        vec_arr.emplace_back(arr[i++]);
    }
    while (j < r) {
        vec_arr.emplace_back(arr[j++]);
    }

    //
    // Move all elements from vector to the original array in the same
    // order to get the sorted merged sub-array.
    //
    int index = 0;
    for (int value: vec_arr) {
        arr[l + index] = value;
        index++;
    }
}

template <std::size_t N>
void merge_sort(std::array<int, N>& arr, int l, int r) {
    if (r - l < 2) {
        return;
    }

    //
    // Split arrays to two sub-arrays recursively till the sub-array 
    // length reaches to one.
    //
    int mid = l + ((r - l) / 2);
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);

    //
    // Merge these two sub-arrays to the one so that recursion will
    // merge the sub-arrays into one array.
    //
    merge(arr, l, mid, r);
}

int main() {
    // Input array
    std::array<int, 9> arr = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    merge_sort(arr, 0, arr.size());
    display_array(arr);

    return 0;
}
