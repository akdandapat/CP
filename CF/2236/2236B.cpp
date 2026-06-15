#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
-----------------------------------
2236
*/

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vll cnt(k);
    for(ll i=0;i<n;i++)
        if(s[i]=='1')
            cnt[i%k]++;
        
    for(ll i=0;i<k;i++){
        if(cnt[i]%2!=0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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