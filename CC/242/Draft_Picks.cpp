#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
242
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,m;
    cin>>n>>m;

    vll v(n);
    int i=0;
    bool f=0;
    while(m>0){
        v[i]+=m;
        m--;
        if(f==0){
            i++;
            if(i==n){
                f=1;
                i=n-1;
            }
        }

        else{
            i--;
            if(i==-1){
                f=0;
                i=0;
            }
        }
    }

    cout<<max(v[0],v.back())<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}