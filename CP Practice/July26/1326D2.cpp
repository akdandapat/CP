#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    string text;
    cin>>text;

    ll n=text.size();
    ll k=0;
    while(k<n-1-k&&text[k]==text[n-1-k])
        k++;

    if(k>=n-1-k){
        cout<<text<<endl;
        return;
    }

    string str="#";
    for(ll i=0;i<n;i++){
        str+=text[i];
        str+="#";
    }

    ll m=str.size();
    vll len(m,0);
    ll cen=0;
    ll r=0;

    for(ll i=0;i<m;i++){
        if(i<r)
            len[i]=min(r-i,len[2*cen-i]);

        while(i-len[i]-1>=0&&i+len[i]+1<m&&str[i-len[i]-1]==str[i+len[i]+1])
            len[i]++;

        if(i+len[i]>r){
            cen=i;
            r=i+len[i];
        }
    }

    ll maxm=0;
    bool pref=true;

    ll l=2*k;
    ll rr=2*(n-k);

    for(ll i=l+1;i<rr;i++){
        if(len[i]>=i-l && (i + (i-l) <= rr)){
            ll cur=i-l;
            if(cur>maxm){
                maxm=cur;
                pref=true;
            }
        }
            //yvaamavy
        if(len[i]>=rr-i && (i - (rr-i) >= l)){
            ll cur=rr-i;
            if(cur>maxm){
                maxm=cur;
                pref=false;
            }
        }
    }

    string ans=text.substr(0,k);

    if(pref)
        ans+=text.substr(k,maxm);
    else
        ans+=text.substr(n-k-maxm,maxm);

    ans+=text.substr(n-k);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}