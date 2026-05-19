#include<bits/stdc++.h>
using namespace std;

/*
author:ARPANN
start:13/4/26 17:27
end: 15/4/26 03:06
*/
#define ll long long
#define vll vector<ll>
#define sort_(v) sort(v.begin(),v.end(),greater<>())
#define ff first
#define ss second

void solve(){
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    vll freq(26);
    
    for(ll i=0;i<n;i++) freq[s[i]-'a']++;
    vll v=freq;
    
    sort_(freq);
    
    ll m=0;//no of distinct alphabet
    for(ll i=0;i<26 && freq[i];i++) m++;
    
    ll ans=1e9;
    ll f_i=-1;
    
    for(ll i=1+(n-1)/26;i<=n;i++){
        if(n%i)
            continue;
        
        ll ans_m=n/i;
        ll diff=0;
        
        if(ans_m>m){
            // if(ans>(n-i*m)){
            //     ans=n-i*m;
            //     f_i=i;
            // }
            // ans=min(ans,n-i*m);
            // f_i=i;//missed it
            //continue;
            for(ll j=0;j<m;j++)
                if(freq[j]>=i)
                    diff+=(freq[j]-i);
        }
        
        else{
            for(ll j=0;j<ans_m;j++)
                if(freq[j]<=i)
                    diff+=(i-freq[j]);
        }
            
        if(ans>diff){
            ans=diff;
            f_i=i;
        }
        
    }
    
    cout<<ans<<endl;
    ll f_m=n/f_i;
    
    vector<vector<ll>>vp(26,vll(2));
    for(ll i=0;i<26;i++) vp[i]={v[i],i};
    sort_(vp);
    // for(ll i=0;i<26;i++) cout<<vp[i][0]<<" "<<vp[i][1]<<endl;
    // return;
    
    multiset<char>in;
    map<char,ll>out;
    
    // cout<<out['l'];
    // return;
    
    // cout<<m<<" "<<f_i;
    // return;
    
    if(f_m>m){
        //cout<<out['l'];return;
        for(ll i=0;i<m;i++){
            if(vp[i][0]>f_i){
                out['a'+vp[i][1]]+=vp[i][0]-f_i;
            }
            else{
                for(ll j=0;j<(f_i-vp[i][0]);j++){
                    in.insert('a'+vp[i][1]);
                }
            }
        }
        //cout<<f_i<<" "<<m<<" "<<f_m;return;
        
        for(ll i=0;i<26;i++){
            if(v[i]==0 && m<f_m){
                m++;
                for(ll j=0;j<f_i;j++){
                    in.insert('a'+i);
                }
            }
        }
    
        //cout<<m<<" "<<f_m;return;
        //cout<<out['x']<<" "<<out['o'];return;
        //cout<<*in.begin()<<" "<<*in.rbegin();return;
    }

    
    else{
        for(ll i=0;i<f_m;i++){
            if(vp[i][0]>f_i){
                out['a'+vp[i][1]]+=vp[i][0]-f_i;
            }
            else{
                    //cout<<"YOO";return;
                for(ll j=0;j<(f_i-vp[i][0]);j++){
                    in.insert('a'+vp[i][1]);
                    // cout<<"YOO";return;
                }
            }
        }
        
        for(ll i=f_m;i<m;i++){
            out['a'+vp[i][1]]=vp[i][0];
        }
        
        //cout<<out['i']<<" "<<out['f']<<" "<<out['r']<<" "<<out['s'];
    //     cout<<f_m<<" : "<<in.size();
    //return;
    }
    
    
    auto it=in.begin();
    
    for(ll i=0;i<n;i++){
        if(out.count(s[i])){
            if(out[s[i]]>0){
                out[s[i]]--;
                s[i]=*it;
                it++;
            }
        }
    }
    //sort(s.begin(),s.end());
    cout<<s<<endl;
    
}

int main(){
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}