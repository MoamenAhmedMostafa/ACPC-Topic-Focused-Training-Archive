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
        ll n, k;cin>>n>>k;
        ll groups = n/k;   // 
        ll cnt =(groups*(n+1))-(k*groups*(groups+1)/2);
        cout<<cnt<<endl;
    }

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.