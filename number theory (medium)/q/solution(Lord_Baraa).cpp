#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N=1e7+1;
bool isPrime[N];
int main() {
    fast
//    freopen("candies.in","r",stdin);
//    freopen("candies.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    //sieve
    memset(isPrime,1, sizeof(isPrime));
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i*i<N;i++)
        if(isPrime[i]){
            for(ll j=i*i;j<N;j+=i)
                isPrime[j]=false;
        }
    vector<ll>a(n);
    for(ll &i:a)cin>>i;
    vector<pair<ll,ll>>v;
    ll l=-1,r=-1,c=0,all=0;
    for(ll i=0;i<n;i++){
        if(isPrime[a[i]]){
            c++,all++;
            if(l==-1)l=r=i;
            else r=i;
        }
        if(c==m){
            v.push_back({l,r});
            l=r=-1;
            c=0;
        }
    }
    if(all%m){
        cout<<0;
        return 0;
    }
    ll ans=1,mod=1e9+7;
    for(ll i=1;i<v.size();i++,ans%=mod){
        ans=ans%mod*(v[i].first-v[i-1].second)%mod;
    }
    cout<<ans%mod;
    return 0;
}
/*
Each consecutive m prime numbers will be in the same slice but the size of slice that contain these consecutive numbers can increase by taking non-prime numbers.
for example n=11,m=2
a=[2,6,2,4,4,3,3,4,4,5,5]
so first slice will be [2,6,2] // maybe the slice has non-primes but we are forced to take them to reach the primes.
second slice will be [3,3]
third slice will be [5,5]
but I can make the first slice be [2,6,2,4] or [2,6,2,4,4] but I can not make it [2,6,2,4,4,3] because now number of primes excedded m
similarly for second slive it can be [3,3,4] or [3,3,4,4] but also can not be [3,3,4,4,5] for the same reason.
So the answer will be the multiplication of sizes of non-primes between each m consecutive primes
*/
