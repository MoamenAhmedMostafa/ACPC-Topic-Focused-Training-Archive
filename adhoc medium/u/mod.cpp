#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll n, m = 0, k;
pair<ll, ll> a[N];
bool good(ll mid)
{
  ll r = 1, sm = 0;
  set<pair<ll, ll>> st;
  while (r <= n)
  {
    sm += a[r].first;
    st.insert({a[r].second, r});
    r++;
    ll x = (sm + mid - 1) / mid;
    while (st.size() && (*st.begin()).first < x)
    {
      sm -= a[st.begin()->second].first;
      st.erase(st.begin());
    }
    if (st.size() >= mid)
      return 1;
  }
  return 0;
}
void fn()
{
  cin >> n;
  ll sm = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + 1 + n);
  int l = 0, r = n + 1, mid;
  while (l + 1 < r)
  {
    mid = (l + r) / 2;
    if (good(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << '\n';
}

int main()
{
  freopen("monsters.in", "r", stdin);
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}