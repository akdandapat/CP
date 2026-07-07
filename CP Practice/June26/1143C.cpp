#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
8:23
----------------------
ill just remove and then sort first
*/


void dfs(ll u,vector<vll> &adj, vll &c, vll &ans){//boolf-->1:kharap
    bool flag=c[u];
    bool all=1;
    for(ll v:adj[u]) if(c[v]==0) all=0;

    if(all && flag)
        ans.push_back(u);

    for(ll v:adj[u]){
        dfs(v,adj,c,ans);
    }

}

void solve(){
    ll m;
    cin>>m;

    vector<vll>adj(m);
    ll root;
    vll c(m);
    vll ans;

    for(ll i=0;i<m;i++){
        ll a;
        cin>>a>>c[i];

        if(a==-1) root=i;
        else {
            a--;
            adj[a].push_back(i);
        }
    }

    dfs(root,adj,c,ans);
    sort(ans.begin(),ans.end());

    if(ans.size()==0) cout<<-1<<endl;
    else{
        for(ll &num:ans) cout<<num+1<<" ";
        cout<<endl;
    }

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