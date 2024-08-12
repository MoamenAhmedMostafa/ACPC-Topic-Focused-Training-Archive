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
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll &i:v)cin>>i;
    ll MAX=(1<<10);
    vector<vector<ll>>dp(2,vector<ll>(MAX+1,1e9));
    for(ll i=0;i<=MAX;i++)dp[1][i]=0;
    for(ll i=n-1;i>=0;i--){
        for(ll j=MAX-1;j>=0;j--){
            dp[0][j]=dp[0][j+1];
            dp[0][j]=min(dp[0][j],dp[1][j]+__builtin_popcount(v[i]^j));
        }
        dp[1]=dp[0];
    }
    cout<<dp[0][0];
    return 0;
}
/*
dp[i][j]=minimum nunber of operations required to sort the suffix from index i to n where the element in index i-1 will be j
The transitions will be in 2 cases
First one is to choose a larger number than j
Second one is to choose the j itself to be in index i.
Finally you must use rolling table to fit the memory in the constraints
*/
