#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n1,n2,n3,n4,n5;
    cin>>n1>>n2>>n3>>n4>>n5;  // input n1,n2 (Photo Range) and n3,n4,n5 (Positions of Chair)
    // if only one chair position in the photo range so you will be seeing while sitting on chair 
    bool flag=0;
    if(n3>=n1 && n3<=n2)flag=1;  
    if(n4>=n1 && n4<=n2)flag=1;
    if(n5>=n1 && n5<=n2)flag=1;
    if(flag)cout<<"Yes";
    else cout<<"No";

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.