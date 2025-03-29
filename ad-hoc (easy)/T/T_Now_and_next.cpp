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
    int x,y;
    cin>>x>>y; 
    cout<<((x%y==0)? "YES" : "NO")<<endl; // is x a divisor of y or not 
   }

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.