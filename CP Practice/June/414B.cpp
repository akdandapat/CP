#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll mod= 1e9+7;

/* 
Author:ARPANN 
11:15
----------------------
thinking to slove by first making adj matrix  between a number and i multiples.....NOOO
kind of dp on multiples got it....i didnt get it at first

*/

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vll>dp(m+1,vll(n+1));
    for(ll j=1;j<=n;j++) dp[1][j]=1;

    for(ll i=1;i<=m-1;i++){
        for(ll j=1;j<=n;j++){
            for(ll val=j;val<=n;val+=j){
                dp[i+1][val]=(dp[i+1][val]+dp[i][j])%mod;
            }
        }
    }

    ll ans=0;
    for(ll i=1;i<=n;i++) ans=(ans+dp[m][i])%mod;
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