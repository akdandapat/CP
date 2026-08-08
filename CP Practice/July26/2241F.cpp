#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    string s;
    cin>>n>>s;
    ll ones=0;
    bool f=0;

    for(ll i=0;i<n;i++){
        if(s[i]=='1')
            ones++;
        else{
            if(ones%2!=0){
                f=1;
                break;
            }
        }
    }

    if(!f){
        ll zeros=0;
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='0')
                zeros++;
            else{
                if(zeros%2!=0){
                    f=1;
                    break;
                }
            }
        }
    }

    if(f)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}