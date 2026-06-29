#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
244A
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll mod=998244353;
ll fact[200001];
ll inv[200001];

ll modpow(ll base,ll exp){
    ll res=1;
    base%=mod;
    while(exp>0){
        if(exp%2==1){
            res=(res*base)%mod;
        }
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}

void precompute(){
    fact[0]=1;
    inv[0]=1;
    for(int i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv[200000]=modpow(fact[200000],mod-2);
    for(int i=199999;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
}

ll ncr(ll n,ll r){
    if(r<0||r>n){
        return 0;
    }
    ll ans=(fact[n]*inv[r])%mod;
    ans=(ans*inv[n-r])%mod;
    return ans;
}

void solve(){
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll k=1;
    for(int i=1;i<n;i++)
        if(s[i]!=s[i-1]) k++;

    ll ans=0;
    for(ll i=0;i<k-1;i++)
        ans=(ans+2*ncr(n-1,i))%mod;

    ans=(ans+ncr(n-1,k-1))%mod;
    ans%=mod;

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;

    precompute();
    
    while(t--)
        solve();

    return 0;
}