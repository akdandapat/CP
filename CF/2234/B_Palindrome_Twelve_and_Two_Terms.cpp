#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
----------------------
2234
*/

void solve(){
    ll n;
    cin>>n;
    
    ll rem=n%12;
    if(rem!=10){
        cout<<rem<<" "<<n-rem<<endl;
        return;
    }

    if(n==10){
        cout<<-1<<endl;
        return;
    }

    cout<<22<<" "<<n-22<<endl;
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