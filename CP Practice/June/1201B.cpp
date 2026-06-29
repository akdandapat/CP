#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

/*
------
hukk....ki sob greedy 
------
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    ll tot=0;
    for(ll &num:a) {
        cin>>num;
        tot+=num;
    }

    sort(a.begin(),a.end());
    
    if(tot&1) cout<<"NO"<<endl;
    else if(tot-a.back()<a.back()) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}