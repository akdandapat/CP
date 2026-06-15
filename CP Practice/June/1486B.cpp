#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
13:45
------------------------------------------------------------
manhattan dist---->median
for evens the total range between medians inclding them
*/

void solve(){
    ll n;
    cin>>n;

    vll x(n),y(n);
    for(ll i=0;i<n;i++) cin>>x[i]>>y[i];

    if(n&1) {
        cout<<1<<endl;
        return;
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    ll diffx=x[n/2]-x[n/2-1]+1;
    ll diffy=y[n/2]-y[n/2-1]+1;

    cout<<diffx*diffy<<endl;
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