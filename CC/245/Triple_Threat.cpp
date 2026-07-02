#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
245C
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,x;
    cin>>n>>x;

    ll z=3*n-x;

    string ans(3*n,'-1');
    for(int i=0;i<n;i++){
        if(z) {
            ans[i]='0';
            z--;
        }
        else ans[i]='1';

        if(z) {
            ans[i+n]='0';
            z--;
        }
        else ans[i+n]='1';
    }

    for(ll i=2*n;i<3*n;i++){
        if(z) {
            ans[i]='0';
            z--;
        }

        else ans[i]='1';
    }

    cout<<ans<<endl;
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