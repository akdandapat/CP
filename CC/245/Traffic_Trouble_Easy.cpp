#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vll nums(n+1),nums1(n+1);

    for(ll i=1;i<=n;i++)
        cin>>nums[i];

    for(ll i=1;i<=n;i++)
        cin>>nums1[i];

    vll nums2(n+1);

    for(ll i=1;i<n;i++)
        nums2[i]=nums[i+1]-nums[i]-1;

    nums2[n]=1e10;

    vll vis(n+1);
    vll nums3(n+1);

    for(ll i=1;i<=min(n,k);i++){
        for(ll j=1;j<=n;j++){
            nums3[j]=min(nums2[j],nums1[j]);
            if(nums3[j]==0) vis[j]=1;
        }

        for(ll j=1;j<n;j++)
            nums2[j]=max(0LL,nums2[j]-nums1[j])+nums3[j+1];
    }

    ll ans=0;

    for(ll &num:vis) ans+=num;

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