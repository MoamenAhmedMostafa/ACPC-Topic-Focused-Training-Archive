#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    freopen("looking.in", "r", stdin);
    int tt;cin>>tt; // test cases
    while (tt--)
    {
        ll n,k;cin>>n>>k; // case input
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i]; // array input 
        }
        int ans=0;
        for(int i = 0; i < n; i++)
        {
            ans|=a[i];
        } 
        cout<<ans<<endl;
    }
    return 0;
}
// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.
