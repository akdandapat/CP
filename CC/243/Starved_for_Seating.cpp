#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
243
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vll a(n);
    ll tot=0;
    for(ll &num:a) {
        cin>>num;
        tot+=num/2;
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll tot_ij=tot+a[i]/2+a[j]/2;
            if(tot_ij>k) ans++;
        }
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