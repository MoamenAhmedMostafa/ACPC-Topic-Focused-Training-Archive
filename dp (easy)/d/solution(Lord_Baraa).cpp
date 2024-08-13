#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define yes "YES"
#define no "NO"
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N=1e5+10;
vector<pair<ll,ll>>adj[N],adj2[N];
int main() {
    fast
    ll n,m,q;
    cin>>n>>m>>q;
    ll in[n+1],in2[n+1];
    memset(in,0, sizeof(in));
    memset(in2,0, sizeof(in2));
    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj2[v].push_back({u,w});
        in[v]++;
        in2[u]++;
    }
    queue<ll>qu,qu2;
    vector<ll>topo,topo2;
    for(ll i=1;i<=n;i++){
        if(!in[i])qu.push(i);
        if(!in2[i])qu2.push(i);
    }
    while(!qu.empty()){
        ll u=qu.front();
        qu.pop();
        topo.push_back(u);
        for(auto v:adj[u]){
            if(--in[v.first]==0)qu.push(v.first);
        }
    }
    while(!qu2.empty()){
        ll u=qu2.front();
        qu2.pop();
        topo2.push_back(u);
        for(auto v:adj2[u]){
            if(--in2[v.first]==0)qu2.push(v.first);
        }
    }
    ll dist1[n+1],distn[n+1];
    memset(dist1,-0x3f, sizeof dist1);
    memset(distn,-0x3f, sizeof distn);
    dist1[1]=distn[n]=0;
    for(ll u:topo){
        for(auto v:adj[u]){
            dist1[v.first]=max(dist1[v.first],dist1[u]+v.second);
        }
    }
    for(ll u:topo2){
        for(auto v:adj2[u]){
            distn[v.first]=max(distn[v.first],distn[u]+v.second);
        }
    }
    while(q--){
        ll u;
        cin>>u;
        cout<<(dist1[u]<0||distn[u]<0?-1:dist1[u]+distn[u])<<nl;
    }
    return 0;
}
/*
The graph is a DAG so you can make a topological sort 
to get the maximum distance from node 1 to all nodes and from node n to all nodoes
then the answer for node u will be the mxdist(1,u)+mxdist(n,u) to get the maximum path that passes through u from 1 to n.
*/
