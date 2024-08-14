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
    ll n;string s;
    cin>>n>>s;
    map<ll,ll>inv;
    for(char x:s)inv[(x-'a')]=1;
    vector<ll>all;
    for(ll i=0;i<26;i++)all.push_back(i+97);
    ll dp[n+1],mod=1e9+7;
    memset(dp,0, sizeof(dp));
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<26;j++){
            if((i==n&&inv[j])||i-all[j]<0)continue;
            dp[i]=dp[i]%mod+dp[i-all[j]]%mod;
            dp[i]%=mod;
        }
    }
    cout<<dp[n]%mod;
    return 0;
}
//basic counting dp problem
