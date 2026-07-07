#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
465c
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    vll a(n);
    ll l=0,r=n-1;
    bool rev=false;

    for(ll i=n;i>=1;i--){
        if(s[i-1]=='o') rev=!rev;
        if(rev){
            a[l]=i;
            l++;
        }
        else{
            a[r]=i;
            r--;
        }
    }

    for(ll i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
        
    return 0;
}
