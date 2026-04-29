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

using namespace std;

/**
 * Standard Segment Tree
 * Operation: Sum (can be modified to Min/Max)
 */
class SegmentTree {
    int n;
    vector<long long> tree;

public:
    SegmentTree(int size) : n(size) {
        tree.assign(4 * n, 0);
    }

    // Build the tree from an existing array
    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    // Point update: change value at index 'pos' to 'new_val'
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, new_val);
            else
                update(2 * v + 1, tm + 1, tr, pos, new_val);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    // Range query: find sum in range [l, r]
    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm))
             + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};
