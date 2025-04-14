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
ll can[N];
void fn()
{
  cin >> n >> m;
  string s, t, b;
  cin >> s >> t >> b;
  for (int i = n - 1, j = m - 1; i >= 0; i--)
  {
    if (j >= 0 && s[i] == t[j])
      j--;
    can[i] = m - j - 1;
  }
  string ans;
  for (int i = 0, j = 0; i < n; i++)
  {
    if (b[i] == '0')
    {
      ans.push_back('0');
      if (j < m && s[i] == t[j])
        j++;
    }
    else
    {
      if (j >= m || (i < n - 1 && can[i + 1] + j >= m))
      {
        ans.push_back('1');
      }
      else
      {
        ans.push_back('0');
        if (j < m && s[i] == t[j])
          j++;
      }
    }
  }
  cout << ans << '\n';
}

int main()
{
  freopen("protecting-memes.in", "r", stdin);
  fastio();
  int t = 1;
  cin >> t;
  while (t--)
    fn();
  return 0;
}