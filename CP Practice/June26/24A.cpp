#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

ll cost;

void dfs(ll u,ll par,vector<vector<array<ll,2>>> &adj,vector<ll>&vis){
    vis[u]=1;
    for(auto [v,cost_]:adj[u]){
        if(!vis[v] && v!=par){
            dfs(v,u,adj,vis);
            cost+=cost_;
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    vector<vector<array<ll,2>>>adj(n);
    for(ll i=0;i<n;i++){
        ll u,v,c;
        cin>>u>>v>>c;

        u--;v--;
        adj[u].push_back({v,0});
        adj[v].push_back({u,c});
    }
    vll vis(n);

    ll c1=adj[0][0][0];
    cost=adj[0][0][1];

    //cout<<c1<<" "<<cost<<endl;
    //vis[0]=1;  karon last e 0 teo aste hbe to complete the circle
    dfs(c1,0,adj,vis);
    ll cost1=cost;
//-----------------------------
    vis.assign(n,0);
    ll c2=adj[0][1][0];
    cost=adj[0][1][1];
    //cout<<c2<<" "<<cost;
    dfs(c2,0,adj,vis);
    ll cost2=cost;
    
    //cout<<cost1<<" "<<cost2;
    //cout<<c1<<" "<<c2<<endl;
    //return;

    cout<<min(cost1,cost2)<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}