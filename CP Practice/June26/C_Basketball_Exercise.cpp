#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
16:16
----------------------
1D DP
*/

void solve(){
    ll n;
    cin>>n;
    
    vll a(n),b(n);
    for(ll &num:a) cin>>num;
    for(ll &num:b) cin>>num;
    
    vector<vll>dp(n+1,vll(2));
    dp[1][0]=a[0];
    dp[1][1]=b[0];

    for(ll i=2;i<=n;i++){
        dp[i][0]=a[i-1]+max(dp[i-1][1],dp[i-2][1]);
        dp[i][1]=b[i-1]+max(dp[i-1][0],dp[i-2][0]);
    }

    cout<<max(dp[n][0],dp[n][1])<<endl;
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