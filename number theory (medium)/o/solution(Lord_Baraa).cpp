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
    ll n;
    cin>>n;
    ll spf[n+1];
    for(ll i=1;i<=n;i++)spf[i]=i;
    for(ll i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=n;j+=i)
                if(spf[j]==j)
                    spf[j]=i;
        }
    }
    ll ans=0;
    for(ll i=2;i<=n;i++){
        ll c=0,x=i;
        while(x!=1){
            c++;
            x/=spf[x];
        }
        if(spf[c]==c&&c>1)ans++;
    }
    cout<<ans;
    return 0;
}
/*
s=number of prime factors of x - 1 because I will leave one factor to make x prime
for example 12 = 2^2 * 3^1
number of prime factors = 2 + 1 = 3
s=3-1=2 because I will divide 12 by 2 to make it 2^2 * 3^1 then I will divide it by 3 (or 2 it will not differ) to make it 2^1=2 which is prime
then he said s+1 prime number so I am intereseted in s+1 = number of prime factors - 1 + 1 = number of prime factors
So if the number of prime factors is prime I will increase the answer
I used smallest prime factor way to factorize each i from 2 to n in log(n) and nloglogn preprocessing.
*/
