#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
08:50
-------
2 pointer...dp o hbe ig
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,k;
    cin>>n>>k;

    vll nums(n);
    for(ll &num:nums) cin>>num;

    ll start=0,end=1;
    ll ans=0;

    while(start<=end && end<n){
        while(end<n && nums[end-1]<2*nums[end]){
            end++;
        }
        
        ans+=max(0LL,(end-start-k));
        start=end;
        end++;

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
}