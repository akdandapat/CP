#include<bits/stdc++.h>
using namespace std;
/*
ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl '\n'

struct node{
    ll mt,op,cl;
};

node merge(node a,node b){
    node c;
    ll x=min(a.op,b.cl);
    c.mt=a.mt+b.mt+x;
    c.op=a.op+b.op-x;
    c.cl=a.cl+b.cl-x;
    return c;
}

void build(ll ind,ll l,ll r,string &s,vector<node> &seg){
    if(l==r){
        seg[ind].mt=0;
        if(s[l]=='('){
            seg[ind].op=1;
            seg[ind].cl=0;
        }
        else{
            seg[ind].op=0;
            seg[ind].cl=1;
        }
        return;
    }

    ll mid=(l+r)/2;

    build(2*ind+1,l,mid,s,seg);
    build(2*ind+2,mid+1,r,s,seg);

    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}

node query(ll ind,ll l,ll r,ll ql,ll qr,vector<node> &seg){
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
    vector<node> seg(4*n);

    build(0,0,n-1,s,seg);

    ll q;
    cin>>q;

    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;

        cout<<2*query(0,0,n-1,l,r,seg).mt<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}