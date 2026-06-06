#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
20:00
---------------
couldnt find out the o(logn).....thought of a tough o(n).....
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    if(n==1){
        cout<<1<<endl;
        return;
    }

    if(n<1000000){
        ll m=(n)/2;
        vll a(m);
        a[0]=1;
        ll sum=1;

        for(ll i=1;i<m;i*=2){
            ll k=0;
            for(ll j=i;j<2*i && j<m;j++){
                if(j<2*i-1) a[j]=a[k++];
                else a[j]=a[k++]+1;
                sum+=a[j];
            }
        }

        cout<< sum+n <<endl;
        return;
    }

    ll ans=0;
    while(n){
        ans+=n;
        n/=2;
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