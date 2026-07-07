#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
14:55
-------
brute force ig...
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    ll n;
    cin>>n;

    vll idx(n);
    for(ll &num:idx) cin>>num;

    vll val(n);
    for(ll &num:val) cin>>num;

    vector<vll> a(n,vll());
    for(ll i=0;i<n;i++){
        ll ind=idx[i];
        ind--;
        a[ind].push_back(val[i]);
    }
    // vector<bool>has(n);

    vector<vll>pref(n,vll());
    for(ll i=0;i<n;i++){

        pref[i].resize((ll)a[i].size());
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());

        // if(a[i].size()>0)
        //     has[i]=1;
        for(ll j=0;j<a[i].size();j++){
            if(j==0) pref[i][j]=a[i][j];
            else pref[i][j]=pref[i][j-1]+a[i][j];
        }

    }

    vll ans(n);
    for(ll i=0;i<n;i++){
        ll s=a[i].size();
        for(ll k=1;k<=s;k++){
            ll div=s/k;
            ans[k-1]+=pref[i][div*k-1];
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
}