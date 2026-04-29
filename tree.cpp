struct BIT {
    int n; vector<long long> b1, b2;
    BIT(int n) : n(n), b1(n + 1, 0), b2(n + 1, 0) {}
    
    void upd(vector<long long>& b, int i, long long v) {
        for (; i <= n; i += i & -i) b[i] += v;
    }
    
    void range_upd(int l, int r, long long v) {
        upd(b1, l, v); upd(b1, r + 1, -v);
        upd(b2, l, v * (l - 1)); upd(b2, r + 1, -v * r);
    }
    
    long long qry(vector<long long>& b, int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += b[i];
        return s;
    }
    
    long long query(int i) { return qry(b1, i) * i - qry(b2, i); }
    long long range_qry(int l, int r) { return query(r) - query(l - 1); }

    vector<long long> get_original_array() {
    // 1. Copy b1 (the Fenwick tree of the difference array)
    vector<long long> res = b1; 
    
    // 2. Undo the BIT structure in O(N)
    // We iterate backwards to subtract children from parents
    for (int i = n; i > 0; --i) {
        int parent = i + (i & -i);
        if (parent <= n) {
            res[parent] -= res[i];
        }
    }

    // Now 'res' is the literal Difference Array D.
    // 3. Take prefix sums to get the actual values A[i]
    // A[i] = D[1] + D[2] + ... + D[i]
    for (int i = 1; i <= n; ++i) {
        res[i] += res[i-1];
    }
    
    // res[1...n] now contains your actual array elements.
    return res;
}
};


// 1. Initialize for 5 elements (indices 1 to 5)
BIT ft(5); 

// 2. RANGE UPDATE: Add 10 to every element from index 2 to 4
// Array becomes: [0, 10, 10, 10, 0]
ft.range_upd(2, 4, 10);

// 3. POINT QUERY (Special case of Range Query)
// To get the value at index 3, query range [3, 3]
long long val3 = ft.range_qry(3, 3); // Returns 10

// 4. RANGE QUERY: Get sum of elements from index 1 to 3
// Sum is: 0 + 10 + 10 = 20
long long sum13 = ft.range_qry(1, 3); // Returns 20

// 5. ANOTHER UPDATE: Add 5 to elements from index 4 to 5
// Array was: [0, 10, 10, 10, 0]
// Now:       [0, 10, 10, 15, 5]
ft.range_upd(4, 5, 5);

// 6. FINAL RANGE QUERY: Sum of index 3 to 5
// Sum is: 10 + 15 + 5 = 30
long long sum35 = ft.range_qry(3, 5); // Returns 30





#include <iostream>
#include <vector>

template <typename T>
class SegmentTree {
private:
    int n;
    std::vector<T> tree;
    std::vector<T> lazy;

    // Helper to push lazy values down to children
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node]; // Update current node
            if (start != end) {
                lazy[2 * node] += lazy[node];             // Mark left child
                lazy[2 * node + 1] += lazy[node];         // Mark right child
            }
            lazy[node] = 0;                               // Reset current lazy
        }
    }

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateRange(int node, int start, int end, int l, int r, T val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    T queryRange(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > end || start > r || end < l) return 0;

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) + 
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }

public:
    SegmentTree(const std::vector<T>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, T val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    T query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

int main() {
    std::vector<long long> data = {1, 3, 5, 7, 9, 11};
    SegmentTree<long long> st(data);

    // Query sum from index 1 to 3: (3 + 5 + 7) = 15
    std::cout << "Initial Query (1-3): " << st.query(1, 3) << std::endl;

    // Add 10 to indices 1 through 5
    st.update(1, 5, 10);

    // Query sum from index 1 to 3: (13 + 15 + 17) = 45
    std::cout << "After Update Query (1-3): " << st.query(1, 3) << std::endl;

    return 0;
}
