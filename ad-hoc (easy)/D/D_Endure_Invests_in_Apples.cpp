#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,l,r;
    cin>>n>>l>>r;
    int s=0,m=0,la=0;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        if(x<=l)s++;
        else if(x>r)la++;
        else m++;
    }
    cout<<s<<" "<<m<<" "<<la;

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.