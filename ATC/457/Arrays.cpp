#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    ll n;
    cin>>n;

    vector<vll> a;
    for(ll i=0;i<n;i++) {
        ll s;
        cin>>s;

        vll temp(s);
        for(ll j=0;j<s;j++)
            cin>>temp[j];
        
        a.push_back(temp);
    }

    ll x,y;
    cin>>x>>y;
    x--;y--;

    cout<<a[x][y]<<endl;
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