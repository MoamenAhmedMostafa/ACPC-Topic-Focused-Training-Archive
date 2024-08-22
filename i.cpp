/* Mohamed_Awad13313 */
#include <bits/stdc++.h>
#define test int t=0;cin>>t;while(t--)
#define Done return 0;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v, d) memset(v, d, sizeof(v))
#define endl "\n"
#define int long long
using namespace std;
int tmp = 0;
const int S = 1e6+10;
const int mod = 1e9 + 7;
int from_one_2_n(int n) // get number of digits from 1 to n
{
    int ans = 0;
    for (int i = 9; n > 0; i *= 10)
    {
        ans += n;
        n -= i;
    }
    return ans;
}
void solve()
{

    int l,r;
    cin >> l >> r;

    l--;
    cout << from_one_2_n(r) - from_one_2_n(l)  << endl;
}

int32_t main() {
    fast
    test
    {
        solve();
    }

    Done
}
