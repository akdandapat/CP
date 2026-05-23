#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
21:15
-------
easy igg
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll n0=0;
    for(char ch:s) if(ch=='0') n0++;

    cout<<((n0%2==0 || n0==1) ?  "BOB" : "ALICE")<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;

    while(t--)
        solve();
}