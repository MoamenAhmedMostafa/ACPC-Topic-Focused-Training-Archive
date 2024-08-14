#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll fp(ll a,ll b,ll mod){
    ll ans=1,push=a;
    while(b>0){
        if(b&1){ans=(ans%mod * push%mod)%mod;}
        push=(push%mod * push%mod)%mod;
        b>>=1;
    }
    return ans%mod;
}
const ll N=1e3+10;
ll dp[N][N];
ll n;
string s;
const ll mod=1e9+7;
ll solve(ll i,ll j){
    if(i==n)return j==0;
    if(j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1=0,op2=0;
    if(s[i]=='?'){
        op1=solve(i+1,j+1);
        op2=solve(i+1,j-1);
    }
    else{
        op1=solve(i+1,j+(s[i]=='(')-(s[i]==')'));
    }
    return dp[i][j]=(op1+op2)%mod;
}
int main() {
    baraa
    ll t=1;
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(ll i=0;i<=n;i++)for(ll j=0;j<=n;j++)dp[i][j]=-1;
        solve(0,0);
        ll c=0;
        for(char x:s)c+=(x=='?');
        ll y=1;
      	while(c--){
      		y*=2;y%=mod;
      	}
        cout<<(dp[0][0]%mod*fp(y,mod-2,mod)%mod)%mod<<nl;
    }
    return 0;
}
