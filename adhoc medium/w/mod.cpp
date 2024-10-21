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
pair<int, int> ask(vector<int> v1, vector<int> v2)
{
  cout << "?\n";
  cout << v1.size() << "\n";
  for (auto x : v1)
  {
    cout << x << " ";
  }
  cout << '\n'
       << v2.size() << '\n';
  for (auto x : v2)
  {
    cout << x << " ";
  }
  cout << endl;
  int x, y;
  cin >> x >> y;
  return {x, y};
}
array<vector<int>, 3> vdiv(vector<int> v)
{
  vector<int> v1, v2, v3;
  int n = v.size();
  int one = bool(n % 3), two = ((n % 3) > 1);
  for (int i = 0; i < n / 3 + one; i++)
  {
    v1.push_back(v[i]);
  }
  for (int i = n / 3 + one; i < n / 3 * 2 + one + two; i++)
  {
    v2.push_back(v[i]);
  }
  for (int i = n / 3 * 2 + one + two; i < n; i++)
  {
    v3.push_back(v[i]);
  }
  return {v1, v2, v3};
}
array<vector<int>, 3> merge(array<vector<int>, 3> a, array<vector<int>, 3> b)
{
  for (auto x : b[0])
    a[0].push_back(x);
  for (auto x : b[1])
    a[1].push_back(x);
  for (auto x : b[2])
    a[2].push_back(x);
  return a;
}

void fn()
{
  n = 2000;
  int a = 1, b = 1;
  vector<int> v, vvv = {1, 2, 3, 4, 5};
  for (int i = 1; i <= n; i++)
  {
    v.push_back(i);
  }
  array<vector<int>, 3> v123;
  int ans1 = 0, ans2 = 0;
  while (1)
  {
    v123 = vdiv(v);
    auto z = ask(v123[0], v123[1]);
    a = z.first;
    b = z.second;
    a--;
    b--;
    if (a == b)
    {
      v = v123[a];
    }
    else
    {
      if (v123[a].size() == 1)
        ans1 = v123[a][0];
      if (v123[b].size() == 1)
        ans2 = v123[b][0];
      break;
    }
  }
  vector<int> v1 = v123[a], v2 = v123[b];
  while (1)
  {
    if (ans1 && ans2)
      break;
    array<vector<int>, 3> a1 = vdiv(v1);
    array<vector<int>, 3> b1 = vdiv(v2);
    array<vector<int>, 3> c = merge(a1, b1);
    auto z = ask(c[0], c[1]);
    a = z.first;
    b = z.second;
    a--;
    b--;
    if (ans1 == ans2 && ans1 == 0)
    {
      v1 = a1[a];
      v2 = b1[b];
      if (v1.size() == 1)
        ans1 = v1[0];
      if (v2.size() == 1)
        ans2 = v2[0];
    }
    else if (ans1 == 0)
    {
      v1 = a1[a];
      if (v1.size() == 1)
        ans1 = v1[0];
    }
    else if (ans2 == 0)
    {
      v2 = a1[b];
      if (v2.size() == 1)
        ans2 = v2[0];
    }
    else
      break;
  }
  cout << "! " << ans1 << " " << ans2 << endl;
}

int main()
{
  fastio();
  int t = 1;
  // cin>>t;
  while (t--)
    fn();
  return 0;
}