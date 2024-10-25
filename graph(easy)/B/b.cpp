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
  int n, m;
  cin >> n >> m;
  char a[n][m];
  ll near(1e9), far(0), cnt(0);
  for (int i(0); i < n; ++i){
    for (int j(0); j < m; ++j){
      cin >> a[i][j];
      if (a[i][j] == 'o'){
        cnt++;
        near = min(near, i + j * 1LL);
        far = max(far, i + j * 1LL);
      }
    }
  }
  if (cnt >= 2)
    cout << min((n + m - 2) * 2LL, near * 2 + ((n + m - 2) - far) * 2 + 1) << '\n';
  else
    cout << (n + m - 2) * 2LL << '\n';
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
