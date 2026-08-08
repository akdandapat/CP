#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    string s;
    cin>>s;
    ll n=s.size();

    string ans;
    bool a=1,b=1;

    for(ll i=0;i<n;i++){
        if(s[i]=='1' && a) {
            a=0;
            continue;
        }
        else if(s[i]=='0' && b){
            b=0;
            continue;
        }
        else ans+=s[i];
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}