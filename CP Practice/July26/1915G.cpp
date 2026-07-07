#include<bits/stdc++.h>
using namespace std;

/*
Authorr: ARPANN
*/
#define ll long long
#define vll vector<ll>
#define arr3 array<ll,3>
#define endl "\n"

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vector<array<ll,2>>> adj(n);

    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vll s(n);
    for(ll &num:s) cin>>num;

    priority_queue<arr3,vector<arr3>,greater<arr3>> pq;
    // {time, min_bike, node}

    vector<vll> mint(n,vll(1005,1e18));

    mint[0][s[0]]=0;
    pq.push({0,s[0],0});

    while(!pq.empty()){
        auto arr=pq.top();
        pq.pop();

        ll time=arr[0];
        ll minm=arr[1];
        ll u=arr[2];

        if(time>mint[u][minm]) continue;

        if(u==n-1){
            cout<<time<<endl;
            return;
        }

        for(auto &[v,wt]:adj[u]){
            ll extra_time=minm*wt;
            ll minm_v=min(minm,s[v]);

            if(time+extra_time<mint[v][minm_v]){
                mint[v][minm_v]=time+extra_time;
                pq.push({time+extra_time,minm_v,v});
            }
        }
    }

    cout<<-1<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
}