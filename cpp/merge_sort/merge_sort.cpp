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

#include <iostream>
#include <vector>

void display_array(const int * arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * @brief Merge two sub-arrays into one array and modify the original
 * array content by the sorted array. This will not affect the size
 * of the array and only the elements within given indices will be 
 * affected (between index `l` to index `r`).
 * 
 * @param arr Input array pointer
 * @param l Leftmost index (lowest index value)
 * @param m Median index of the two sub-arrays
 * @param r Rightmost index (highest index value)
 */
void merge(int * arr, int l, int m, int r) {
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

void merge_sort(int * arr, int l, int r) {
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
    int arr[] = {5, 9, 6, 4, 7, 2, 3, 1, 8};

    // Calculate the array length
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, arr_len);
    display_array(arr, arr_len);

    return 0;
}
