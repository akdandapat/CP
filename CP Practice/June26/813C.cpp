#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

void dfs(ll u,ll d,vector<vll> &adj,vll &dist,vll &vis){
    dist[u]=d;
    vis[u]=1;

    for(ll v:adj[u]){
        if(!vis[v]){
            dfs(v,d+1,adj,dist,vis);
        }
    }
}

void solve(){
    ll n,x;
    cin>>n>>x;
    x--;

    vector<vll>adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll dist0(n);
    vll vis(n);
    dfs(0,0,adj,dist0,vis);

    vll distx(n);
    vis.assign(n,0);
    dfs(x,0,adj,distx,vis);

    ll ans=0;
    for(ll i=0;i<n;i++){
        if(dist0[i]>distx[i])
            ans=max(ans,dist0[i]);
    }

    cout<<2*ans<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}