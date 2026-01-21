// comparator that sorts a pair like: 
// first item descening and if they match the second item is sorted descending

sort(s.begin(), s.end(), [](const auto &a, const auto &b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });