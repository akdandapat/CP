#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    string s;
    cin>>s;

    ll n=s.size();
    ll ans=0;

    for(ll i=0;i<n;i++){
        if(s[i]=='C'){
            ans+=(1+min(i,n-1-i));
        }
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