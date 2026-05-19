#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    ll n,k;
    cin>>n>>k;
    k--;

    vector<vll> a;
    vll l(n);
    for(ll i=0;i<n;i++) {
        ll s;
        cin>>s;
        l[i]=s;

        vll temp(s);
        for(ll j=0;j<s;j++)
            cin>>temp[j];
        
        a.push_back(temp);
    }

    vll c(n);
    for(ll &num:c) cin>>num;

    ll idx=0;
    ll i=0;
    while(idx<=k){
        idx+=c[i]*l[i];
        if(idx>k){
            idx-=c[i]*l[i];
            break;
        }
        i++;
    }
    
    ll c_idx=k-idx;
    ll d_idx=c_idx%l[i];
    // cout<<idx<<endl<<c_idx<<endl<<d_idx<<endl;
    // return;
    cout<<a[i][d_idx]<<endl;

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