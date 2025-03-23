#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int tt;cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;                           
        ll count=n/2;  // pow(n,2)/4 - > must be square  so pow(n,2) = 4 * count so n = 2 * count so count = n / 2  
        if(n<=1)cout<<"0\n";
        else cout<<count<<"\n";
    }

    return 0;
}
// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.