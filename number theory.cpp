// when doing an exponential its better use bit shiffting for percision
cout << pow(2, res); // bad
cout << (1LL << res); // good
// gcd(a, b) = gcd(a % b, b)
// gcd(0, x) = x
// (a + b) % m = ((a % m) + (b % m)) % m


// counting number of divisors in O(N logN)

const int MAXN = 1000001;
int divisors[MAXN];

void precompute() {
    // Sieve-like method to count divisors
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
        }
    }
}

// factorial

ll fact(ll x) {
    ll res = 1;
    while (x > 1) {
        res *= x;
        x--;
    }
    return res;
}

// combination 

ll nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (int i = 0; i < r; i++) res *= (n - i);
    return res;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n / 2) r = n - r;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}


// 1. Memory Optimization: bitset uses 1 bit per number. 
// 10^7 bits = ~1.25 MB (Very light compared to 40MB for int array)
const int MAXN = 10000001;
bitset<MAXN> is_prime;
vector<int> primes;

void sieve() {
    is_prime.set(); // Set all bits to 1
    is_prime[0] = is_prime[1] = 0;
    
    for (int p = 2; p * p < MAXN; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXN; i += p)
                is_prime[i] = 0;
        }
    }
    
    // Store primes in a vector for faster access during the Goldbach search
    for (int p = 2; p < MAXN; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}


//
//
//  The property of any integer y is that it is congruent to the sum of its digits modulo 9.
//  y = d(y)  (mod 9)
//


// digit sum

long long getSum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}



// get prime factors

std::vector<long long> getPrimeFactors(long long n) {
    std::vector<long long> factors;
    if (n <= 1) return factors;

    // Handle 2 separately so we can skip all even numbers in the loop
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check odd numbers starting from 3 up to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still > 1, the remaining n is a prime factor
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}





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

// Modular multiplication to prevent overflow when (a * b) > LLONG_MAX
ll mul_mod(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return res;
}



long long ceil(long  long a, long long b) {
 return (a + b - 1) / b;
}
 
