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

    ll ans=0,cur=0;

    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;

        cur=max(cur,a);
        ans+=cur-a;
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