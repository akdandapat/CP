#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
244B
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    map<ll,ll> cnt;
    map<ll,ll> cost;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;

        ll s=0;
        while(x){
            cnt[x]++;
            cost[x]+=s;

            x/=2;
            s++;
        }
    }

    ll ans=1e9;
    for(auto &[a,b]:cnt)
        if(b==n)ans=min(ans,cost[a]);
    
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