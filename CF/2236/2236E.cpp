#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define endl '\n'

/* 
Author:ARPANN 
-----------------------------------
2236
*/

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    for(int &num:a) cin>>num;

    int z=(int)(pow(n+1,2));
    vi nums1(z,-1);
    vi nums2(z,n+1);
    vector<bool> vis(n+1);

    for(int l=0;l<n;l++){
        int minm=a[l];
        int maxm=a[l];

        for(int r=l;r<n;r++){

            if(vis[a[r]]) break;
            vis[a[r]]=1;

            minm=min(minm,a[r]);
            maxm=max(maxm,a[r]);

            ll len=r-l+1;
            if(maxm-minm==len-1){
                ll idx=len*(n+1)+minm;
                
                if(nums1[idx]==-1){
                    nums1[idx]=l;
                    nums2[idx]=r;
                }

                else{
                    nums1[idx]=max(l,nums1[idx]);
                    nums2[idx]=min(r,nums2[idx]);
                }
            }
        }

        for(ll r=l;r<n;r++){
            if(!vis[a[r]]) break;
            vis[a[r]]=0;
        }
    }

    for(ll i=n/2;i>=1;i--){
        for(ll j=1;j<=n-2*i+1;j++){
            ll idx1=i*(n+1)+j;
            ll idx2=i*(n+1)+j+i;
            
            if((nums1[idx1]!=-1 && nums1[idx2]!=-1) && (nums2[idx1]<nums1[idx2] || nums2[idx2]<nums1[idx1])){
                cout<<i<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;
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







// void solve(){
//     ll n;
//     cin>>n;
//     vll a(n);
//     for(ll &num:a) cin>>num;

//     vector<map<ll,array<ll,2>>> nums(n+1);
//     vector<bool> vis(n+1);

//     for(ll l=0;l<n;l++){
//         ll minm=a[l];
//         ll maxm=a[l];

//         for(ll r=l;r<n;r++){

//             if(vis[a[r]]) break;
//             vis[a[r]]=1;

//             minm=min(minm,a[r]);
//             maxm=max(maxm,a[r]);

//             ll len=r-l+1;
//             if(maxm-minm==len-1){
//                 if(!nums[len].count(minm))
//                     nums[len][minm]={l,r};

//                 else{
//                     nums[len][minm][0]=max(nums[len][minm][0],l);
//                     nums[len][minm][1]=min(nums[len][minm][1],r);
//                 }
//             }
//         }

//         for(ll r=l;r<n;r++){
//             if(!vis[a[r]]) break;
//             vis[a[r]]=0;
//         }
//     }

//     for(ll i=n/2;i>=1;i--){
//         for(auto &[x,arr1]:nums[i]){
//             if(nums[i].count(x+i)){
//                 auto arr2=nums[i][x+i];
//                 if(arr1[1]<arr2[0] ||  arr2[1]<arr1[0]){
//                     cout<<i<<endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout<<0<<endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll t=1;
//     cin>>t;
//     while(t--)
//         solve();
//     return 0;
// }
