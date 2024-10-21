#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 5e5 + 5;
const ll MOD = 1e9 + 7, MAX = 1e18;
const double ep = 1e-6, pi = atan(1.0) * 4;
/*typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
*/
long long inv(long long a, long long b = MOD)
{
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int comp(ld x, ld y)
{
  // return 1 if x<=y
  if (abs(x - y) <= 1e-9)
    return 1;
  if (x < y)
    return 1;
  return 0;
}

ll n, m = 0, k;

void fn()
{
  cin >> n;
  ll ans = n / 7 * 4;
  ll rem = n % 7;
  ans += (rem > 0) + (rem > 1) + (rem > 3) + (rem > 4);
  cout << ans << '\n';
}

int main()
{
  freopen("machines.in", "r", stdin);
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}