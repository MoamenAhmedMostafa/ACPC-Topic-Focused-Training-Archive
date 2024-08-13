/**
 *    Author:  ZyadFVA
 *    --
**/

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define int long long

const int MOD = 1e9+7;


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while (t--)
    {
        int a ,c;
        cin>>a>>c;
        int ans=1;
        map<ll,ll> mp;
        set<ll>s;
        for (int i = 2; i*i <= c ; ++i) {
            while (c%i==0)
            {
                c/=i;
                mp[i]++;
                s.insert(i);
            }
        }
        if(c>1)
        {
            mp[c]++;
            s.insert(c);
        }

        map<ll,ll> mp2;
        for (int i = 2; i*i <= a ; ++i) {
            while (a%i==0)
            {
                s.insert(i);
                a/=i;
                mp2[i]++;
            }
        }
        if(a>1)
        {
            mp2[a]++;
            s.insert(a);
        }

        bool flag = false;
        for(auto factor:s)
        {
            if(mp2[factor] > mp[factor]) 
            {
                cout << -1<<endl;
                flag=true;
                break;
            } else if (mp[factor]>mp2[factor])
            {
                for (int i = 0; i < mp[factor]; ++i) {
                    ans*=factor;
                }
            }
        }

        if(flag)
        {
            continue;
        }
        else
            cout << ans<<endl;
    }


    return 0;
}