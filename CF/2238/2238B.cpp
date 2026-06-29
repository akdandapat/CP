#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
CF 2238B
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    ll res=0;
    for(ll i=1;i<=n;i++) res+=(n/i)*(n/i);

    cout<<res<<endl;
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