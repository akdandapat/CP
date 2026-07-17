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
        ll j=pi[i-1];

        while(j>0&&s[i]!=s[j])
            j=pi[j-1];

        if(s[i]==s[j])
            j++;

        pi[i]=j;
    }

    ll maxm=0;
    for(ll i=1;i<n-1;i++)
        maxm=max(maxm,pi[i]);

    ll len=pi[n-1];

    if(len==0)
        cout<<"Just a legend"<<endl;

    else if(len<=maxm)
        cout<<s.substr(0,len)<<endl;

    else{
        ll len1=pi[len-1];
        if(len1>0)
            cout<<s.substr(0,len1)<<endl;
        else
            cout<<"Just a legend"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}