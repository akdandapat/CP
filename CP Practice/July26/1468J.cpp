#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

struct Edge{
    ll u,v,w;
};

bool cmp(Edge &a,Edge &b){
    return a.w<b.w;
}

ll par[200005];

ll find(ll node){
    if(par[node]==node){
        return node;
    }
    return par[node]=find(par[node]);
}

void unite(ll u,ll v){
    u=find(u);
    v=find(v);
    if(u!=v){
        par[u]=v;
    }
}

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<Edge> edges(m);
    ll minm=2e9;
    for(ll i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        minm=min(minm,abs(edges[i].w-k));
    }

    sort(edges.begin(),edges.end(),cmp);
    for(ll i=1;i<=n;i++)
        par[i]=i;
    
    ll ans=0;
    ll maxm=0;
    ll cnt=0;

    for(ll i=0;i<m;i++){
        if(find(edges[i].u)!=find(edges[i].v)){
            unite(edges[i].u,edges[i].v);

            maxm=max(maxm,edges[i].w);
            if(edges[i].w>k)
                ans+=edges[i].w-k;

            cnt++;
            if(cnt==n-1)
                break;
        }
    }

    if(maxm<=k)
        cout<<minm<<endl;
    else
        cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}