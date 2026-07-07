#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vll a(n),pref(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        
        if(a[i]==2) pref[i]=1;
        if(i!=0) pref[i]+=pref[i-1];
    }

    for(ll i=0;i<n-1;i++){
        if(pref[i]==pref[n-1]-pref[i]){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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