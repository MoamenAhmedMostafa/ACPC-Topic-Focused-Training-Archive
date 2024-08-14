#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N=1e6+10;
int main() {
    baraa
    ll t=1;
    cin>>t;
    while(t--) {
        ll l,r;
        cin>>l>>r;
        ll n=61,c=0;
        for(ll i=n-1;i>=0;i--){
            bitset<61>b=0;
            for(ll j=i;j>=0;j--){
                b[j]=1;
                c+=(b.to_ullong()>=l&&b.to_ullong()<=r);
            }
        }
        cout<<c<<nl;
    }
    return 0;
}
