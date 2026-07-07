#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
465a
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll a,b;
    cin>>a>>b;

    if(3*a>2*b){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
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