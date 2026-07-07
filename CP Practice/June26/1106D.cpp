#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<vll>adj(n);
    for(ll i=0;i<k;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(0);

    vll vis(n);
    vll ans;

    while(!pq.empty()){
        ll u=pq.top();
        pq.pop();

        if(vis[u]) continue;
        
        vis[u]=1;
        ans.pb(u);

        for(ll v:adj[u]){
            if(!vis[v])
                pq.push(v);
        }
    }

    for(ll &num:ans) cout<<num+1<<" ";
    cout<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}