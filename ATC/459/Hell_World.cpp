#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    ll n;
    cin>>n;

    n--;
    string s="HelloWorld";
    string ans;
    for(ll i=0;i<10;i++){
        if(i!=n)
            ans+=s[i];
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