struct FenwickTree {
    vector<ll> bit; int n;
    FenwickTree(int n) : n(n) { bit.assign(n + 1, 0); }
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll query(int idx) {
        ll s = 0;
        for (; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }
};