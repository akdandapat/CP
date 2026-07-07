#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    cin>>n;

    vll a(n),b(n);
    for(ll &num:a) cin>>num;
    for(ll &num:b) cin>>num;

    //0=d*a[i]+b[i]------>d=-(b[i]/a[i]);
    // maxd=1e9 mind=-1e9.......one thing a[i] cant be 0 here
    //if a[i]==0 we will just continue....at laast we will see how many ai bi both 0 pairs are there

    // also while dividing if b[i]%a[i]!=0 we will continue then also........................nooooooooo...d can be any real number...

    //actually d can be 0 right
    
    ll extra=0;
    map<pair<ll,ll>,ll>freq;
    for(ll i=0;i<n;i++){
        if(a[i]==0 && b[i]==0) extra++;
        else if(a[i]==0) continue;
        else{
            if(b[i]==0) freq[{0,0}]++;
            ll gcdd=__gcd(a[i],b[i]);
            freq[{a[i]/gcdd,b[i]/gcdd}]++;
        }
    }

    ll ans=0;
    for(auto &[a,b]:freq){
        ans=max(ans,b);
    }
    
    cout<<ans+extra<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}