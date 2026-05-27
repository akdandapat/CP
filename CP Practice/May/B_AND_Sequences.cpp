#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
00:20
-------
adhoc type...hve to think conditions for possibility of such array.....
starting 1<<40 -1 ....not 1..
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll MOD = 1e9 + 7;
const ll MAXN = 200010;

ll fact[MAXN];
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll nPr(ll n, ll r) {
    if (n < r || r < 0) return 0;
    ll res = fact[n];
    res = (res * modInverse(fact[n - r])) % MOD;
    return res;
}

void init_ncr() {
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    ll allAnd=(1<<40)-1;
    // map<ll,ll>freq;
    for(ll &num:a) {
        cin>>num;
        allAnd &=num;
        // freq[num]++;
    }

    ll f=0;
    for(ll &num:a){
        if(num==allAnd)
            f++;
    }

    if(f<=1){
        cout<<0<<endl;
        return;
    }

    cout<<(nPr(f,2)*fact[n-2])%MOD<<endl;

    // vll pref=a;
    // vll suff=a;

    // for(ll i=1;i<n;i++){
    //     pref[i] &=pref[i-1];
    //     suff[n-1-i] &=suff[n-i];
    // }

    // ll val=-1;
    // for(ll i=0;i<n;i++){
    //     if(i==0){
    //         if(a[0]==suff[1]){
    //             val=a[0];
    //             break;
    //         }
    //     }
    //     else if(i==n-1){
    //         if(pref[n-2]==a[n-1]){
    //             val=a[n-1];
    //             break;
    //         }
    //     }
    //     else if(a[i]==(pref[i-1]&suff[i+1])){
    //         val=a[i];
    //         break;
    //     }
    // }
    //cout<<npr(f,1)*npr(f-1,1)*fact[f-2]%MOD<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_ncr();

    ll t=1;
    cin>>t;

    while(t--)
        solve();
}


