// ﷽
// Contest: number theory (medium)
//
// Judge: Codeforces
// URL: https://codeforces.com/group/o09Gu2FpOx/contest/542177/problem/W
// Memory Limit: 256
// Time Limit: 2000
// Start: Mon 1 Oct 2024 05:39:03 PM EEST
#include <bits/stdc++.h>

#ifdef ALGOAT
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

#define int long long
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1},
          dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
using namespace std;

// 1. For any number x, to find how many times it divides n!, we need:
//    - Prime factorization of all numbers from 1 to n
//    - Store the count of each prime factor
//    - This gives us how many times each prime appears in n!

// 2. We use Sieve of Eratosthenes with modification:
//    - spf[i] stores smallest prime factor of i
//    - This helps in efficient prime factorization in O (log n) 
int MAXN = 1e6;
vector<int> spf(MAXN + 1, 1);
void sieve() {
  spf[0] = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (spf[i] == 1) {  // i is prime
      for (int j = i; j <= MAXN; j += i) {
        if (spf[j] == 1) spf[j] = i;
      }
    }
  }
}

// 3. Function to get prime factorization using spf
//    - Uses division method with precomputed smallest prime factors
//    - Stores result in map: prime -> count
void getFactorization(int x, map<int, int> &primes) {
  while (x != 1) {
    primes[spf[x]]++;
    x = x / spf[x];
  }
}

void solve() {
  // primesV stores prime factorization of n!
  map<int, int> primesV;
  int n, q;
  cin >> n >> q;

  // Calculate prime factorization of n!
  // by factorizing each number from 1 to n
  for (int i = 1; i <= n; i++) {
    getFactorization(i, primesV);
  }

  // Process queries
  int op, x;
  while (q--) {
    cin >> op >> x;

    if (op == 1) {
      // Type 1: Multiply v by x
      // Add prime factors of x to primesV
      getFactorization(x, primesV);
    }
    if (op == 2) {
      // Type 2: Find largest r where x^r divides (n! * v)
      map<int, int> primes;
      getFactorization(x, primes);
      int ans = INT_MAX;

      // For each prime p in x's factorization:
      // 1. If prime occurs more times in x than in n!*v, result is 0
      // 2. Otherwise, we can divide p's count in n!*v by p's count in x
      // 3. The minimum such division across all primes is our answer
      for (auto &[prime, count] : primes) {
        if (count > primesV[prime]) {
          ans = 0;
          break;
        }
        count = primesV[prime] / count;
        ans = min(ans, count);
      }
      cout << ans << "\n";
    }
  }
}
int32_t main() {
  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio();
  sieve();
  int n = 1;
  /*cin>>n;*/
  while (n--) solve();
  return 0;
}
