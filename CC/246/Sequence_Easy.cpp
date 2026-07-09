#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

const ll mod=998244353;
vll fact(2005),inv(2005);

ll modpow(ll b,ll e){
    ll ans=1;

    while(e){
        if(e&1)
            ans=ans*b%mod;
        b=b*b%mod;
        e>>=1;
    }

    return ans;
}

ll ncr(ll n,ll r){
    if(r<0||r>n)
        return 0;

    return fact[n]*inv[r]%mod*inv[n-r]%mod;
}

void precompute(){
    fact[0]=1;

    for(ll i=1;i<=2004;i++)
        fact[i]=fact[i-1]*i%mod;

    inv[2004]=modpow(fact[2004],mod-2);

    for(ll i=2003;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}

void solve(){
    ll n,k;
    cin>>n>>k;

    ll ans=0;

    for(ll i=0;i<n;i++){
        ll cur=0;

        for(ll j=0;j<=i/k;j++){
            ll val=ncr(n-i+1,j)*ncr(n-j*k,n-i)%mod;

            cur=(j&1 ? (cur-val+mod)%mod : (cur+val)%mod);
        }
        
        cur=cur*fact[i]%mod;
        cur=cur*fact[n-i]%mod;
        ans=(ans+cur)%mod;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    ll t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}