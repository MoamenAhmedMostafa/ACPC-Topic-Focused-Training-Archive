#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;

void fastio()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll n, m = 0, k;
ll arr[N][N];
void fn()
{
  cin >> n >> m >> k;
  multiset<ll> st;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
      st.insert(arr[i][j]);
    }
  }
  if (k == 1)
  {
    cout << "0\n";
    return;
  }
  ll ans = 0;
  for (int i = 1; i <= m; i++)
  {
    set<ll> st2;
    for (int j = 1; j <= n; j++)
    {
      st2.insert(arr[j][i]);
      st.erase(st.find(arr[j][i]));
    }
    ans = max({ans, abs((*st2.rbegin()) - (*st.begin())), abs((*st.rbegin()) - (*st2.begin()))});
    for (int j = 1; j <= n; j++)
    {
      st.insert(arr[j][i]);
    }
  }
  cout << ans << '\n';
}

int main()
{
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}