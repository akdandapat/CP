#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
-----------------------------------
2236
*/

void solve(){
    ll n;
    cin>>n;

    ll maxm=-1,minm=10;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;

        maxm=max(maxm,a);
        minm=min(minm,a);
    }
    cout<<maxm-minm+1<<endl;
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