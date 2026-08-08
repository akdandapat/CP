#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n,k;
    string s;

    cin>>n>>k>>s;
    if(2*k>n){
        cout<<-1<<endl;
        return;
    }

    ll ans=0;
    for(ll i=0;i<k;i++) if(s[i]!='R') ans++;
    for(ll i=n-1;i>n-1-k;i--) if(s[i]!='L') ans++;

    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
}