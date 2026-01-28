// when doing an exponential its better use bit shiffting for percision
cout << pow(2, res); // bad
cout << (1LL << res); // good




 /*
 oprimized power function with mod
 Computes (base^exp) % mod
 * Time Complexity: O(log exp)
 * Space Complexity: O(1)
 */
long long binpow(long long base, long long exp, long long mod = 1e9 + 7) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}


// without mod
long long binpow_raw(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}



long long ceil(long  long a, long long b) {
 return (a + b - 1) / b;
}
 
