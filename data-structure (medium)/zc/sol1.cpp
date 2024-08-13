/**
 *    Author:  ZyadFVA
 *    --
**/

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>
using namespace std;



#define ll long long

const int MOD = 1e9+7;

class SegmentTree { // OOP style
private:
    ll n; // n = (int)A.size()
    vector<ll> A, st, lazy; // the arrays
    ll l(ll p) { return p << 1; } // go to left child
    ll r(ll p) { return (p << 1) + 1; } // go to right child
    ll conquer(ll a, ll b) {
        if (a == -1) return b; // corner case
        if (b == -1) return a;
        return (a+b)%MOD; // RMQ
    }

    void build(ll p, ll L, ll R) { // O(n)
        if (L == R)
            st[p] = A[L]; // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(ll p, ll L, ll R) {
        if (lazy[p] != -1) { // has a lazy flag
            st[p] = lazy[p]; // [L..R] has same value
            if (L != R) // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p]; // propagate downwards
            else // L == R, a single index
                A[L] = lazy[p]; // time to update this
            lazy[p] = -1; // erase lazy flag
        }
    }

    ll RMQ(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j) return -1; // infeasible
        if ((L >= i) && (R <= j)) return st[p]; // found the segment
        ll m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(ll p, ll L, ll R, ll i, ll j, ll val) { // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) { // found the segment
            lazy[p] = val; // update this
            propagate(p, L, R); // lazy propagation
        } else {
            ll m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            ll lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            ll rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];


            st[p] = (st[l(p)] + st[r(p)])%MOD;
        }
    }

public:
    SegmentTree(ll sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vector<ll> &initialA) : SegmentTree((ll) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(ll i, ll j, ll val) { update(1, 0, n - 1, i, j, val); }

    ll RMQ(ll i, ll j) { return RMQ(1, 0, n - 1, i, j); }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    vector<ll> tmp = v;
    sort(tmp.begin(),tmp.end());
    map<ll,ll> index;
    ll last = 0;
    for (ll i = 0; i < n; ++i) {
        if(index.count(tmp[i])==0)
        {
            index[tmp[i]]=last++;  
        }
    }


    ll ans=0;
    SegmentTree st(vector<ll>(n+1,0ll));
    SegmentTree f(vector<ll>(n+1,0ll));
    ll times=1;
    for (int i = 0; i < n; ++i) {
        ans*=2;
        ans%=MOD;

        if(index[v[i]]>0) {
            ll less = f.RMQ(0, index[v[i]] - 1);
            ll allsum = less * v[i];
            allsum %= MOD;
            ans += (((allsum - st.RMQ(0, index[v[i]] - 1))%MOD + MOD)%MOD);
            ans%=MOD;
        }

        if(index[v[i]]<last-1) {
            ll more = f.RMQ(index[v[i]] + 1, last-1);
            ll allsum2 = more * v[i];
            allsum2 %= MOD;
            ans += (((st.RMQ(index[v[i]] + 1, n - 1) - allsum2)%MOD + MOD)%MOD);
            ans%=MOD;
        }

        f.update(index[v[i]], index[v[i]], (f.RMQ(index[v[i]], index[v[i]])+times)%MOD);
        ll x = st.RMQ(index[v[i]],index[v[i]]);
        st.update(index[v[i]],index[v[i]],0);
        x+=v[i]*times;
        x%=MOD;
        st.update(index[v[i]],index[v[i]],x);
        times*=2;
        times%=MOD;
    }

    cout << ans<<endl;


    return 0;
}