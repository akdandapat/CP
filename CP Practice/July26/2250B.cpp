#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,m;
    cin>>n>>m;

    if(m==n-1){
        cout<<-1<<endl;
        return;
    }

    ll b=n-m,o=(n+1)/2,z=n/2;
    ll bo=(b+1)/2,bz=b/2;
    ll ro=o-bo,rz=z-bz;

    string s;

    for(ll i=0;i<b;i++){
        if(i&1){
            s+='0';
            if(i==1)
                while(rz--)
                    s+='0';

        }
        else{
            s+='1';
            if(i==0)
                while(ro--)
                    s+='1';
        }
    }

    cout<<s<<endl;
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