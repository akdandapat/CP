#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
567E
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

const ll md1=1e9+7;
const ll md2=1e9+9;
const ll inf=1e18;

void solve(){
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    s--,t--;

    vector<vector<array<ll,3>>> adj_s(n),adj_t(n);
    vector<array<ll,3>> edges;

    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;

        edges.push_back({u,v,w});
        adj_s[u].push_back({v,w,0});
        adj_t[v].push_back({u,w,0});
    }

    vll mindist_s(n,inf),mindist_t(n,inf);
    vll way_s1(n),way_s2(n),way_t1(n),way_t2(n);

    auto dijkstra=[&](ll src,vector<vector<array<ll,3>>> &adj, vll &mindist, vll &way1, vll &way2){
        priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> pq;

        mindist[src]=0;
        way1[src]=1;
        way2[src]=1;
        pq.push({0,src});

        while(!pq.empty()){
            auto [dist,u]=pq.top();
            pq.pop();

            if(dist>mindist[u]) continue;

            for(auto &[v,wt,id]:adj[u]){
                if(mindist[v]>dist+wt){
                    mindist[v]=dist+wt;
                    way1[v]=way1[u];
                    way2[v]=way2[u];
                    pq.push({mindist[v],v});
                }
                else if(mindist[v]==dist+wt){
                    way1[v]=(way1[v]+way1[u])%md1;
                    way2[v]=(way2[v]+way2[u])%md2;
                }
            }
        }
    };

    dijkstra(s,adj_s,mindist_s,way_s1,way_s2);
    dijkstra(t,adj_t,mindist_t,way_t1,way_t2);

    ll shortest_path=mindist_s[t];

    for(auto &[u,v,wt]:edges){
        if(mindist_s[u]+wt+mindist_t[v]==shortest_path){
            ll way1=(way_s1[u]*way_t1[v])%md1;
            ll way2=(way_s2[u]*way_t2[v])%md2;

            if(way1==way_s1[t] && way2==way_s2[t])
                cout<<"YES"<<endl;
            
            else if(wt>1)
                cout<<"CAN 1"<<endl;
            
            else
                cout<<"NO"<<endl;
        }
        else{
            ll diff=mindist_s[u]+wt+mindist_t[v]-shortest_path;
            ll req=diff+1;

            if(wt>req)
                cout<<"CAN "<<req<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    while(t--)
        solve();

    return 0;
}