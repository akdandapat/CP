#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
--------------------------
kinda same like prev
tle for const ig..
precomp wll mle
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll base=331;

void solve(){
    string text;
    cin>>text;

    ll n=text.size();
    ll f1=0,b1=0,p1=1;
    ll f2=0,b2=0,p2=1;

    vll kpal(n,0);
    ll ans=0;

    for(ll i=0;i<n;i++){
        f1=(f1*base+text[i])%mod1;
        b1=(b1+(text[i])*p1)%mod1;
        p1=(p1*base)%mod1;

        f2=(f2*base+text[i])%mod2;
        b2=(b2+(text[i])*p2)%mod2;
        p2=(p2*base)%mod2;

        if(f1==b1&&f2==b2){
            kpal[i]=1;
            if(i){
                kpal[i]=kpal[(i+1)/2-1]+1;
            }
        }
    }
    cout<<accumulate(kpal.begin(),kpal.end(),0ll)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}