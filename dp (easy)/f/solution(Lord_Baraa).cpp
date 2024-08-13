#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[1001][1001];
ll n, m;

ll mx_sum(ll l, ll w){
    ll ans = -1e18;
    for(int i = l; i <= n; i++){
        for(int j = w; j <= m; j++){
            ll x = i - l + 1, y = j - w + 1;
            ans = max(ans, sum[i][j] - sum[i][y - 1] - sum[x - 1][j] + sum[x - 1][y - 1]);
        }
    }
    return ans;
}

void solve(){
    ll k; cin >> n >> m >> k;
    ll arr[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    ll ans = -1e18;
    for(int i = 1; i * i <= k; i++){
        if(k % i == 0){
            ans = max(ans, mx_sum(i, k / i));
            ans = max(ans, mx_sum(k / i, i));
        }
    }
    if(ans == -1e18) 
        cout << "No such rectangle.";
    else 
        cout << ans;
    cout << '\n';
}

int main()
{
    ll t; cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}
/*
Just try all divisors of k.
*/
