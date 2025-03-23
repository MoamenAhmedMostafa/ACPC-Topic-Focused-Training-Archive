#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    unsigned ll n;
    cin>>n;
    int cnt=0;
    while(n>=1)   // we need only to count the numbers of monsters divisions that the astronaut will face and then calculate the sum of monsters the astronaut will face 
    // summution of (division power 2) minus 1  
    {
        cnt++;
        n/=2;
    }
    unsigned ll ans = pow(2,cnt)-1;
    cout<<ans;
    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.