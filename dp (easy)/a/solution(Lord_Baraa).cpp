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
    freopen("lex.in","r",stdin);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<string>v(n);
        string dp[n+1];
        dp[n]="";
        for(auto &i:v)cin>>i;
        for(ll i=n-1;i>=0;i--)dp[i]=max(dp[i+1],v[i]+dp[i+1]);
        cout<<dp[0]<<nl;
    }
    return 0;
}
