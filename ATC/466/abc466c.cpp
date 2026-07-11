#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
466c
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    ll ans=0;
    ll r=1;

    for(ll l=1;l<=n;l++){
        if(r<l)
            r=l;
        while(r<n){
            cout<<"? "<<l<<" "<<r+1<<endl;
            cout.flush();

            string s;
            cin>>s;

            if(s=="Yes")
                r++;
            else
                break;
        }
        ans+=r-l;
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
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