#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
18:21
-----------------------------------
adj list thekei hye jbe ig...
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    vll deg(n);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;

        a--;b--;
        deg[a]++;
        deg[b]++;
    }
    ll mul=4ll*2*4*....

    ll total=accumulate(a.begin(),a.end(),0ll);
    vll b;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<deg[i]-1;j++){
            b.push_back(a[i]);
        }
    }

    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    //for(ll &num:b) cout<<num<<" ";
    //cout<<b.size();
    cout<<total<<" ";
    for(ll i=0;i<n-2;i++){
        if(i<b.size()){
            total+=b[i];
        }
        cout<<total<<" ";
    }
    cout<<endl;
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