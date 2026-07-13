#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll i=0;i<n;i++){
        if(i%2==0){
            a[i]=i+2;
        }
        else
            a[i]=i;
    }
    for(ll &num:a) cout<<num<<" ";
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