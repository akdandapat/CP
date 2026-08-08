#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    string s;
    cin>>n>>s;

    ll len=0;
    ll ans=0;

    for(ll i=0;i<n;i++){
        if(s[i]=='#') {
            if(len>2){
                cout<<2<<endl;
                return;
            }
            ans+=len;
            len=0;
        }
        else len++;
    }
    if(len>2){
        cout<<2<<endl;
        return;
    }
    ans+=min(len,2ll);
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