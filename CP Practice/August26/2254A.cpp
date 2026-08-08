#include<bits/stdc++.h>
using namespace std;

#define  ll long long
#define vll vector<ll>

void solve(){
    vll a(3);
    cin>>a[0]>>a[1]>>a[2];

    sort(a.begin(),a.end());
    cout<<min(a[1]-a[0],a[2]-a[1])<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
}