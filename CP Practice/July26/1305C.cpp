#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;

    if(n>m){
        cout<<0<<endl;
        return;
    }

    vll nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];

    ll ans=1;

    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll diff=abs(nums[i]-nums[j]);
            ans=(ans*(diff%m))%m;
        }
    }

    cout<<ans<<endl;
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