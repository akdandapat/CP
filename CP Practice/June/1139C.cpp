#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll MOD=1e9+7;

vector<vll> adj;
vll vis;
ll sz;

ll powm(ll x,ll n){
    x%=MOD;

    if(n==0) return 1;
    else if(n==1) return x;

    ll p=powm(x*x,n/2);

    if(n%2) return p*x%MOD;
    else return p;
}

void dfs(ll x){
    vis[x]=1;
    sz++;
    for(auto &i:adj[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    adj.assign(n,{});
    for(ll i=0;i<n-1;i++){
        ll u,v,x;
        cin>>u>>v>>x;
        u--;v--;

        if(x==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    ll ans=0;
    vis.assign(n,0);
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            sz=0;
            dfs(i);
            ans=(ans+powm(sz,k))%MOD;
        }
    }

    ans=(powm(n,k)-ans+MOD)%MOD;
    cout<<ans<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}