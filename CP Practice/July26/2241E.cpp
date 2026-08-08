#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void dfs(ll node,ll par,vector<vector<ll>>& adj,vll& sizes,vll& parent){
    sizes[node]=1;
    parent[node]=par;

    for(ll child:adj[node]){
        if(child==par)
            continue;
        dfs(child,node,adj,sizes,parent);
        sizes[node]+=sizes[child];
    }
}

void solve(){
    ll n;
    cin>>n;

    vll nums(n+1);
    for(ll i=1;i<=n;i++)
        cin>>nums[i];

    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll sizes(n+1),parent(n+1);
    dfs(1,0,adj,sizes,parent);

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll root=sqrt(nums[i]);
        if(root*root!=nums[i])
            continue;

        vll parts;
        for(ll child:adj[i]){
            if(child==parent[i])
                parts.push_back(n-sizes[i]);
            else
                parts.push_back(sizes[child]);
        }

        ll sum1=0,sum2=0,sum3=0;
        for(ll curr:parts){
            sum1+=curr;
            sum2+=curr*curr;
            sum3+=curr*curr*curr;
        }

        ll ways3=(sum1*sum1*sum1-3*sum1*sum2+2*sum3)/6;
        ll ways2=(sum1*sum1-sum2)/2;
        ans+=ways2+ways3;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--)
        solve();
}