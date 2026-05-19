#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll i=0;i<n;i++) cin>>a[i];

    ll x;
    cin>>x;
    x--;

    cout<<a[x]<<endl;
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