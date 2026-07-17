#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    string s;
    cin>>s;

    ll n=s.size();
    vll pi(n);

    for(ll i=1;i<n;i++){
        ll cur=pi[i-1];
        while(cur>0&&s[i]!=s[cur])
            cur=pi[cur-1];

        if(s[i]==s[cur])
            cur++;
        pi[i]=cur;
    }

    vll cnt(n+1,1);
    for(ll i=n;i>=2;i--)
        cnt[pi[i-1]]+=cnt[i];

    vll ans;
    ll cur=n;
    while(cur>0){
        ans.push_back(cur);
        cur=pi[cur-1];
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<" "<<cnt[ans[i]]<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}