#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N=1e5+2,M=4;
ll dp[N][M];
ll n;
string s,x="scpc";
ll solve(ll i,ll j){
    if(j==4)return 0;
    if(i==n)return 1e14;
    if(dp[i][j]!=-1)return dp[i][j];
    char f=x[j];
    ll op1=1e14,op2=1e14;
    op1=solve(i+1,j);
    op2=solve(i+1,j+1)+(f!=s[i]);
    return dp[i][j]=min(op1,op2);
}
int main() {
    fast
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(ll i=0;i<=n;i++)
            for(ll j=0;j<=3;j++)
                dp[i][j]=-1;
        cout<<solve(0,0)<<nl;
    }
    return 0;
}
/*
dp[i][j]=minimum number of operation to make a subsequence of characters from index i and from j-th index of scpc to the last index.
*/
