#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
16:16
----------------------
I just keep forgettin these...geez :((
*/

void solve(){
    ll n;
    cin>>n;
    
    vll arr(n);
    for(ll &num:arr) cin>>num;
    
    ll odd=0,even=1;
    ll cur=0;
    ll ans=0;
    
    for(ll i=0;i<n;i++){
        if(arr[i]<0) cur=1-cur;
        
        if(cur==0){
            ans+=even;
            even++;
        }
        else{
            ans+=odd;
            odd++;
        }
    }
    
    ll tot=n*(n+1)/2;
    cout<<tot-ans<<" "<<ans<<endl;
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