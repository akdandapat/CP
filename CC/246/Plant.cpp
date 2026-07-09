#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vll a(n);

    for(ll &num:a) cin>>num;

    ll ans=-1;
    for(ll i=0;i<n-1;i++){
        ll val=min(a[i],a[i+1]);
        ans=max(ans,val);
    }

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