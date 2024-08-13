#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long  ll;
typedef unsigned long long  ull;
typedef long double  ld;
#define lp(i,n)      for(int i=0;i<n;i++)
#define lpi(i,j,n)   for(int i=j;i<n;i++)
#define lpd(i,j,n)   for(int i=j;i>=n;i--)
#define MP           make_pair
#define clr(v, d)    (memset(v, d, sizeof(v)))
#define all(v)     (v.begin()),(v.end())
#define rall(v)     (v.rbegin()),(v.rend())
#define N 100004
const double pi = acos(-1);

// ll n,t,m,k;

ll ans;
ll mod = 1e9 + 7;

class SegmentTree {
private:
    vector<ll> tree, tree2, tree3, lazy;
    int n;

    void build(int node, int start, int end, const vector<ll>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            tree2[node] = (arr[start]*arr[start]) % mod;
            tree3[node] = (tree2[node] * arr[start]) % mod;
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % mod;
            tree2[node] = (tree2[2 * node + 1] + tree2[2 * node + 2]) % mod;
            tree3[node] = (tree3[2 * node + 1] + tree3[2 * node + 2]) % mod;
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            ll len = (end - start + 1);
              // Apply the pending updates
            tree3[node] += (3ll * tree2[node] * lazy[node]) % mod + 
                            (((lazy[node] * lazy[node])%mod) * (3ll * tree[node]) % mod) %mod +
                            (((lazy[node] * lazy[node])%mod) * ((len * lazy[node]) % mod)) % mod;
            
            tree2[node] += (((lazy[node] * lazy[node])%mod) * len) % mod + (2ll* lazy[node] * tree[node]) % mod;
            tree[node] += (len * lazy[node]) % mod;

            tree[node] %= mod;
            tree2[node] %= mod;
            tree3[node] %= mod;

            
            if (start != end) {  // If not a leaf node, propagate the lazy value to children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;  // Clear the lazy value for the current node
        }
    }

    void updateRange(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r) {
            ll len = end - start +1;
            tree3[node] += (3ll * tree2[node] * val) % mod + 
                (((val * val)%mod) * (3ll * tree[node]) % mod) %mod +
                (((val * val)%mod) * ((len * val) % mod)) % mod;
            
            tree2[node] += (((val * val)%mod) * len) % mod + (2ll* val * tree[node]) % mod;
            tree[node] += (len * val) % mod;

            tree[node] %= mod;
            tree2[node] %= mod;
            tree3[node] %= mod;

            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % mod;
        tree2[node] = (tree2[2 * node + 1] + tree2[2 * node + 2]) % mod;
        tree3[node] = (tree3[2 * node + 1] + tree3[2 * node + 2]) % mod;
    }

    ll queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return 0;

        if (start >= l && end <= r)
            return tree3[node];

        int mid = (start + end) / 2;
        ll leftSum = queryRange(2 * node + 1, start, mid, l, r);
        ll rightSum = queryRange(2 * node + 2, mid + 1, end, l, r);
        return (leftSum + rightSum) % mod;
    }

public:
    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        tree2.resize(4 * n);
        tree3.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    void updateRange(int l, int r, ll val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};


int main() {
 
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
// freopen("inc.in","r",stdin); 
// freopen("e_out.txt","w",stdout); 
cout.precision(8);
int t;
// cin>>t;
t = 1;
while(t--){
    int n;
    cin>>n;
    vector<ll>a(n);
    lp(i,n)cin>>a[i];
    SegmentTree segtree(a);
    int q;
    cin>>q;
    while(q--){
        int type, l, r;
        cin>>type>>l>>r;
        --l, r--;
        if(type == 1){
            ll val;
            cin>>val;
            segtree.updateRange(l,r,val);
        }
        else {
            cout<<segtree.queryRange(l,r)<<"\n";
        }
        
    }
     
}

}
 
