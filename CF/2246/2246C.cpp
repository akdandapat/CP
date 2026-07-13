#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'
const ll mod=1e9+7;

ll modpow(ll b,ll e){
    ll ans=1;
    b%=mod;
    while(e){
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;

    ll neg=0,pos=0;
    set<ll>st;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;

        if(x==-1)
            neg++;
        else{
            pos++;
            st.insert(x);
        }
    }

    ll k=0;
    for(auto it=st.begin();it!=st.end();it++){
        auto nxt=it;
        nxt++;
        if(nxt!=st.end() && *nxt==*it+1)
            k++;
    }

    ll even=1,odd=0;
    if(neg){
        even=modpow(2,neg-1);
        odd=modpow(2,neg-1);
    }

    ll paths=modpow(2,pos-(ll)st.size());
    cout<<(((even+(k*odd)%mod)%mod)*paths)%mod<<endl;
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