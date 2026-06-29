#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'


ll n;
ll ans=0;
vector<vll> adj;

ll dfs(ll curr,ll par){
	ll sub=1;
	for(ll v:adj[curr]){
		if(v!=par){
			sub+=dfs(v,curr);
		}
	}
    
	if(sub%2==0 && curr!=n){
		ans++;
	}
	return sub;
}

void solve(){
    cin>>n;

    if(n%2!=0){
		cout<<-1<<endl;
		return;
	}

	adj.resize(n+1);
	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(n,0);
	cout<<ans<<endl;
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