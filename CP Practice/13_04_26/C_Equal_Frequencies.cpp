#include<bits/stdc++.h>
using namespace std;

/*
author:ARPANN
start:13/4/26 17:27
end:
*/
#define ll long long
#define vll vector<ll>
#define sort_(v) sort(v.begin(),v.end(),greater<>())

void solve(){
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    vll freq(26);
    vll v=freq;
    for(ll i=0;i<n;i++) freq[s[i]-'a']++;
    sort_(freq);
    
    ll m=0;//no of distinct alphabet
    for(ll i=0;i<n && freq[i];i++) m++;
    
    ll ans=1e9;
    ll f_i=-1;
    ll f_j=-1;

    
    for(ll i=min(1LL,1+(n-1)/26);i<=n;i++){
        ll change=1e12;
        if(n%i)
            continue;
        
        ll ans_m=n/i;
        if(ans_m>m){
            change=n-i*m;
            ans=min(ans,change);
            continue;
        }
        
        ll diff=0;
        for(ll j=0;j<m;j++){
            if(freq[j]<=i)
                diff+=(i-freq[j]);
            
            if(j>=ans_m-1){
                
                if(ans>diff){
                    ans=diff;
                    f_i=i;
                    f_j=j;
                }
                
                if(freq[j-(ans_m-1)]<=i)
                    diff-=(i-freq[j-(ans_m-1)]);
            }
        }
        

    }
    
    cout<<ans<<endl;
    ll f_m=n/f_i;
    
    vector<pair<ll,ll>>vp(26);
    for(ll i=0;i<26;i++) vp.push_back({freq[i],i});
    sort_(vp);
    
    multiset<ll>in,out;
    for(ll i=f_j-(f_m-1))
    
}

int main(){
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}