#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
14:30
*/

void solve(){
    ll n;
    cin>>n;
    
    vll a(n);
    for(ll &num:a) cin>>num;

    vll b(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        b[i]=a[i]-i;
        mp[b[i]]+=a[i];
    }

    ll ans=-1;
    for(auto &[c,d]:mp) ans=max(ans,d);

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