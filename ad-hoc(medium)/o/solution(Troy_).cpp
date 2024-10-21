//Practice like you've never won, Perform like you've never lost.

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds{
    typedef tree<int,
            null_type,
            less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

#define el "\n"
#define fi first
#define se second
#define pb push_back
#define int long long
#define ON(n,k) ((n)|(1LL<<(k)))
#define OFF(n,k) ((n)&~(1LL<<(k)))
#define isON(n,k) (((n)>>(k))&1LL)
#define cin(v) for(auto &i:v)cin>>i
#define cout(v) for(auto &i:v)cout<<i<< " "
#define all(a) a.begin(), a.end()
#define rev(a) a.begin(), a.end(), greater<int>()
#define Troy_was_here ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5+5;
const int MOD = 1e9+7;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char di[] = {'R', 'L', 'D', 'U'};

/*
    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
*/


void Insert(ordered_set &s,int x)
{ //this function inserts one more occurrence of (x) into the set.
    s.insert(x);
}
bool Exist(ordered_set &s,int x)
{ //this function checks weather the value (x) exists in the set or not.

    if((s.upper_bound(x))==s.end())
    {
        return 0;
    }
    return ((*s.upper_bound(x))==x);
}
void Erase(ordered_set &s,int x)
{ //this function erases one occurrence of the value (x).

    if(Exist(s,x))
    {
        s.erase(s.upper_bound(x));
    }
}

void AnswerMachine()
{
    int n,q; cin>>n>>q;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    map<int,int>curr;
    ordered_set st;

    while(q--)
    {
        int k; cin>>k;

        if(k==1)
        {
            int idx,x; cin>>idx>>x;
            int rem=v[idx]-curr[idx];
            if(x<=rem)
            {
                if(Exist(st,curr[idx]))
                {
                    Erase(st,curr[idx]);
                }

                curr[idx]+=x;

                Insert(st,curr[idx]);
            }
        }

        else if(k==2)
        {
            int idx,x; cin>>idx>>x;
            if(x<=curr[idx])
            {
                if(Exist(st,curr[idx]))
                {
                    Erase(st,curr[idx]);
                }

                curr[idx]-=x;

                Insert(st,curr[idx]);
            }
        }

        else if(k==3)
        {
            int z; cin>>z;
            int y = st.order_of_key(z);
            int ans = (st.size()-y);
            cout<<ans<<el;
        }
    }
}

int32_t main()
{
    Troy_was_here
    int t=1;
    //cin>>t;
    while(t--)
    {
        AnswerMachine();
        cout<<el;
    }
}