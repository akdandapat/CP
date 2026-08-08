#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,c;
    cin>>n>>c;

    ll lessc=0,greatc=0;

    vll a(n);
    for(ll &num:a) cin>>num;
    sort(a.rbegin(),a.rend());

    ll ans=0;
    ll tot=(n+1)/2;

    for(ll i=0;i<n;i++)
        if(i<tot||a[i]>c)
            ans+=a[i]-c;

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}