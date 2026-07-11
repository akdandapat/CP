#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
466a
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vll a(n);

    bool flag=0;
    for(ll &num:a) 
    {
        cin>>num;
        if(num>=0) flag=1;
    }

    cout<<(flag ? "No" : "Yes")<<endl;
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