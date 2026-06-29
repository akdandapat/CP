#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
CF 2238C
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll ans;

ll dfs(ll u,vector<vll>& adj){
    ll ff=0,ss=0;
    for(ll v:adj[u]){
        ll cnt=1+dfs(v,adj);
        if(cnt>ff){
            ss=ff;
            ff=cnt;
        }
        else if(cnt>ss)
            ss=cnt;
    }

    ans+=ss;
    return ff;
}

void solve(){
    ll n;
    cin>>n;

    vector<vll>adj(n);

    for(ll i=1;i<n;i++){
        ll p;
        cin>>p;
        p--;

        adj[p].push_back(i);
    }

    ans=n;
    dfs(0,adj);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}