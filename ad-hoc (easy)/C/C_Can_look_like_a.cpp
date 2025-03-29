#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) 
    {
        int n;
        cin >> n;
        int big = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            int x;cin>>x;
            big=max(big,x);
        }
        cout << big << endl;
    }

    return 0;
}