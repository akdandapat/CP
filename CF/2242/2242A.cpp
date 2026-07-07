#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2242
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    ll b=0;
    ll c=0;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;

        if(a>1) b++;
        if(a>2) c=1;
    }

    if(c || b>1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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