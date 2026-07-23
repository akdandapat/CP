#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    cin>>n;

    vll nums(n),prf(n+1);
    vector<array<ll,2>> vals(n);

    for(ll i=0;i<n;i++){
        cin>>nums[i];
        prf[i+1]=prf[i]+nums[i];
        vals[i]={nums[i],i};
    }

    sort(vals.begin(),vals.end());

    vll par(n),minm(n),maxm(n),vis(n);

    for(ll i=0;i<n;i++){
        par[i]=i;
        minm[i]=prf[i];
        maxm[i]=prf[i+1];
    }

    auto find=[&](auto& slf,ll x)->ll{
        if(par[x]==x){
            return x;
        }
        return par[x]=slf(slf,par[x]);
    };
    
    bool ok=true;

    for(ll i=0;i<n;i++){
        ll idx=vals[i][1];

        ll left=prf[idx];
        if(idx>0&&vis[idx-1]){
            ll root=find(find,idx-1);
            left=min(left,minm[root]);
        }

        ll right=prf[idx+1];
        if(idx+1<n&&vis[idx+1]){
            ll root=find(find,idx+1);
            right=max(right,maxm[root]);
        }

        if(right-left>nums[idx]){
            ok=false;
            break;
        }

        vis[idx]=1;

        if(idx>0&&vis[idx-1]){
            ll root=find(find,idx-1);
            par[root]=idx;
            minm[idx]=min(minm[idx],minm[root]);
            maxm[idx]=max(maxm[idx],maxm[root]);
        }

        if(idx+1<n&&vis[idx+1]){
            ll root=find(find,idx+1);
            par[root]=idx;
            minm[idx]=min(minm[idx],minm[root]);
            maxm[idx]=max(maxm[idx],maxm[root]);
        }
    }

    cout<<(ok?"YES":"NO")<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}