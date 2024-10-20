#include <bits/stdc++.h>
#define ll long long
#define Mo17 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define YES(x) cout << ((x) ? "YES\n" : "NO\n")
#define NO(x) cout << ((x) ? "NO\n" : "YES\n")
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) signed(x.size())
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n + 2);
  vector<ll> deg(n + 5);
  for (int i(1); i <= n;++i)
    cin >> a[i];
  int ans(0);
  for (int i(1); i <= n;++i){
    if (a[i]!=i)
      deg[a[i]]++;
  }
  queue<int> q;
  for (int i(1); i <= n;++i){
    if (deg[i]==0)
      q.push(i);
  }
  while (sz(q)){
    ans++;
    if (--deg[a[q.front()]]==0)
      q.push(a[q.front()]);
    q.pop();
  }
  if (ans!=n)
    cout << "Definitely Lying\n";
  else
    cout << "Not Definitely Lying\n";
}

signed main()
{
  Mo17;
  int tt = 1;
  cin >> tt;
  while (tt--){
    solve();
  }
  return 0;
}
