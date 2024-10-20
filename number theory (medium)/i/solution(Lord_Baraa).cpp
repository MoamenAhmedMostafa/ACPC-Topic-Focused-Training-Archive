#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
//    freopen("shop.in","r",stdin);
//    freopen("candies.out","w",stdout);
    ll N=1e5+1;
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    ll frq[N]={};
    for(ll &i:v)cin>>i,frq[i]++;
    for(ll i=N-1;i>=1;i--){
        ll c=n;
        for(ll j=i;j<N;j+=i)c-=frq[j];
        if(c<=k){
            cout<<i<<nl;
            break;
        }
    }
    return 0;
}
/*
If we want the number X to be the gcd so all numbers that are not multiples of X must be deleted.
So if we can try every X from 1 to 1e5 and get the number of numbers that are not multiple of X by the way of sieve.
*/
