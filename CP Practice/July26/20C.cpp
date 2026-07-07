#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
20C
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vector<array<ll,2>>> adj(n);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--; v--;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> pq;

    const ll INF=1e18;
    vll mindist(n,INF);
    vll parent(n,-1);

    mindist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        auto arr=pq.top();
        pq.pop();

        ll dist=arr[0];
        ll u=arr[1];

        if(dist>mindist[u]) continue;

        for(auto &neigh:adj[u]){
            ll v=neigh[0];
            ll add_dist=neigh[1];

            if(dist+add_dist<mindist[v]){
                mindist[v]=dist+add_dist;
                parent[v]=u;
                pq.push({mindist[v],v});
            }
        }
    }

    if(mindist[n-1]==INF){
        cout<<-1<<endl;
        return;
    }

    vll nums;
    ll cur=n-1;

    while(cur!=-1){
        nums.push_back(cur+1);
        cur=parent[cur];
    }

    reverse(nums.begin(),nums.end());

    for(ll x:nums)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    while(t--)
        solve();

    return 0;
}