#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
12:20
-------
finding mean kind of thing __WRONG__
********
Median minimizes abs diff..
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    ll n;string s;
    cin>>n>>s;

    vll pos;
    for(ll i=0;i<n;i++) if(s[i]=='*') pos.push_back(i);

    ll sum=accumulate(pos.begin(),pos.end(),0LL);
    ll n_=pos.size();

    if(n_==0){
        cout<<0<<endl;
        return;
    }

    ll median=pos[n_/2];

    ll ans=1e15;

    for(ll m=median-3;m<=median+3;m++){
        ll start=m-n_/2;
        if(start<0)
            continue;

        ll ans_=0;
        for(ll p=0;p<pos.size();p++){
            ans_+=llabs(pos[p]-start);
            start++;
        }

        ans=min(ans,ans_);
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
}