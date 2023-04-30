// The binary search identifies a target value's location within a sorted 
// array. The center element of the array is what the binary search 
// compares the target value to. If not, the half in which the target 
// cannot lie is removed, and the search is then continued on the other 
// half, using the middle element once more to compare to the target 
// value. This process is repeated until the target value is discovered. 
// The target is not in the array if the search yields a half that is 
// empty.

fn main() {
    // Create a sorted array
    let arr = [10, 20, 30, 40, 50, 60, 70, 80, 90];

    match binary_search(&arr, 10) {
        Some(result) => println!("Element found at index {}", result),
        None => println!("Element not found in the given array"),
    };
}

fn binary_search(arr: &[i32], element: i32) -> Option<i32> {
    let mut min = 0;
    let mut max = arr.len() - 1;

    while min <= max {
        // Update the mid value
        let mid = min + (max - min) / 2;
        println!("min: {}, max: {}, mid: {}", min, max, mid);

        // Compare the element with the value at arr[mid]
        if arr[mid] == element {
            return Some(mid as i32);
        };

        // Update miin and max
        if arr[mid] > element {
            max = mid - 1
        } else {
            min = mid + 1
        };
    }

     None
}
