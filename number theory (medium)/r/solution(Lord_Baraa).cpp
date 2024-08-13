#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
//    freopen("candies.in","r",stdin);
//    freopen("candies.out","w",stdout);
    ll t;
    cin>>t;
    ll n=1e5+2;
    ll pref[n][17];
    memset(pref,0, sizeof(pref));
    for(ll i=1;i<n;i++){
        for(ll j=0;j<17;j++)pref[i][j]=pref[i-1][j];
        ll c=0,y=i;
        for(ll x=2;x*x<=y;x++){
            while(y%x==0){
                y/=x;
                c++;
            }
        }
        if(y>1)c++;
        pref[i][c]++;
    }
    while(t--){
        ll l,r,x;
        cin>>l>>r>>x;
        cout<<pref[r][x]-pref[l-1][x]<<nl;
    }
    return 0;
}
/*
Just use prefix sum to know the number of x_prime from l to r
*/
