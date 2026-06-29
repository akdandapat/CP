#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
CF 2238A
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,c;
    cin>>n>>c;

    vll a(n),b(n);
    for(ll &num:a) cin>>num;
    for(ll &num:b) cin>>num;

    ll diff=accumulate(a.begin(),a.end(),0LL)-accumulate(b.begin(),b.end(),0LL);


    bool f=1;
    for(ll i=0;i<n;i++){
        if(a[i]<b[i]){
            f=0;
            break;
        }
    }

    if(f==1){
        cout<<diff<<endl;
        return;
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    f=1;
    for(ll i=0;i<n;i++){
        if(a[i]<b[i]){
            f=0;
            break;
        }
    }

    if(f==1){
        cout<<diff+c<<endl;
    }
    else cout<<-1<<endl;
    
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