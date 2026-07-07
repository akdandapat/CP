#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
8:23
----------------------
no of piece --> no of subarrray
i miss interpreted at first
wrong---->> ill just sort(diff betwn neighbours) and then give to smallest for extras
damn that waas the correct idea...so ironiccc :))))))))))))


*/
// bool valid(ll tot,vll &a,ll k){

//     // ll end=a[0]+len-1;
//     // k--;

    
//     for(ll i=0;i<a.size();i++){
//         if(a[i]<=end) continue;
//         else{
//             k--;
//             if(k==-1) return 0;
//             end=a[i]+len-1;
//         }
//     }

//     return 1;
// }

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vll a(n);
    for(ll &num:a) cin>>num;

    sort(a.begin(),a.end());
    // ll lo=1,hi=a.back()-a[0]+1;

    // ll ans=hi;
    // while(hi>=lo){
    //     ll mid=lo+(hi-lo)/2;
    //     if(valid(mid,a,k)){
    //         ans=mid;
    //         hi=mid-1;
    //     }
    //     else
    //         lo=mid+1;
    // }
    // cout<<ans<<endl;

    if(k>=n){
        cout<<n<<endl;
        return;
    }

    vll gaps;
    for(ll i=0;i<n-1;i++){
        gaps.push_back(a[i+1]-a[i]-1);
    }

    sort(gaps.begin(),gaps.end());

    ll ans=n;

    for(ll i=0;i<n-k;i++){
        ans+=gaps[i];
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