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
    string s,t;
    cin>>s>>t;

    ll n=s.size();
    ll m=t.size();

    vll prefs(n),preft(m);

    prefs[0]=(s[0]-'0');
    for(ll i=1;i<n;i++) prefs[i]=(prefs[i-1]+(s[i]-'0'))%10;

    preft[0]=(t[0]-'0');
    for(ll i=1;i<m;i++) preft[i]=(preft[i-1]+(t[i]-'0'))%10;

    if(prefs.back()!=preft.back()){
        cout<<-1<<endl;
        return;
    }

    vector<vll> dp(n+1, vll(m+1,0));

    for(ll i=1;i<n;i++){
        for(ll j=1;j<m;j++){
            
            if(prefs[i-1]==preft[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    if(n>1 && m>1)
        cout<<1+dp[n-1][m-1]<<endl;
    else 
        cout<<1<<endl;
    
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