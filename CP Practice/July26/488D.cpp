#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,s,l;
    cin>>n>>s>>l;

    vll nums(n+1);
    for(ll i=1;i<=n;i++) cin>>nums[i];

    ll inf=1e18;
    vll dp(n+1,inf);
    dp[0]=0;

    multiset<ll> win;
    multiset<ll> vals;

    ll left=1;

    ll minm=0;
    ll maxm=-1;

    for(ll i=1;i<=n;i++){
        win.insert(nums[i]);

        while(*win.rbegin()-*win.begin()>s){
            win.erase(win.find(nums[left]));
            left++;
        }

        ll leftidx=left-1;
        ll right=i-l;

        while(minm<leftidx){
            if(minm<=maxm)
                vals.erase(vals.find(dp[minm]));
            minm++;
        }

        while(maxm<right){
            maxm++;
            if(maxm>=minm)
                vals.insert(dp[maxm]);
        }

        if(!vals.empty() && *vals.begin()!=inf)
            dp[i]=*vals.begin()+1;
    }

    cout<<(dp[n]==inf?-1:dp[n])<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}