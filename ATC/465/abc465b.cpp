#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
456b
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll x,y,l,r,a,b;
    cin>>x>>y>>l>>r>>a>>b;

    ll ans=0;

    for(ll i=a;i<b;i++){
        if(i>=l && i<r) ans+=x;
        else ans+=y;
    }

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