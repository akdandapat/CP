#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    ll x,n;
    cin>>x>>n;

    multiset<ll>ms;
    ms.insert(x);

    ll a,b;
    cin>>a>>b;

    ms.insert(a);ms.insert(b);
    auto i=ms.begin();
    i++;
    cout<<*i<<endl;
    for(ll j=1;j<n;j++){
        cin>>a>>b;

        ms.insert(a);
        ms.insert(b);

        if(a>=*i && b>=*i){
            i++;
            cout<<*i<<endl;
        }
        else if(a<*i && b<*i){
            i--;
            cout<<*i<<endl;
        }
        else if(max(a,b)>=*i && *i>min(a,b)){
            cout<<*i<<endl;
        }

    }
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