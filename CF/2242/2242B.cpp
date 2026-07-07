#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2242
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vll nums(n);
    for(ll &num:nums) cin>>num;

    vll nums1(n),nums3(n);

    ll cur1=0,cur3=0;

    for(ll i=0;i<n;i++){
        cur1+=(nums[i]==1?1:-1);
        nums1[i]=cur1;

        cur3+=(nums[i]!=3?1:-1);
        nums3[i]=cur3;
    }

    ll minm=n+1;
    bool flag=0;

    for(ll i=0;i<n-2;i++){
        if(nums1[i]>=0)
            minm=min(minm,nums3[i]);

        if(nums3[i+1]>=minm){
            flag=1;
            break;
        }
    }

    cout<<(flag ? "YES" : "NO")<<endl;
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