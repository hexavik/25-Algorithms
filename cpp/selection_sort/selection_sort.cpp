#include <iostream>
#include <utility>

void display_array(const int * arr, size_t arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void selection_sort(int * arr, size_t arr_size) {
    for (int i = 0; i < arr_size - 1; ++i) {
        size_t min_index = i;
        // Find the min
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
