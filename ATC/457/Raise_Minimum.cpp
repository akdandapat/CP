#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

bool f(ll tar,ll k,vector<ll>&a){
    ll see=0;
    ll d=a[0]+k;
    for(ll i=0;i<a.size();i++){
        if(a[i]<tar){
            ll z=(tar-a[i]+i)/(i+1);
            if(see>d-z)// fix2
                return 0;
            see+=z;
        }
    }
    if (see<=k)
        return 1;
    return 0;
}

void solve(){
    ll n,k;
    cin>>n>>k;


    vll a(n);
    for(ll &num:a) cin>>num;

    ll minm=*min_element(a.begin(),a.end());
    ll lo=minm,hi=a[0]+k;//crazzzyyyy

    ll ans=lo;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(f(mid,k,a)){
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}


