#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
---------------------------
same mistake ...fukkk
*/
#define ll long long
#define endl '\n'

vector<pair<ll,ll>> adj[900005];
ll down[400005];
ll up[400005];
ll tot=0;

void buildDown(ll ind,ll l,ll r){
    down[ind]=++tot;

    if(l==r){
        adj[down[ind]].push_back({l,0});
        return;
    }

    ll mid=(l+r)/2;

    buildDown(2*ind,l,mid);
    buildDown(2*ind+1,mid+1,r);

    adj[down[ind]].push_back({down[2*ind],0});
    adj[down[ind]].push_back({down[2*ind+1],0});
}

void buildUp(ll ind,ll l,ll r){
    up[ind]=++tot;

    if(l==r){
        adj[l].push_back({up[ind],0});
        return;
    }

    ll mid=(l+r)/2;

    buildUp(2*ind,l,mid);
    buildUp(2*ind+1,mid+1,r);

    adj[up[2*ind]].push_back({up[ind],0});
    adj[up[2*ind+1]].push_back({up[ind],0});
}

void queryDown(ll ind,ll l,ll r,ll ql,ll qr,ll u,ll cost){
    if(ql<=l&&r<=qr){
        adj[u].push_back({down[ind],cost});
        return;
    }

    ll mid=(l+r)/2;

    if(ql<=mid)
        queryDown(2*ind,l,mid,ql,qr,u,cost);

    if(qr>mid)
        queryDown(2*ind+1,mid+1,r,ql,qr,u,cost);
}

void queryUp(ll ind,ll l,ll r,ll ql,ll qr,ll v,ll cost){
    if(ql<=l&&r<=qr){
        adj[up[ind]].push_back({v,cost});
        return;
    }

    ll mid=(l+r)/2;

    if(ql<=mid)
        queryUp(2*ind,l,mid,ql,qr,v,cost);

    if(qr>mid)
        queryUp(2*ind+1,mid+1,r,ql,qr,v,cost);
}

void solve(){
    ll n,q,s;
    cin>>n>>q>>s;

    tot=n;

    buildDown(1,1,n);
    buildUp(1,1,n);

    while(q--){
        ll t;
        cin>>t;

        if(t==1){
            ll u,v,cost;
            cin>>u>>v>>cost;
            adj[u].push_back({v,cost});
        }
        else if(t==2){
            ll u,l,r,cost;
            cin>>u>>l>>r>>cost;
            queryDown(1,1,n,l,r,u,cost);
        }
        else{
            ll v,l,r,cost;
            cin>>v>>l>>r>>cost;
            queryUp(1,1,n,l,r,v,cost);
        }
    }

    vector<ll> dist(tot+1,1e18);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> heap;

    dist[s]=0;
    heap.push({0,s});

    while(!heap.empty()){
        ll d=heap.top().first;
        ll u=heap.top().second;
        heap.pop();

        if(d>dist[u])
            continue;

        for(auto edge:adj[u]){
            ll v=edge.first;
            ll cost=edge.second;

            if(dist[u]+cost<dist[v]){
                dist[v]=dist[u]+cost;
                heap.push({dist[v],v});
            }
        }
    }

    for(ll i=1;i<=n;i++){
        if(dist[i]==1e18)
            cout<<-1<<" ";
        else
            cout<<dist[i]<<" ";
    }

    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}