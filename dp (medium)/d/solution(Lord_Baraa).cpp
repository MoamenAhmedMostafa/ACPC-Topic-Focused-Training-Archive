#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    fast
    ll t;
    cin>>t;
    while(t--){
        ll n;string s;
        cin>>n>>s;
        vector<ll>c(n),vis(30,0);
        map<char,ll>freq;
        for(ll i=0;i<n;i++){
            cin>>c[i];
            freq[s[i]]++;
        }
        string ans="";
        for(ll i=0;i<n;i++){
            freq[s[i]]--;
            if(vis[s[i]-'a'])continue;
            while(ans.size()&&s[i]<ans.back()&&freq[ans.back()])vis[ans.back()-'a']=0,ans.pop_back();
            vis[s[i]-'a']=1;
            ans+=s[i];
        }
        ll m=ans.size();
        ll dp[n+1][m+1];
        memset(dp,-0x3f, sizeof(dp));
        for(ll i=0;i<=n;i++)dp[i][m]=0;
        for(ll i=n-1;i>=0;i--){
            for(ll j=m-1;j>=0;j--){
                if(s[i]==ans[j])dp[i][j]=max(dp[i][j],dp[i+1][j+1]+c[i]);
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
            }
        }
        cout<<ans<<nl<<dp[0][0]<<nl;
    }
    return 0;
}
/*
first of all you can get the smallest lexigraphically greedily by using monotonic stack idea
then the problem is converted to you have 2 string a,b |a|<=200000 and |b|<=26 
(since the string b consists of 1 occurence of each character) 
find the biggest cost you can achieve where you choose the b as a subsequence of a.
*/
