#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n,x;
    cin>>n>>x;

    vll a(n);
    for(ll &num:a) cin>>num;
    sort(all(a));

    ll total=0;
    ll fst=0;
    for(ll i=0;i<n;i++){
        total+=a[i];
        if(total<=x) fst++;
        else break;
    }

    ll ans=0;
    ll mincost=a[0];
    
    while(fst && mincost<=x){
        ll add=(x-total)/fst;
        ans+=add*fst;
        fst--;
        total-=a[fst];
    }
}

int main(){
    ll t=1;
    cin>>t;

    while(t--)
        solve();
    return 0;

}