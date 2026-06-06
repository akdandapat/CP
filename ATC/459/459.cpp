#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    ll n;
    cin>>n;

    string ans;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;

        ll d=2;
        if(s[0]=='p' ||s[0]=='q' ||s[0]=='r' || s[0]=='s') d=7;
        else if (s[0]=='t' ||s[0]=='u' ||s[0]=='v') d=8;
        else if (s[0]=='w' ||s[0]=='x' ||s[0]=='y' || s[0]=='z') d=9;
        else d+=(s[0]-'a')/3;

        ans+=to_string(d);
    }

    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;

    while(t--)
        solve();
}