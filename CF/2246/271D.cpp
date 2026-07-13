#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
-------------------------------
always use vector bruhh :))
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll base=31;

void solve(){
    string s,good;
    cin>>s>>good;

    ll k;
    cin>>k;
    ll n=s.size();

    vector<array<ll,2>>nums;
    for(ll i=0;i<n;i++){
        ll bad=0;
        ll hash1=0;
        ll hash2=0;

        for(ll j=i;j<n;j++){
            if(good[s[j]-'a']=='0')
                bad++;
            if(bad>k)
                break;

            hash1=(hash1*base+s[j]-'a'+1)%mod1;
            hash2=(hash2*base+s[j]-'a'+1)%mod2;
            nums.push_back({hash1,hash2});
        }
    }

    sort(nums.begin(),nums.end());
    ll ans=1;
    for(ll i=1;i<nums.size();i++)
        if(nums[i]!=nums[i-1])
            ans++;

    if(nums.empty())
        ans=0;

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}