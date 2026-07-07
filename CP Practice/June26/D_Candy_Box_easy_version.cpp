#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
18:08
----------------------
kind of greedy stl stuff ig..
*/

void solve(){
    ll n;
    cin>>n;
    
    vll a(n);
    for(ll &num:a) cin>>num;

    map<ll,ll>mp;
    for(ll &num:a) mp[num]++;

    vll freq;
    for(auto &[c,d]:mp) freq.push_back(d);
    sort(freq.begin(),freq.end());
    reverse(freq.begin(),freq.end());

    ll last=1e8;
    ll ans=0;
    for(auto p:freq){
        //cout<<p<<" ";
        // ll st=last+1;
        // ll tot=p-st+1;
        // ans+=(tot*st+tot*(tot-1)/2);
        // last=p;
        ll val=min(last-1,p);
        if(val==0) break;

        ans+=val;
        last=val;
    }

    cout<<ans<<endl;
    //cout<<endl;
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