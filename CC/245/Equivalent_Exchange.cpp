#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
245B
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    ll red=0,blue=0;
    ll minr=1e9,minb=1e9;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;

        red+=a;
        blue-=a;

        minr=min(minr,red);
        minb=min(minb,blue);
    }

    ll k_=0;
    if(minr<0) k_-=minr;
    if(minb<0) k_-=minb;

    if(k_<=k){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
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