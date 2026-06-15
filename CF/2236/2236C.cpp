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
    ll a,b,x;
    cin>>a>>b>>x;

    vll diva,divb;
    ll a_=a;

    while(a_){
        diva.push_back(a_);
        a_/=x;
    }

    ll b_=b;
    while(b_){
        divb.push_back(b_);
        b_/=x;
    }

    diva.push_back(0);
    divb.push_back(0);

    ll ans=1e10;
    for(ll i=0;i<diva.size();i++){
        for(ll j=0;j<divb.size();j++){
            ll diff=llabs(diva[i]-divb[j]);
            ans=min(ans,diff+i+j);
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