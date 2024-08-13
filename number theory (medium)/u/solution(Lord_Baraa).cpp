#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
    ll n,k;
    cin>>n>>k;
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        for(ll j=2;j*j<=x;j++){
            while(x%j==0){
                x/=j;
                mp[j]++;
            }
        }
        if(x>1)mp[x]++;
    }
    bool ok=1;
    for(auto [x,y]:mp){
        ok&=(y%k==0);
    }
    cout<<(ok?"YES":"NO")<<nl;
    return 0;
}
/*
The sum of prime powers must be divisble by k to know if the product has k-th root because the product of some numbers equals adding their prime powers together
In the first example test case : 2 * 6 * 12 * 9 = (2^1) * (2^1*3^1) * (2^2*3^1) * (3^2) = 2^4 * 3^4 = so here the powers are 4,4 which are divisble by k=4. 
*/
