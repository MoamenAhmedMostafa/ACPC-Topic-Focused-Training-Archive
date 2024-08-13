#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
    ll N=1e6+10;
    ll dp[N];
    vector<vector<ll>>div(N);
    for(ll i=1;i<N;i++)
        for(ll j=i;j<N;j+=i)
            div[j].push_back(i);
    memset(dp,0x3f, sizeof(dp));
    dp[1]=0;
    for(ll i=2;i<N;i++){
        for(ll j:div[i])dp[i]=min(dp[i],dp[i/j]+j);
        dp[i]=min(dp[i],dp[i-1]+1);
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        while(n--){ll x;cin>>x;ans+=dp[x];}
        cout<<ans<<nl;
    }
    return 0;
}
/*
dp[i]=the minimum number of operation to make i equal to 1
You will have 2 trasnitions
1-Decrease i-1 so take dp[i-1]+1(cost of the opartion you made).
2-Choose any divisor so take dp[i/j](to divide i by the divisor j )+j(cost of the operation.
*/
