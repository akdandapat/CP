#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
242
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,m;
    cin>>n>>m;

    string s,t;
    cin>>s>>t;

    string ans;
    for(ll i=0;i<min(n,m);i++){
        if(s[i]==t[i]) ans+=s[i];
        else break;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}