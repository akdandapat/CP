#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll r,y;
    cin>>r>>y;

    ll ans=0;
    while(r && y){
        y--;
        r--;
        ans+=1;
    }

    ans+=r;
    ans+=y/2;
    
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