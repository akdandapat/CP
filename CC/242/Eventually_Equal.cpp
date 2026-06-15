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
    ll a,b,c;
    cin>>a>>b>>c;

    if(a==b)
        cout<<0<<endl;

    else if(gcd(a,c)==gcd(b,c))
        cout<<1<<endl;

    else if(gcd(a,c+1)==gcd(b,c+1))
        cout<<2<<endl;

    else
        cout<<3<<endl;

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