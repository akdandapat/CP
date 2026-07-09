#include<bits/stdc++.h>
using namespace std;
/*
ARPANN
------------------------------
i understood wrongly needs __gcd
*/
#define ll long long
#define vll vector<ll>
#define endl '\n'
#define arr2 array<ll,2>

arr2 merge(arr2 a,arr2 b){
    arr2 c;
    c[0]=__gcd(a[0],b[0]);
    c[1]=0;

    if(c[0]==a[0]) c[1]+=a[1];
    if(c[0]==b[0]) c[1]+=b[1];

    return c;
}

void build(ll ind,ll l,ll r,vll &a,vector<arr2> &seg){
    if(l==r){
        seg[ind][0]=a[l];
        seg[ind][1]=1;
        return;
    }

    ll mid=(l+r)/2;

    build(2*ind+1,l,mid,a,seg);
    build(2*ind+2,mid+1,r,a,seg);

    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}

arr2 query(ll ind,ll l,ll r,ll ql,ll qr,vector<arr2> &seg){
    if(ql<=l&&r<=qr)
        return seg[ind];

    ll mid=(l+r)/2;

    if(qr<=mid)
        return query(2*ind+1,l,mid,ql,qr,seg);

    if(ql>mid)
        return query(2*ind+2,mid+1,r,ql,qr,seg);

    return merge(
        query(2*ind+1,l,mid,ql,qr,seg),
        query(2*ind+2,mid+1,r,ql,qr,seg)
    );
}

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    vector<arr2> seg(4*n);
    build(0,0,n-1,a,seg);

    ll q;
    cin>>q;

    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        
        auto gcd=query(0,0,n-1,l,r,seg);
        cout<<r-l+1-(gcd[1])<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
