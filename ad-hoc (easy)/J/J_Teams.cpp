#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int tt;cin>>tt;
    while(tt--)
    {
        int n;cin>>n;
        int big1=INT_MIN,big2=INT_MIN;
        for(int i=0;i<n;i++){int x1;cin>>x1;big1=max(big1,x1);}   // find biggest element in team1
        for(int i=0;i<n;i++){int x2;cin>>x2;big2=max(big2,x2);}   // find biggest element in team2
        if(big1>big2)cout<<"team1"<<endl;
        else cout<<"team2"<<endl;
    }
    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.