#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll n, m = 0, k;
ll arr[N], pref1[N], pref2[N];
void fn()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    pref1[i] = 0;
    pref2[i] = 0;
  }
  for (int i = 1; i <= m; i++)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      pref1[1]++;
      pref1[x + 1]--;
      pref2[1]--;
      pref2[x + 1]++;
    }
    else
    {
      pref1[x]--;
      pref2[x]++;
    }
  }
  vector<ll> v1, v2;
  for (int i = 1; i <= n; i++)
  {
    pref1[i] += pref1[i - 1];
    pref2[i] += pref2[i - 1];
    v1.push_back(arr[i] + pref1[i]);
    v2.push_back(arr[i] + pref2[i]);
  }
  if (is_sorted(v1.begin(), v1.end()) || is_sorted(v2.begin(), v2.end()) || is_sorted(v1.rbegin(), v1.rend()) || is_sorted(v2.rbegin(), v2.rend()))
  {
    cout << "YES\n";
  }
  else
    cout << "NO\n";
}

int main()
{
  freopen("I.in", "r", stdin);
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}