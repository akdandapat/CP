#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
465d
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    
    ll ans=0;
    while(x!=y){
        if(x>y){
            x/=k;
        }
        else{
            y/=k;
        }
        ans++;
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
