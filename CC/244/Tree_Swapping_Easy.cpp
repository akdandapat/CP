#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
244E
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

const ll mod=998244353;
const ll maxn=5005;

ll fact[maxn],inv[maxn];

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
    for(ll i=1;i<maxn;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv[maxn-1]=modpow(fact[maxn-1],mod-2);
    for(ll i=maxn-2;i>=1;i--){
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

vll adj[maxn];
ll cs[maxn],ct[maxn],cq[maxn];

string S,T;
void dfs(ll u,ll p){
    cs[u]=(S[u]=='1');
    ct[u]=(T[u]=='1');
    cq[u]=(S[u]=='?');
    for(ll v:adj[u]){
        if(v!=p){
            dfs(v,u);
            cs[u]+=cs[v];
            ct[u]+=ct[v];
            cq[u]+=cq[v];
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++) adj[i].clear();

    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>S>>T;
    dfs(0,-1);

    ll k=ct[0]-cs[0];
    ll Q=cq[0];

    if(k<0||k>Q)
        cout<<0<<endl;
    else{
        ll ans=0;
        for(ll i=1;i<n;i++){
            ll qi=cq[i];
            ll qo=Q-qi;
            ll si=cs[i],ti=ct[i];

            for(ll x=0;x<=qi;x++)
                ans=(ans+ncr(qi,x)*ncr(qo,k-x)%mod*abs(si+x-ti))%mod;
        }
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}