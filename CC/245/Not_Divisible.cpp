#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
245E
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vll nums(n+1),nums1(n+1),nums2(n+1);

    for(ll i=1;i<=n;i++){
        cin>>nums[i];
        nums1[i]=n+1-nums[i];
        nums2[i]=i;
    }

    ll id1=1,id2=-1;

    for(ll i=2;i<=n;i++){
        if(nums1[i]!=nums1[1]){
            id2=i;
            break;
        }
    }

    if(id2==-1){
        cout<<-1<<endl;
        return;
    }

    for(ll i=1;i<=n;i++){
        if(nums2[i]==nums1[i]){
            ll j;
            if(nums1[id1]==nums1[i])
                j=id2;
            else j=id1;
            swap(nums2[i],nums2[j]);
        }
    }

    for(ll i=1;i<=n;i++)
        cout<<nums2[i]<<" ";
    cout<<endl;
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