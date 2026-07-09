#include<bits/stdc++.h>
using namespace std;
/*
ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl '\n'

void build(ll ind,ll l,ll r,vll &arr,vll &seg){
    if(l==r){
        seg[ind]=arr[l];
        return;
    }

    ll mid=(l+r)/2;

    build(2*ind+1,l,mid,arr,seg);
    build(2*ind+2,mid+1,r,arr,seg);

    seg[ind]=seg[2*ind+1]&seg[2*ind+2];
}

ll query(ll ind,ll l,ll r,ll ql,ll qr,vll &seg){
    if(ql<=l&&r<=qr)
        return seg[ind];

    ll mid=(l+r)/2;

    if(qr<=mid)
        return query(2*ind+1,l,mid,ql,qr,seg);

    if(ql>mid)
        return query(2*ind+2,mid+1,r,ql,qr,seg);

    return query(2*ind+1,l,mid,ql,qr,seg)& query(2*ind+2,mid+1,r,ql,qr,seg);
}

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<array<ll,3>> queries(m);
    vector<vll> diff(30,vll(n+2));

    for(ll i=0;i<m;i++){
        cin>>queries[i][0]>>queries[i][1]>>queries[i][2];

        for(ll j=0;j<30;j++){
            if((queries[i][2]>>j)&1){
                diff[j][queries[i][0]]++;
                diff[j][queries[i][1]+1]--;
            }
        }
    }

    vll arr(n+1);

    for(ll i=0;i<30;i++){
        ll cur=0;

        for(ll j=1;j<=n;j++){
            cur+=diff[i][j];

            if(cur)
                arr[j]|=(1LL<<i);
        }
    }

    vll seg(4*(n+1));

    build(0,1,n,arr,seg);

    for(ll i=0;i<m;i++){
        if(query(0,1,n,queries[i][0],queries[i][1],seg)!=queries[i][2]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

    for(ll i=1;i<=n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}