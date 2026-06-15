#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
----------------------
2234
*/

void solve(){
    ll n;
    cin>>n;
    
    vll a(n);
    for(ll &num:a) cin>>num;

    vll ans(n);
    for(ll i=0;i<n;i++){
        vll prev(n),next(n);

        ll maxm=0;
        for(ll j=1;j<n;j++){
            ll k=(i+j)%n;
            ll k_=(i+j-1+n)%n;        
            next[k]=maxm=max(maxm,a[k_]);
        }

        maxm=0;
        for(ll j=1;j<n;j++){
            ll k=(i-j+n)%n;
            prev[k]=maxm=max(maxm,a[k]);
        }

        ll sum=0;
        for(ll j=0;j<n;j++) if(j!=i) sum+=min(next[j],prev[j]);
        ans[i]=sum;
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