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

vll par(200005);
vll groupsz(200005);
ll total=0;

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
        total+=groupsz[u]*groupsz[v];
        par[u]=v;
        groupsz[v]+=groupsz[u];
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<Edge> edges(n-1);
    for(ll i=0;i<n-1;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    
    vector<array<ll,2>> query(m);
    for(ll i=0;i<m;i++){
        cin>>query[i][0];
        query[i][1]=i;
    }
    
    sort(edges.begin(),edges.end(),cmp);
    sort(query.begin(),query.end());

    for(ll i=1;i<=n;i++){
        par[i]=i;
        groupsz[i]=1;
    }

    total=0;
    vll ans(m);
    ll curr=0;
    for(ll i=0;i<m;i++){
        while(curr<n-1 &&edges[curr].w<=query[i][0]){
            unite(edges[curr].u,edges[curr].v);
            curr++;
        }
        ans[query[i][1]]=total;
    }

    for(ll x:ans)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}