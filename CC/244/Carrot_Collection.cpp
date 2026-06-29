#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
244A
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    l--;
    r--;

    vll a(n);
    for(ll &num:a) cin>>num;

    ll c=0,d=0;
    for(ll i=0;i<n;i++){
        if(i<l) c+=a[i];
        if(i>r) d+=a[i];
    }

    cout<<max(c,d)<<endl;
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