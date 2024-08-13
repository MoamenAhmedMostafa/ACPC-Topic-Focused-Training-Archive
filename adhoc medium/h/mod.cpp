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
  ll freq[26] = {};
  ll sm = 0, odd = 0;
  for (int i = 0; i < 26; i++)
  {
    cin >> freq[i];
    if (freq[i] % 2)
    {
      odd++;
      freq[i]--;
    }
    sm += freq[i];
  }
  ll ans = 0;
  for (int i = 1; i < 100 && odd; i++)
  {
    int x = i;
    if (x % 2)
      odd--, x--;
    if (sm >= x)
    {
      sm -= x;
    }
    else
    {
      break;
    }
    ans++;
  }
  ll l = 0, r = 3e9, mid, kk = 0;
  if (ans % 2)
    kk = 1;
  while (l + 1 < r)
  {
    mid = (l + r) / 2;
    ll tk = (mid - kk) % 4;
    if (tk <= 2 && tk >= 1)
      tk = 1;
    else
      tk = 0;
    ll nr = mid + ans;
    if (nr * (nr + 1) / 2 - ans * (ans + 1) / 2 + tk <= sm)
      l = mid;
    else
      r = mid;
  }
  // ll tk = (r + 3) / 4 * 2;
  // ll nr = r + ans;
  // cout << tk << " " << nr << " " << l << " " << ans << " " << odd << " " << sm << '\n';
  cout << ans + l << '\n';
}

int main()
{
  freopen("cube.in", "r", stdin);
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}