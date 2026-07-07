#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
12:45
----------------------
no of elements in each of the components of the graph
*/

void dfs(ll u,vector<vll> &adj,vector<bool> &vis, vll &temp){
    vis[u]=true;
    temp.push_back(u);

    for(ll v:adj[u]){
        if(!vis[v]){
            dfs(v,adj,vis,temp);
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    
    vector<vll> adj(n);
    for(ll i=0;i<m;i++){
        ll s;
        cin>>s;

        ll a;
        if(s!=0){
            
            cin>>a;
            a--;
        }
        if(s<=1) continue;

        for(ll j=0;j<s-1;j++){
            ll b;
            cin>>b;b--;

            adj[a].push_back(b);
            adj[b].push_back(a);

            a=b;
        }
    }

    // for(ll i=0;i<n;i++) cout<<adj[i].size()<<" ";
    // return;

    vector<bool>vis(n);
    vll ans(n);

    for(ll i=0;i<n;i++){
        if(!vis[i]){

            vll temp;
            dfs(i,adj,vis,temp);

            for(ll &num:temp) ans[num]=(ll)temp.size();
        }
    }

    for(ll &num:ans) cout<<num<<" ";
    cout<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
        
    return 0;
}