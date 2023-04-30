// The linear search iterates sequentially over an array or list starting 
// at one end and continuing until the target is located or the end. 
// The return value will be the index of the value to be discovered if 
// found otherwise -1.

fn main() {
    // Create an array
    let arr = [10, 20, 30, 40, 50, 60, 70, 80, 90];

    match linear_search(&arr, 55) {
        Some(result) => println!("Element found at index {}", result),
        None => println!("Element not found in the given array"),
    };
}

// Search an element in the given array and return its index.
// If the element absent then return -1.
fn linear_search(arr: &[i32], element: i32) -> Option<i32> {
    for (i, item) in arr.iter().enumerate() {
        if *item == element {
            return Some(i as i32);
        };
    }

    None
}
