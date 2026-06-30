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
    ll n;
    cin>>n;

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

    ll x=0;
    for(ll i=1;i<n;i++){
        if(dist0[i]>dist0[x])
            x=i;
    }

    vll distx(n);
    vis.assign(n,0);
    dfs(x,0,adj,distx,vis);

    ll y=0;
    for(ll i=1;i<n;i++){
        if(distx[i]>distx[y])
            y=i;
    }

    vll disty(n);
    vis.assign(n,0);
    dfs(y,0,adj,disty,vis);

    vll maxm(n);
    for(ll i=0;i<n;i++){
        maxm[i]=max(distx[i],disty[i]);
    }

    sort(maxm.begin(),maxm.end());
    for(ll k=1;k<=n;k++){
        ll cnt=lower_bound(maxm.begin(),maxm.end(),k)-maxm.begin();
        cout<<min(cnt+1,n)<<" ";
    }
    cout<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}