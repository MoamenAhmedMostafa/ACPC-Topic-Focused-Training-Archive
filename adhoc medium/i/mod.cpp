#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
ll n, m = 0, k;
int MAXN = 1e6 + 2;
ll arr[N];
int primes[N];
int spf[N];
void seive()
{
  for (ll i = 2; i < MAXN; i++)
  {
    if (!primes[i])
    {
      spf[i] = i;
      for (ll j = i * i; j < MAXN; j += i)
      {
        primes[j] = 1;
        if (!spf[j])
          spf[j] = i;
      }
    }
  }
}
ll facts[N];
ll calc(ll z)
{
  ll ret = 0;
  while (z > 1)
  {
    ll sp = spf[z], cnt = 0;
    while (z % sp == 0)
    {
      z /= sp;
      cnt++;
    }
    ret += cnt * sp;
  }
  return ret;
}
void fn()
{
  cin >> n;
  set<int> vv;
  arr[0] = 1;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    int z = arr[i];
    while (z > 1)
    {
      ll sp = spf[z], cnt = 0;
      while (z % sp == 0)
      {
        z /= sp;
        cnt++;
      }
      ans -= facts[sp] * sp;
      facts[sp] = max(facts[sp], cnt);
      ans += facts[sp] * sp;
      vv.insert(sp);
    }
  }
  ll fans = 0;
  for (int i = 1; i <= n; i++)
  {
    int g = __gcd(arr[i], arr[i - 1]);
    ll z = arr[i] / g;
    ll z2 = arr[i - 1] / g;
    // cout << i << " " << z << " " << z2 << " " << ans << '\n';
    ans = ans - calc(z);
    if (i == 1)
      fans += ans;
    fans += calc(z2);
  }
  for (auto z : vv)
  {
    facts[z] = 0;
  }
  cout << fans << '\n';
}

int main()
{
  freopen("bor3y.in", "r", stdin);
  seive();
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}