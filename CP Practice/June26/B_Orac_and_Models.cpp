#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
09:20
*/

void solve(){
    ll n;
    cin>>n;
    
    vll s(n+1);
    for(ll i=1;i<=n;i++){
        cin>>s[i];
    }
    
    vll dp(n+1,1);
    ll ans=1;
    
    for(ll i=1;i<=n;i++){
        for(ll j=i*2;j<=n;j+=i){
            if(s[i]<s[j]){
                dp[j]=max(dp[j],dp[i]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    
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