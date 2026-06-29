#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;

    ll k=n/3;
    ll ans=k*min(3*a,b);

    ll rem=n%3;
    ans+=min(rem*a,b);

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