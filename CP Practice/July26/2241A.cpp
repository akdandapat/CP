#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll x,y;
    cin>>x>>y;

    if(x%y){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
}