#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    cin>>n;

    vll ans;
    map<ll,vll>mp;

    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    ll start;
    for(auto &[a,b]:mp) if(b.size()==1){
        start=a;
        ans.push_back(a);
        break;
    }

    set<ll>vis;
    vis.insert(start);

    while(ans.size()!=n+1){
        for(auto &v:mp[start]){
            if(!vis.count(v)){
                ans.push_back(v);
                vis.insert(v);
                start=v;
                break;
            }
        }
    }

    for(ll &num:ans) cout<<num<<" ";
    cout<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}