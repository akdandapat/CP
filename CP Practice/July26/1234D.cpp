#include<bits/stdc++.h>
using namespace std;
/*
ARPANN
----------------------------
logic is correct but will tle can use bit manipulation as set.size<=26
*/
#define ll long long
#define vll vector<ll>
#define endl '\n'
#define sll set<ll> 

ll merge(const ll &a,const ll &b){
    ll c=0;
    c|=a;
    c|=b;

    return c;
}

void build(ll ind,ll l,ll r,string &s,vll &seg){
    if(l==r){
        seg[ind]=1<<(s[l]-'a');
        return;
    }

    ll mid=(l+r)/2;

    build(2*ind+1,l,mid,s,seg);
    build(2*ind+2,mid+1,r,s,seg);

    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}

void update(ll ind,ll l,ll r,ll pos,char val,vll &seg){
    if(l==r){
        seg[ind]=1<<(val-'a');
        return;
    }

    ll mid=(l+r)/2;

    if(pos<=mid) update(2*ind+1,l,mid,pos,val,seg);
    else update(2*ind+2,mid+1,r,pos,val,seg);

    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}

ll query(ll ind,ll l,ll r,ll ql,ll qr,vll &seg){
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
    string s;
    cin>>s;

    ll n=s.size();
    vll seg(4*n);

    build(0,0,n-1,s,seg);

    ll q;
    cin>>q;

    while(q--){
        ll k;
        cin>>k;

        if(k==2){
            ll l,r;
            cin>>l>>r;
            l--;
            r--;
            
            cout<<__builtin_popcountll(query(0,0,n-1,l,r,seg))<<endl;
        }
        else{
            ll pos;
            char val;
            cin>>pos>>val;
            pos--;

            update(0,0,n-1,pos,val,seg);
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}