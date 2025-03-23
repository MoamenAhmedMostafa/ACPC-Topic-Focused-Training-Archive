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
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(x%2==1)cnt++;  // count number of odd numbers
        }
        if(cnt%2==0)cout<<"Win\n";  // of the number of odd numbers is even so he can take each two of them forming a even number and take them 
        else cout<<"Lose\n";
        
    }

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.