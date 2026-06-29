#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
244
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    string a,b;
    cin>>a>>b;

    string u="",v="";
    u+=a[0];

    for(ll i=1;i<n;i++)
        if(a[i]!=a[i-1])
            u+=a[i];
        
    v+=b[0];
    for(ll i=1;i<n;i++)
        if(b[i]!=b[i-1])
            v+=b[i];
            
    ll sa=u.size(),sb=v.size();

    if(u[0]!=v[0]){
        cout<<(sb+1<=sa ? "YES" : "NO")<<endl;
        return;
    }

    cout<<(sb>sa ? "NO" : "YES")<<endl;
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