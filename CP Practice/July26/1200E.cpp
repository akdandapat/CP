#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n;
    cin>>n;

    string ans;
    cin>>ans;

    for(ll i=1;i<n;i++){
        string s;
        cin>>s;

        ll len1=ans.size();
        ll len2=s.size();
        ll len=min(len1,len2);

        string cur=s+"#"+ans.substr(len1-len,len);

        ll sz=cur.size();
        vll pi(sz);

        for(ll j=1;j<sz;j++){
            ll k=pi[j-1];

            while(k>0&&cur[j]!=cur[k])
                k=pi[k-1];

            if(cur[j]==cur[k])
                k++;

            pi[j]=k;
        }

        ll match=pi[sz-1];
        ans+=s.substr(match);
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}