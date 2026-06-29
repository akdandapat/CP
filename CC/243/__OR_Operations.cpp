#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
243
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    
    vll a(n);
    ll tot=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        tot|=a[i];
    }
    
    ll cnt=0,cur=0;
    for(ll i=0;i<n;i++){
        cur|=a[i];
        if(cur==tot){
            cur=0;
            continue;
        }
        cnt++;
    }
    
    cout<<cnt<<endl;
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