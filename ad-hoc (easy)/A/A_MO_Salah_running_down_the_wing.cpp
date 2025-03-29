#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    freopen("mosalah.in", "r", stdin);
    int tt;
    cin>>tt;
    while (tt--) 
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if(!y) 
        {
            if(m>=n*(x+y))cout<<0<<endl; 
            else cout<<-1<<endl;
        } 
        else cout<<max(0,n*(x+y)-m)<<endl;
    }

    return 0;
}