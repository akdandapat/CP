#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
243
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

const ll MOD=998244353;
vll mob(101);
vector<vll> mat(101,vll(101));

ll pw(ll x,ll y){
    ll ret=1;
    x%=MOD;
    while(y>0){
        if(y&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        y>>=1;
    }
    return ret;
}

ll hcf(ll x,ll y){
    while(y){
        x%=y;
        swap(x,y);
    }
    return x;
}

ll mlt(ll x,ll y){
    if(x==0||y==0) return 0;
    return (x/hcf(x,y))*y;
}

void init(){
    mob[1]=1;
    for(ll p=1;p<=100;++p){
        for(ll q=2*p;q<=100;q+=p){
            mob[q]-=mob[p];
        }
    }
}

void solve(){
    ll sz,lim;
    cin>>sz>>lim;
    
    for(ll p=1;p<=lim;++p){
        for(ll q=1;q<=lim;++q){
            ll lc=mlt(p,q);
            if(lc>lim){
                mat[p][q]=0;
            }
            else{
                ll v1=lim/p;
                ll v2=lim/q;
                ll v3=pw(lim/lc,sz-2);
                mat[p][q]=(((v1*v2)%MOD)*v3)%MOD;
            }
        }
    }
    
    ll ans=0;
    for(ll g1=2;g1<=lim;++g1){
        for(ll g2=2;g2<=lim;++g2){

            if(hcf(g1,g2)==1){
                ll sum=0;

                for(ll r1=1;r1*g1<=lim;++r1){
                    for(ll r2=1;r2*g2<=lim;++r2){

                        if(mob[r1]==0||mob[r2]==0) continue;

                        ll sgn=mob[r1]*mob[r2];
                        ll val=mat[r1*g1][r2*g2];
                        
                        if(sgn==-1) val=(MOD-val)%MOD;
                        sum=(sum+val)%MOD;
                    }
                }
                ans=(ans+sum)%MOD;
            }
        }
    }
    
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    ll t=1;
    cin>>t;
    while(t--)
        solve();

    return 0;
}