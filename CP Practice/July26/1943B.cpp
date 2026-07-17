#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
---------------------------------------------------------
damn wa on 150 for the hasing mistake...
pref1[i+1]=(pref1[i]*base+text[i])%mod1;
here (int)text[i]>31...so either base=331 or do text[i]-'a'+1...
these are guesses..actual process is manacher's algo
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll base=331;

vll power1(200005);
vll power2(200005);

void precompute(){
    power1[0]=1;
    power2[0]=1;

    for(ll i=1;i<=200000;i++){
        power1[i]=(power1[i-1]*base)%mod1;
        power2[i]=(power2[i-1]*base)%mod2;
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;

    string text;
    cin>>text;

    vll diff1(n,0);
    for(ll i=1;i<n;i++){
        if(text[i]!=text[i-1])
            diff1[i]=i;
        else
            diff1[i]=diff1[i-1];
    }

    vll diff2(n,0);
    for(ll i=2;i<n;i++){
        if(text[i]!=text[i-2])
            diff2[i]=i;
        else
            diff2[i]=diff2[i-1];
    }

    vll pref1(n+1,0),pref2(n+1,0);
    vll suff1(n+1,0),suff2(n+1,0);

    for(ll i=0;i<n;i++){
        pref1[i+1]=(pref1[i]*base+text[i]-'a'+1)%mod1;
        pref2[i+1]=(pref2[i]*base+text[i]-'a'+1)%mod2;
    }

    for(ll i=n-1;i>=0;i--){
        suff1[i]=(suff1[i+1]*base+text[i]-'a'+1)%mod1;
        suff2[i]=(suff2[i+1]*base+text[i]-'a'+1)%mod2;
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;

        ll sz=r-l+1;

        if(diff1[r]<=l){//every substr is pal
            cout<<0<<endl;
            continue;
        }

        if(diff2[r]<=l+1){//ababab seq...even len....2+4+6+.....
            ll cnt=sz/2;
            cout<<cnt*(cnt+1)<<endl;
            continue;
        }

        ll f1=(((pref1[r+1]-pref1[l]*power1[sz])%mod1)+mod1)%mod1;
        ll f2=(((pref2[r+1]-pref2[l]*power2[sz])%mod2)+mod2)%mod2;

        ll b1=(((suff1[l]-suff1[r+1]*power1[sz])%mod1)+mod1)%mod1;
        ll b2=(((suff2[l]-suff2[r+1]*power2[sz])%mod2)+mod2)%mod2;

        ll ans=sz*(sz+1)/2-1;//k==1 substracted
        cout<<((f1==b1&&f2==b2) ? ans-sz : ans)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    ll t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}