/**
 * @file binary_search.cpp
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @brief 
 * The binary search identifies a target value's location within a sorted 
 * array. The center element of the array is what the binary search 
 * compares the target value to. If not, the half in which the target 
 * cannot lie is removed, and the search is then continued on the other 
 * half, using the middle element once more to compare to the target 
 * value. This process is repeated until the target value is discovered. 
 * The target is not in the array if the search yields a half that is 
 * empty.
 *
 * 1. Take the sorted array
 * 2. Assign the min and max values accordin to the array size
 * 3. Calculate the mid of the min and max
 * 4. If the value at arr[mid] is lower than the searching element then move to the next half
 * 5. Update the min = mid and then recalculate the mid and follow the same procedure
 * 6. If the value at aee[mid] is greater than the searching element then move to the first half
 * 7. Update the max = mid and then recalculate the mid and follow the same procedure
 */

#include <iostream>

int binary_search(int arr[], int size, int element) {
	// Assign min and max values
	int min = 0;
	int max = size - 1;
	int mid;

	while (min <= max) {
		// Update the mid value
		mid = min + (max - min) / 2;

		// Compare the element with the value at arr[mid]
		if (arr[mid] == element) {
			return mid;
		}
		// Update min and max
		arr[mid] > element ? max = mid - 1 : min = mid + 1;
	}

	return -1;
}

int main() {
	// Create a sorted array
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

	// Calculate the array size
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	auto result = binary_search(arr, arr_size, 34);
	result != -1 ? 
		std::cout << "Element found at index " << result << std::endl :
		std::cout << "Element not found in the given array" << std::endl;

	return 0;
}
