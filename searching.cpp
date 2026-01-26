int main() {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};
    // Find first element > 3
    auto it = std::upper_bound(v.begin(), v.end(), 3); 
    
    if (it != v.end()) {
        std::cout << "First element > 3 is: " << *it << "\n"; // Output: 5
    }
}
