#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;

    ll nm=0,np=0;
    ll a;
    for(ll i=0;i<n;i++) {
        cin>>a;
        a>0 ? np++ : nm++;
    }

    //no of 1 is more or equal
    //no of -1 is even
    ll ans=0;
    if (nm&1){
        ans++;
        nm--;
        np++;
    }

    if(nm>np){
        ll diff=nm-np+1;
        diff/=2;
        ans+= ((diff&1) ? diff+1 : diff);
    }
    cout<<ans<<endl;

}

int main(){
    ll t=1;
    cin>>t;

    while(t--)
        solve();
    return 0;

}