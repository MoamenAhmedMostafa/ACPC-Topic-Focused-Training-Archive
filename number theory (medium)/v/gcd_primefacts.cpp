// ﷽
// Contest: ECPC Qualifications 2024 Day 3 (Mirror)
//
// Judge: Codeforces
// URL: https://codeforces.com/group/Rilx5irOux/contest/537870/problem/J
// Memory Limit: 256
// Time Limit: 1000
// Start: Mon 07 Oct 2024 02:28:46 PM EEST
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
using namespace std;

map<int, int> primefacts(int n) {
  map<int, int> primes;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      primes[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    primes[n]++;
  }
  return primes;
}

int solve() {
  int x, y;
  cin >> x >> y;
  int g = __gcd<int>(x, y);
  y /= g;
  x /= g;
  int xx = sqrtl(x);
  int yy = sqrtl(y);
  if (yy * yy != y || xx * xx != x) {
    return -1;
  }
  map<int, int> m1 = primefacts(xx);
  map<int, int> m2 = primefacts(yy);
  int ans = 0;
  for (auto &[k, v] : m1) {
    ans += v;
  }

  for (auto &[k, v] : m2) {
    ans += v;
  }

  cout << ans << "\n";


// 1. For two numbers to become equal through these operations, their product must remain constant
//    - When we divide one number by p and multiply the other by p, x*y stays the same
//    - This means (final_num * final_num) must equal (x * y)
//    - Therefore, x*y must be a perfect square for the numbers to ever become equal

// 2. After each operation, one prime factor moves from one number to the other
//    - We're essentially redistributing prime factors between x and y
//    - The final state must have identical prime factorizations for both numbers

// 3. To avoid integer overflow (since x,y ≤ 10^18):
//    a) First divide both x and y by their GCD to make them coprime
//    b) Check if both reduced numbers are perfect squares
//       - If not, it's impossible (answer is -1)
//       - If yes, take their square roots (xx and yy)
//    c) The answer is the total number of prime factors in xx and yy
//       - Each prime factor needs exactly one move to reach its final position

// 4. Why this works:
//    - After removing GCD, x and y have no common factors
//    - When both reduced numbers are perfect squares, we can make them equal
//    - Each prime factor in xx needs to move to match yy's factors
//    - The minimum operations is the sum of prime factors in both xx and yy
//      because each factor needs exactly one move
}
int32_t main() {
  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio();

  int n;
  cin >> n;
  while (n--) {
    solve();
  }

  return 0;
}
