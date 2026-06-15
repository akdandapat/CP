#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
242
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'


struct Node{
    ll sum;
    ll lzy;
};

vector<Node> tr;

void push(ll u,ll l,ll r){
    if(tr[u].lzy!=-1){
        ll mid=l+(r-l)/2;
        ll val=tr[u].lzy;

        tr[2*u].lzy=val;
        tr[2*u].sum=val*(mid-l+1);

        tr[2*u+1].lzy=val;
        tr[2*u+1].sum=val*(r-mid);

        tr[u].lzy=-1;
    }
}

void upd(ll u,ll l,ll r,ll ql,ll qr,ll val){
    if(ql<=l&&r<=qr){
        tr[u].lzy=val;
        tr[u].sum=val*(r-l+1);
        return;
    }
    push(u,l,r);

    ll mid=l+(r-l)/2;
    if(ql<=mid) upd(2*u,l,mid,ql,qr,val);
    if(qr>mid) upd(2*u+1,mid+1,r,ql,qr,val);

    tr[u].sum=tr[2*u].sum+tr[2*u+1].sum;
}

ll fndz(ll u,ll l,ll r){
    if(l==r) return l;

    push(u,l,r);

    ll mid=l+(r-l)/2;
    ll rlen=r-mid;

    if(tr[2*u+1].sum<rlen)
        return fndz(2*u+1,mid+1,r);

    else
        return fndz(2*u,l,mid);
    
}

ll qry(ll u,ll l,ll r,ll ql,ll qr){
    if(ql>qr) return 0;
    if(ql<=l&&r<=qr) return tr[u].sum;

    push(u,l,r);

    ll mid=l+(r-l)/2;
    ll ans=0;

    if(ql<=mid) ans+=qry(2*u,l,mid,ql,qr);
    if(qr>mid) ans+=qry(2*u+1,mid+1,r,ql,qr);

    return ans;
}

void solve(){
    ll n,q;
    cin>>n>>q;

    tr.assign(4*n+1,{0,-1});

    for(ll i=0;i<q;i++){
        ll tp;
        cin>>tp;

        if(tp==0||tp==1){
            ll l,r;
            cin>>l>>r;
            upd(1,1,n,l,r,tp);
        }

        else if(tp==2){
            ll ones=tr[1].sum;
            ll zros=n-ones;
            if(zros>0) upd(1,1,n,1,zros,0);
            if(ones>0) upd(1,1,n,zros+1,n,1);
        }

        if(tr[1].sum==n)
            cout<<1<<endl;
        else{
            ll lz=fndz(1,1,n);
            ll cnt=qry(1,1,n,1,lz);
            cout<<cnt+1<<endl;
        }
    }
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