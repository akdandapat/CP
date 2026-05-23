#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

/*
Author:ARPANN
Started: 21:00 26-04-2026
Completed: 2:41 27-04-2026
*/


ll n,ans=1e6;
vll a;
map<ll,ll> mp;

void f(ll idx,ll rem){
    if(idx==n){
        ans=min(ans,rem);
        return;
    }

    if(mp.count(idx) && mp[idx]<=rem) 
        return;
    mp[idx]=rem;

    if(idx+a[idx]<n) 
        f(idx+a[idx]+1LL,rem);

    f(idx+1LL,rem+1LL);
}

void solve(){
    cin>>n;
    ans=1e6;
    mp.clear();

    a.assign(n,0LL);
    for(ll &num:a) 
        cin>>num;

    f(0LL,0LL);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}