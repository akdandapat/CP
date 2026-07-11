#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
466a
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vll a(n),s(n);

    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>s[i];
        if(mp.count(a[i]))
            mp[a[i]]=max(mp[a[i]],s[i]);
        else
            mp[a[i]]=s[i];
    }

    for(ll i=1;i<=m;i++){
        if(mp.count(i))
            cout<<mp[i]<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
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