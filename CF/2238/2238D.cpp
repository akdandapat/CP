#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
CF 2238D
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll spf[(ll)1e6+5];
void precompute(){
    for(ll i=2;i<=(ll)1e6;i++) spf[i]=i;

    for(ll i=2;i*i<=(ll)1e6;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=1e6;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    ll ans=0,d=0;
    while(n>1){
        d++;
        ll p=spf[n];
        
        while(n%p==0){
            ans++;
            n/=p;
        }
    }
    d--;
    cout<<ans+d<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();

    ll t=1;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}