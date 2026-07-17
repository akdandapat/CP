#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
-----------------------------------------
needs double hashing...
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll base=31;

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<array<ll,2>> hashs;

    vll pow1(600005),pow2(600005);
    pow1[0]=1;
    pow2[0]=1;

    for(ll i=1;i<=600000;i++){
        pow1[i]=(pow1[i-1]*base)%mod1;
        pow2[i]=(pow2[i-1]*base)%mod2;
    }

    for(ll i=0;i<n;i++){
        string s;
        cin>>s;

        ll hash1=0,hash2=0;

        for(ll j=0;j<s.size();j++){
            hash1=(hash1*base+(s[j]-'a'+1))%mod1;
            hash2=(hash2*base+(s[j]-'a'+1))%mod2;
        }

        hashs.push_back({hash1,hash2});
    }

    sort(hashs.begin(),hashs.end());

    for(ll i=0;i<m;i++){
        string s;
        cin>>s;

        ll hash1=0,hash2=0;
        ll len=s.size();

        for(ll j=0;j<len;j++){
            hash1=(hash1*base+(s[j]-'a'+1))%mod1;
            hash2=(hash2*base+(s[j]-'a'+1))%mod2;
        }

        bool ok=false;

        for(ll j=0;j<len;j++){
            for(char c='a';c<='c';c++){
                if(c==s[j])
                    continue;

                ll diff1=(c-s[j]+mod1)%mod1;
                ll diff2=(c-s[j]+mod2)%mod2;

                ll new1=(hash1+diff1*pow1[len-1-j])%mod1;
                ll new2=(hash2+diff2*pow2[len-1-j])%mod2;

                if(binary_search(hashs.begin(),hashs.end(),array<ll,2>{new1,new2})){
                    ok=true;
                    break;
                }
            }

            if(ok)
                break;
        }

        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}