#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
21:00
----------------------------------------------------
max gap is the for an number is the max it cant...
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    vector<vll> pos(n+1);
    for(ll i=0;i<n;i++){
        pos[a[i]].push_back(i);
    }

    vll ans(n,-1);
    for(ll i=1;i<=n;i++){
        if(!pos[i].size()) continue;
        ll maxm=0;

        for(ll j=1;j<pos[i].size();j++)
            maxm=max(maxm,pos[i][j]-pos[i][j-1]);
        
        maxm=max({maxm,pos[i][0]+1,n-pos[i].back()});

        for(ll j=maxm-1;j<n;j++){
            if(ans[j]!=-1) break;
            ans[j]=i;
        }

    }
    
    for(ll &num:ans) cout<<num<<" ";
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