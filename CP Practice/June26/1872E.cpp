#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
12:00
------------------------------------------------------------
pref xor properties.....xor is really op....creezy creezy..
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    string s;
    cin>>s;

    ll x0=0,x1=0;
    vll pref=a;

    for(ll i=0;i<n;i++){
        if(s[i]=='1')
            x1^=a[i];
        else
            x0^=a[i];

        if(i>0) pref[i]^=pref[i-1];

    }

    ll q;
    cin>>q;

    while(q--){
        ll k;
        cin>>k;

        if(k==2){
            ll z;
            cin>>z;

            if(z==0) cout<<x0<<" ";
            else cout<<x1<<" ";
        }

        else{
            ll l,r;
            cin>>l>>r;
            l--;r--;

            ll xlr=pref[r];
            if(l>0) xlr^=pref[l-1];

            x0^=xlr;
            x1^=xlr;
        }
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