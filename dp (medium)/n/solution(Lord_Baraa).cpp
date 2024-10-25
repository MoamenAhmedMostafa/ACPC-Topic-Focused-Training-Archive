#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;//
ll n,x;
vector<ll>v;
map<ll,ll>fact;
map<ll,ll>factorize(ll tt){
    map<ll,ll>mp;
    for(ll i=2; i*i<=tt; i++){
        ll cnt=0;
        while(tt%i==0){
            tt/=i;
            cnt++;
        }
        if(cnt) mp[i]=cnt;
    }
    if(tt>1) mp[tt]=1;
    return mp;
}
const ll N=1e5+1,mod=1e9+7;
ll dp[N][(1<<9)+10];
ll solve(ll i,ll msk){
    if(i==n)return (__builtin_popcountll(msk)==fact.size());
    if(dp[i][msk]!=-1)return dp[i][msk];
    ll op1=solve(i+1,msk),op2=solve(i+1,msk|v[i]);
    return dp[i][msk]=(op1%mod+op2%mod)%mod;
}
ll fp(ll a,ll b){
    ll ans=1,push=a;
    while(b>0){
        if(b&1){ans=(ans * push)%mod;}
        push=(push * push)%mod;
        b>>=1;
    }
    return ans;
}
int main() {
    baraa
    ll t=1;
    cin>>t;
    while(t--){
        cin>>n>>x;
        v.clear();
        fact= factorize(x);
        ll c=0;
        for(ll i=0;i<n;i++){
            ll z;cin>>z;
            c+=(z==1);
            map<ll,ll>mp= factorize(z);
            bool ok=1;
            bitset<11>bit=0;
            ll idx=0;
            for(auto [a,b]:fact)bit[idx++]=(mp.find(a)!=mp.end()&&mp[a]==b);
            for(auto [a,b]:mp)ok&=(fact.find(a)!=fact.end()&&b<=fact[a]);
            if(ok)v.push_back(bit.to_ullong());
        }
        n=v.size();
        for(ll i=0;i<=n;i++)memset(dp[i],-1, sizeof(dp[i]));
        if(x==1)cout<<fp(2,c)%mod-1<<nl;
        else cout<<solve(0,0)%mod<<nl;
    }
    return 0;
}
