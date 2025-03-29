#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    string s;cin>>s;  // input time now       
    int n;cin>>n;    // input minutes to add
    int  hours = (int(s[0]-'0')*10)  + int(s[1]-'0') + n/60;   // calculating hours from (time now) and from (minutes to add)  
    int  min = (int(s[3]-'0')*10)  + int(s[4]-'0') + n%60;     // calculating minutes from (time now) and from (minutes to add)
    if(min>=60) // check if minutes more than 60 
    {
        hours+=min/60;
        min=min%60;
    }
    if(hours>=24)hours/=24;  // check if hours more than 24


    if(hours < 10)cout<<"0"<<hours<<":";
    else cout<<hours<<":";
    if(min  < 10)cout<<"0"<<min;
    else cout<<min;

    return 0;
}

// Failure is another stepping stone to greatness.
// It's fine to celebrate success, but it is more important to heed the lessons of failure.
// Competition is the fuel that ignites innovation.