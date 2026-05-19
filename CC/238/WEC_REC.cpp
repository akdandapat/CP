#include<bits/stdc++.h>
using namespace std;

/*
Name: ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,x,k;
    cin>>n>>x>>k;

    vll a(n);
    for(ll &num:a) cin>>num;

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    
    ll k_=1;
    ll ans=0;
    for(ll i=0;i<x;i++){
        ans++;
        if(i!=n-1 && a[i]!=a[i+1])
            k_++;

        if(k_>k)
            break;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}