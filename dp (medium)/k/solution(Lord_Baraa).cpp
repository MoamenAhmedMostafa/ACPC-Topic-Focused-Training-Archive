#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N=1e2+10,M=(1<<11);
ll n;
vector<ll>v;
ll ans[N][N];
ll dp[N][N][M];
ll solve(ll l,ll r,ll xr){
    if(l>r){
        ll a=xr,b=ans[0][n-1]^xr;
        return (a==b?0:(a>b?1:2));
    }
    if(dp[l][r][xr]!=-1)return dp[l][r][xr];
    ll op1=solve(l+1,r-1,xr^v[r]);
    ll op3=solve(l,r-2,xr^v[r]);
    ll op2=solve(l+1,r-1,xr^v[l]);
    ll op4=solve(l+2,r,xr^v[l]);
    //cout<<l<<' '<<r<<' '<<xr<<' '<<op1<<' '<<op2<<' '<<op3<<' '<<op4<<nl;
    return dp[l][r][xr]=(((op1==1&&op3==1)|(op2==1&&op4==1))?1:((!op1&&!op3)|(!op2&&!op4))?0:2);
}
int main() {
    baraa
    memset(dp,-1, sizeof(dp));
    cin>>n;
    v=vector<ll>(n);
    for(ll &i:v)cin>>i;
    for(ll i=0;i<n;i++){
        ll x=0;
        for(ll j=i;j<n;j++){
            x^=v[j];
            ans[i][j]=x;
        }
    }
    ll an=solve(0,n-1,0);
    if(an==1)cout<<"Toty";
    else if(an==0)cout<<"Toty-Boty";
    else cout<<"Boty";
    return 0;
}
/*
dp[i][j][xr]=what will happen if toty starts first playing in range from l to r with xor elements equals to xr.(0-draw, 1-Toty win, 2-Boty win)
so we will have 4 transitions.
1-toty take the last element in the range and boty take the first one.
2-toty take the first element and boty take the last one.
3-toty take the last and boty take the previous last.
4-toty take the first and boty take after the first.
In these transitions we are playing 2 turns in the same transition so that each time we want to solve range[l,r] we know that toty starts first.
by the xor property (a^a=0) so if we know that toty took some elements so boty must take the remaining elements so if we know that the total xor of elements is all and toty took xr elements so boty took all^xr.
*/
