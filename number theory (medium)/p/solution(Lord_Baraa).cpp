#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "Yes"
#define no "no"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
const ll N=1e7+10;
int main(){
    baraa
    ll div[N]={};
    for(ll i=1;i<N;i++)
        for(ll j=i;j<N;j+=i)
            div[j]++;
    ll t;
    cin>>t;
    while(t--){
        ll x;cin>>x;
        cout<<div[x]+(x&1)<<nl;
    }
    return 0;
}
//Pattern detection
