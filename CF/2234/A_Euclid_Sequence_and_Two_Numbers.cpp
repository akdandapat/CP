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
    
    vll a(n);
    for(ll &num:a) cin>>num;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    
    if(n==2){
        cout<<a[0]<<" "<<a[1]<<endl;
        return;
    }

    for(ll i=2;i<n;i++){
        if(a[i]!=(a[i-2]%a[i-1])){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<a[0]<<" "<<a[1]<<endl;
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