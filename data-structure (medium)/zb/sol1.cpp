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

const int MOD = 1e9+9;

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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int inverse(int a, int m){
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        x = (x % m + m) % m;
        return  x; // x is the inverse of a
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll> poss(n);
    vector<ll> v(n);
    vector<ll> bits(n);

    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        if(v[i]>=2){
            poss[i]=1;
        }
        bits[i]= (v[i]&1);
        v[i] = (v[i]&1)*binpow(2,n-i-1,MOD);
    }


    SegmentTree possible(poss),sum(v);
    ll inv = 500000005;

    int q;
    cin>>q;
    while (q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            possible.update(b-1,b-1, 0);
            c&=1;
            bits[b-1]^=c;
            if(!bits[b-1]){
                sum.update(b-1,b-1, 0);
            }
            else
            {
                sum.update(b-1,b-1, binpow(2,n-b,MOD));
            }

        }
        else if (possible.RMQ(b-1,c-1)){
            cout << "Impossible\n";
        }
        else
        {
            ll s = sum.RMQ(b-1,c-1);
            ll bin = binpow(inv,n-c,MOD);
            cout << (s*bin)%MOD<<endl;
        }
    }

    return 0;
}