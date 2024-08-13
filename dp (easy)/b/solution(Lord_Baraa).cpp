#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
    freopen("money.in", "r", stdin);
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<pair<ll,string>>v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i].second>>v[i].first;
        }
        sort(all(v));
        cout<<v.back().second<<nl;
    }
    return 0;
}
