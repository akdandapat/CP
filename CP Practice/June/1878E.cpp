#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
12:30
----------------------
making prefix array of ors is pointless we cant get pre[r]-pre[l] just by any ops........but we can make prefix array of set bits for each position and then we can perform this without any problem......that that and bs is common for highest/lowest type and as prefix array of or will always be decreasing and <=ff...

*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    vector<vll> pref(30,vll(n+1,0));
    for(ll j=0;j<30;j++){
        for(ll i=0;i<n;i++){

            if((1LL<<j)&a[i])
                pref[j][i+1]=pref[j][i]+1;
            
            else
                pref[j][i+1]=pref[j][i];
        }
    }

    auto valid=[&](ll l,ll r,ll k){
        ll ans=0;
        for(ll i=0;i<30;i++){
            if(pref[i][r+1]-pref[i][l]==r-l+1)
                ans+=(1LL<<i);
        }
        return ans>=k;
    };

    ll q;
    cin>>q;

    while(q--){
        ll l,k;
        cin>>l>>k;
        l--;

        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }

        ll lo=l,hi=n-1;
        ll ans=l;
        while(hi>=lo){
            ll mid=lo+(hi-lo)/2;
            if(valid(l,mid,k)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        cout<<ans+1<<" ";
    }
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