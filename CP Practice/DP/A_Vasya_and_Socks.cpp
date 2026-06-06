#include<bits/stdc++.h>
using namespace std;

/*

Author: ARPANN
00:45
-------------------------
cant math...simulation ig

*/

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define MOD 998244353

void solve(){
    ll n,m;
    cin>>n>>m;

    ll extra=0;
    ll tot=n;
    while(tot>=m){
        extra+=(tot/m);
        tot=(tot%m)+(tot/m);
    }

    cout<<n+extra<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;

    while(t--)
        solve();
}