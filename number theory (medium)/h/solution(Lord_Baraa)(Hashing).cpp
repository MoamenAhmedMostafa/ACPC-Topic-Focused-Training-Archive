#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){
    return a+rng()%(b-a+1);
}
struct hasher{
    vector<ll> pw, pref, inv;
    vector<ll> pw2, pref2, inv2;
    ll b1,b2,mod1,mod2,N;
    ll add(ll a,ll b,ll mod){
        return (0LL + a + b + mod) % mod;
    }
    ll mul (ll a, ll b,ll mod){
        return (1LL * a * b) % mod;
    }
    ll fp(ll b, ll p,ll mod){
        if(!p)return 1;
        ll temp = fp(b, p >> 1,mod);
        temp = mul(temp, temp,mod);
        if(p & 1)
            temp = mul(temp,b,mod);
        return temp;
    }
    void pre(ll len)// do not forget it is too important
    {
        N=len;//do not forget to change it according to problem
        b1=rnd(30,100);
        b2=rnd(30,100);
        auto check = [&](ll x) {
            for (ll i = 2; i <= x / i; ++i)
                if (!(x % i))return false;
            return true;
        };
        mod1 = rnd(1e8, 2e9);
        mod2 = rnd(1e8, 2e9);
        while (!check(mod1))--mod1;
        while (mod1 == mod2 or !check(mod2))--mod2;
        pw=inv=pw2=inv2=pref=pref2=vector<ll>(N);
        pw[0] = 1, inv[0] = 1;
        pw2[0] = 1, inv2[0] = 1;
        for ( ll i = 1 ; i < N ; i++)
        {
            pw[i] = mul(b1, pw[i-1],mod1);
            inv[i] = fp(pw[i],mod1-2,mod1);
            pw2[i] = mul(b2, pw2[i-1],mod2);
            inv2[i] = fp(pw2[i],mod2-2,mod2);
        }
    }
    char conv(char x){
        return (x>='a'&&x<='z'?'a':'0');
    }
    void build_string_hash( string &s)
    {
        ll hash_value = 0, hash_value2 = 0;
        for ( ll i = 0 ; i < s.size() ; i++)
        {
            hash_value = add(hash_value,mul(s[i]-conv(s[i])+1, pw[i],mod1),mod1);
            pref[i] = hash_value;
            hash_value2 = add(hash_value2,mul(s[i]-conv(s[i])+1, pw2[i],mod2),mod2);
            pref2[i] = hash_value2;
        }
    }
    ll get_hash(string &s)
    {
        ll hash_value = 0;
        for (ll i = 0; i < s.size(); i++)
            hash_value = add(hash_value, mul(s[i] - conv(s[i]) + 1, pw[i],mod1),mod1);
        return hash_value;
    }
    pair<ll, ll> get_hash(ll L,ll R)
    {
        if(L == 0)
            return {pref[R], pref2[R]};
        return {mul(add(pref[R],-pref[L-1],mod1), inv[L],mod1),
                mul(add(pref2[R],-pref2[L-1],mod2), inv2[L],mod2)};
    }
};
int main() {
    fast
    freopen("xmore.in","r",stdin);
//    freopen("candies.out","w",stdout);
    ll n;
    cin>>n;
    hasher hash;
    vector<hasher>a;
    ll len;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        if(!i)hash.pre((ll)s.size()),len=(ll)s.size();
        hash.build_string_hash(s);
        a.push_back(hash);
    }
    ll q;
    cin>>q;
    while(q--){
        ll i,j;
        cin>>i>>j;
        i--;
        j--;
        ll l=0,r=len-1,ans=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[i].get_hash(0,mid)!=a[j].get_hash(0,mid))r=mid-1,ans=mid;
            else l=mid+1;
        }
        cout<<(ans==-1?-1:len-ans-1)<<nl;
    }
    return 0;
}
/*
The problem can be converted to find the farthest index such that a_index xor b_index = 1.
If we observed the xor of the digits after that index they must be equal
So we will binary search on that index by using hashing.
*/
