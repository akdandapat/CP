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

vll par(200005);

ll find(ll node){
    if(par[node]==node){
        return node;
    }
    return par[node]=find(par[node]);
}

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<Edge> edges(m);

    for(ll i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }

    ll target=(1LL<<30)-1;

    for(ll bit=29;bit>=0;bit--){
        target&=~(1LL<<bit);

        for(ll i=1;i<=n;i++){
            par[i]=i;
        }

        ll cnt=0;

        for(ll i=0;i<m;i++){
            if((edges[i].w|target)==target){
                ll u_=find(edges[i].u);
                ll v_=find(edges[i].v);
                if(u_!=v_){
                    par[u_]=v_;
                    cnt++;//successful merge cnt
                }
            }
        }

        if(cnt<n-1){// jodi successful merges at the end mst toiri korteh na pare
            target|=(1LL<<bit);
        }
    }

    cout<<target<<endl;
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