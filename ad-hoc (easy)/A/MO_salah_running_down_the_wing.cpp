#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    freopen("mosalah.in", "r", stdin); 
    int tt;cin>>tt; // test case 
    while (tt--) 
    {
        int n,m,x,y;cin>>n>>m>>x>>y; // input 
        if(!y) // if there is no remaining mathces 
        {
            if(m>=n*(x+y))cout<<0<<endl; // you have avg that greater than or equal  needed avg 
            else cout<<-1<<endl; // you have a less than the needed avg 
        } 
          /*
            avg =( Goals + needed Goals ) / (Played Matches  + remaining Matches ) 
           so needed Goals = avg * (played matches + remaining mathcs ) - Goals  
          */
        else cout<<max(0,n*(x+y)-m)<<endl;  
    }

    return 0;
}
