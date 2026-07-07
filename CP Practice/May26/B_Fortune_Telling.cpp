#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
11:00
-------
dppp...
always fukking remeber to clear global vars and DSs....

nuhhh...dp oto space pabe na bruhh
parity matching types...
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

ll n,x,target;
map<string,bool>mp;

bool f(ll i,ll total,vll &nums){
    if(i==n){
        if(total==target){
            return 1;
        }
        return 0;
    }

    string s=to_string(i)+"#"+to_string(total);
    if(mp.count(s))
        return mp[s];

    return mp[s]=f(i+1,total^nums[i],nums) || f(i+1,total+nums[i],nums);
}

void solve(){
    
    cin>>n>>x>>target;
    //YOOOOO
    mp.clear();

    vll nums(n);
    for(ll &num:nums) cin>>num;

    if(f(0,x,nums)){
        cout<<"Alice"<<endl;
    }
    else
        cout<<"Bob"<<endl;

    // vector<set<ll>>dp(n);
    // dp[0].insert(x+nums[0]);
    // dp[0].insert(x^nums[0]);

    // for(ll i=1;i<n;i++){
    //     for(ll num:dp[i-1]){
    //         dp[i].insert(num+nums[i]);
    //         dp[i].insert(num^nums[i]);
    //     }
    // }
/*
--------------------------------------------------
fukk i just remebered knapsack of +/^ bw numbers
--------------------------------------------------
*/

    // if(dp[n-1].count(target)){
    //     cout<<"Alice"<<endl;
    //     return;
    // }

    // cout<<"Bob"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;

    while(t--)
        solve();
}