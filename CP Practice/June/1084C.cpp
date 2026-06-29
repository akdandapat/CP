#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
22:44
-----------------------------------
simple greedy...
*/
const ll mod=1e9+7;

void solve(){
    
    string s;
    cin>>s;

    ll n=s.size();
    ll ans=0;

    for(ll i=0;i<n;i++){
        ll cnt=0;
        while(i<n){
            if(s[i]=='a') cnt++;
            if(s[i]=='b') break;
            i++;
        }
        
        if(cnt){
            if(ans==0)
                ans=cnt+1;
            else ans=ans*(cnt+1)%mod;
        }
    }

    cout<<(ans==0 ? 0 : ans-1)<<endl;
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