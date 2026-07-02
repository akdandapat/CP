#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
245
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vll nums(n),nums1(n);

    for(ll i=0;i<n;i++)
        cin>>nums[i];
    for(ll i=0;i<n;i++)
        cin>>nums1[i];

    ll ans=0;
    vll nums2(n);

    for(ll i=0;i<n;i++){
        ll x=nums[i];
        ll req=k+1;

        ll m=0;
        for(ll j=0;j<n;j++){
            if(nums[j]>=x) req--;
            else nums2[m++]=(x-nums[j])*nums1[j];
        }

        ll curr=0;
        if(req<=0) curr=k*x;
        else{
            sort(nums2.begin(), nums2.begin()+m);

            ll cost=0;
            for(ll j=0;j<req;j++)
                cost+=nums2[j];

            curr=k*x-cost;
        }
        ans=max(ans,curr);
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