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
    ll n;
    cin>>n;

    vll a(n),pre(n);

    for(ll &num:a)
        cin>>num;

    ll ans=0,mx=0;
    vll pos;

    for(ll i=0;i<n;i++){
        pre[i]=(i?max(pre[i-1],a[i]):a[i]);
        ans+=pre[i]-a[i];

        if(i==0||pre[i]==a[i]&&pre[i]>pre[i-1])
            pos.push_back(i);
        else
            mx=max(mx,pre[i-1]-a[i]);
    }

    pos.push_back(n);

    for(ll i=0;i+1<pos.size();i++){
        ll l=pos[i],r=pos[i+1];
        ll cur=(l?pre[l-1]:0);
        ll res=0;

        for(ll j=l+1;j<r;j++){
            cur=max(cur,a[j]);
            res+=a[l]-cur;
        }

        mx=max(mx,res);
    }

    cout<<ans-mx<<endl;
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