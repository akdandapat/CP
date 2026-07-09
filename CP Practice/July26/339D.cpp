#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

ll n,m,sz;

void build(ll ind,ll l,ll r,ll lvl,vll &nums,vll &seg){
    if(l==r){
        seg[ind]=nums[l];
        return;
    }

    ll mid=(l+r)/2;
    ll c1=2*ind+1;
    ll c2=2*ind+2;

    build(c1,l,mid,lvl-1,nums,seg);
    build(c2,mid+1,r,lvl-1,nums,seg);

    if(lvl&1) seg[ind]=seg[c1] | seg[c2];
    else seg[ind]=seg[c1] ^ seg[c2];
}

void upd(ll ind,ll l,ll r,ll pos,ll val,ll lvl,vll &seg){
    if(l==r && l==pos){
        seg[ind]=val;
        return;
    }

    ll mid=(l+r)/2;
    ll c1=2*ind+1;
    ll c2=2*ind+2;

    if(pos<=mid) upd(c1,l,mid,pos,val,lvl-1,seg);
    if(pos>mid) upd(c2,mid+1,r,pos,val,lvl-1,seg);

    if(lvl&1) seg[ind]=seg[c1] | seg[c2];
    else seg[ind]=seg[c1] ^ seg[c2];
}

void solve(){
    cin>>n>>m;

    sz=1<<n;

    vll nums(sz);
    for(ll &num:nums) cin>>num;

    vll seg(4*sz);

    build(0,0,sz-1,n,nums,seg);//root level-->n

    while(m--){
        ll p,b;
        cin>>p>>b;

        upd(0,0,sz-1,p-1,b,n,seg);

        cout<<seg[0]<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;
    while(t--) solve();
}

