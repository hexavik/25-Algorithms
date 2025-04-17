/**
 * @file linear_search.cpp
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @brief 
 * The linear search iterates sequentially over an array or list starting
 * at one end and continuing until the target is located or the end. 
 * The return value will be the index of the value to be discovered if 
 * found otherwise -1.
 * 
 * 1. Read the search element (target) element in an array
 * 2. Set an integer i = 0 and repeat step 3 and 4 till i reaches 
 *	  to the end of the array
 * 3. Match the key with arr[i]
 * 4. If the key matches, return the index, else increment i by 1
 */

#include <array>
#include <iostream>

/**
 * @brief Search an element in the given array and return its index. 
 * If the element absent then return -1.
 * 
 * @tparam N Get the size of an array based on the input std::array
 * @param arr Input sorted/unsorted array
 * @param element Value that needs to be searched
 * @return int Index of the element if found, else -1
 */
template <std::size_t N>
int linear_search(std::array<int, N>& arr, int element) {
    for (int i = 0; i < arr.size(); ++i) {
        if (element == arr[i])
            return i;
    }

    return -1;
}

int main() {
    // Create an array
    std::array<int, 8> arr = {10, 40, 30, 50, 80, 90, 20, 70};

    auto result = linear_search(arr, 20);

    (result == -1) ? std::cout << "Element not found" << std::endl
                   : std::cout << "Element found at " << result << std::endl;

    return 0;
}
