// O(log n) search algorithm for sorted array
// lower_bound returns an iterator to the first element greater than or equal to the specified value (>=).
// upper_bound returns an iterator to the first element strictly greater than the specified value (>).

int main() {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};
    // Find first element > 3
    auto it = std::upper_bound(v.begin(), v.end(), 3); 
    
    if (it != v.end()) {
        std::cout << "First element > 3 is: " << *it << "\n"; // Output: 5
    }
}


// linear search

int main() {
    std::vector<int> prefix = {10, 20, 30, 40, 50};
    auto it = std::find(prefix.begin(), prefix.end(), 30);
    
    if (it != prefix.end()) {
        // Calculate the index (distance from begin)
        auto idx = std::distance(prefix.begin(), it);
        std::cout << "Index: " << idx << std::endl; // Output: 2
    }
    return 0;
}
