#include <bits/stdc++.h>
#define ll long long
#define Mo17 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define YES(x) cout << ((x) ? "YES\n" : "NO\n")
#define NO(x) cout << ((x) ? "NO\n" : "YES\n")
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) signed(x.size())
using namespace std;

const int N = 1e5 + 4;
vector<ll> a(N);
vector<vector<ll>> adj(N);
map<ll, bool> vis;

ll dfs(ll v){
  vis[v] = 1;
  ll sum(a[v]);
  for (auto &u:adj[v])
    if (!vis[u])
      sum += dfs(u);
  return sum;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i(1); i <= n;++i)
    cin >> a[i];
  ll u, v,mx(-1e18);
  for (int i(0); i < m;++i){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i(1); i <= n;++i)
    if (!vis[i])
      mx = max(mx, dfs(i));
  cout << mx ;
}

signed main()
{
  Mo17;
  int tt = 1;
  //cin >> tt;
  while (tt--){
    solve();
  }
  return 0;
}
