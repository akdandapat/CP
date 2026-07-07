#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2242
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vll a(n);
    for(ll &num:a) cin>>num;

    vll cnt;
    for(ll i=0;i<n;i++){
        ll temp=1;
        while(i+1<n && a[i]==a[i+1]){
            temp++;
            i++;
        }

        cnt.push_back(temp);
    }

    sort(cnt.begin(),cnt.end());
    int sz=cnt.size();

    vll suff(sz+1);
    for(ll i=sz-1;i>=0;i--) suff[i]=suff[i+1]+cnt[i];

    ll ans=0;
    for(ll i=0;i<sz;i++){
        if(i>0 && cnt[i]==cnt[i-1]) continue;

        ll num=cnt[i],sum=suff[i],rem_blk=sz-i;
        
        ll rem_size=k-sum;
        if(rem_size % rem_blk) continue;

        ll change=rem_size/rem_blk;
        if(num+change>=1) ans++;
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