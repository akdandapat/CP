#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

int f(ll a,ll b,ll c){
    ll diff=llabs(b-c);
    return !(diff&1);
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;

    cout<<f(a,b,c)<<" "<<f(b,a,c)<<" "<<f(c,a,b)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}