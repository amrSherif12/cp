int main() {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};
    // Find first element > 3
    auto it = std::upper_bound(v.begin(), v.end(), 3); 
    
    if (it != v.end()) {
        std::cout << "First element > 3 is: " << *it << "\n"; // Output: 5
    }
}


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
