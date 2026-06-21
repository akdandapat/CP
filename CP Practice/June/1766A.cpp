#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'


void solve(){
    ll n;
    cin>>n;

    vll a;
    for(ll i=1;i<=1000000000;i*=10){
        for(ll j=1;j<10;j++){
            a.push_back(i*j);
        }
    }

    ll ans=0;
    for(ll i=0;i<a.size();i++){
        if(a[i]<=n) ans++;
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

    return 0;
}