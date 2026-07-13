#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll suf[20][100100];
void precompute(){
    for(ll i=0;i<=18;i++){
        ll lim=100000+(1LL<<i);
        lim>>=i;
        lim+=50;

        for(ll j=1;j<=lim;j++){
            ll num=j*(1LL<<i);
            num+=__builtin_popcountll(j)-1;
            num+=32-__builtin_clz(j);
            suf[i][j]=num;
        }

        for(ll j=lim-1;j>=1;j--)
            suf[i][j]=min(suf[i][j],suf[i][j+1]);
    }
}

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    ll sum=0;
    for(ll &num:a){
        cin>>num;
        sum+=num;
    }

    ll ans=1e8;
    for(ll i=0;i<=18;i++){
        ll cur=i-sum;
        for(ll j=0;j<n;j++){
            ll d=a[j]+(1LL<<i)-1;
            d>>=i;
            cur+=suf[i][d];
        }
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
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