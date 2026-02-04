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
