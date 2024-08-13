#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll mod=1e9+7;
ll fp(ll a,ll b){
    ll ans=1,push=a;
    while(b>0){
        if(b&1){ans=(ans * push)%mod;}
        push=(push * push)%mod;
        b>>=1;
    }
    return ans%mod;
}
int main() {
    fast
    freopen("math.in","r",stdin);
    // freopen("candies.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(n%mod*fp(2,n-1)%mod)%mod<<nl;
    }
    return 0;
}
/*
Pattern detection
*/
