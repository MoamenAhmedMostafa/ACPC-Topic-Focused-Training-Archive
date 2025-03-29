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
        ll n1,n2,n3,n4;cin>>n1>>n2>>n3>>n4; 
        ll x  = n4 * (n1-n2); // calculate summution of N-M elements 
        cout<<( n3 * n1 ) - x<<endl; // calculate  sum remaining from N - M = sum all - sum N - M elements
    }

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.