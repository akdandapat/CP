#include<bits/stdc++.h>
using namespace std;

/*

Author: ARPANN
00:45
-------------------------
mp<string,ll>------->>TLE
ll dp[][]----------->>Passes

*/

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define MOD 998244353

ll dp[5005][5005];
ll f(vll &a,ll idx,ll sum){
    if(idx==a.size()){
        return 0;
    }
    
    if(dp[idx][sum]!=-1)
        return dp[idx][sum];
    
    ll sum_=sum+a[idx];
    ll maxm_=a[idx];

    return dp[idx][sum]=(max(maxm_,(sum_+1)/2)+f(a,idx+1,sum_)+f(a,idx+1,sum))%MOD;
}

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;
    sort(a.begin(),a.end());
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=5000;j++){
            dp[i][j]=-1;
        }
    }

    cout<<f(a,0,0)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;

    while(t--)
        solve();
}