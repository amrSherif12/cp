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

ll comb(ll n, ll r) {
    return fact(n) / (fact(r) * fact(n - r));
}

// seive of aresth

const int MAXN = 10000001; // 10^7
int spf[MAXN];             // Smallest Prime Factor
vector<int> primes;        // List of primes found

void linearSieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {     // i is prime
            spf[i] = i;
            primes.push_back(i);
        }
        // Multiply i by every prime found so far
        for (int p : primes) {
            // Stop if the prime is larger than i's SPF or exceeds n
            if (p > spf[i] || (long long)i * p > n) break;
            
            spf[i * p] = p;    // Mark the multiple
        }
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
