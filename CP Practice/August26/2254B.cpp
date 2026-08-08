#include<bits/stdc++.h>
using namespace std;

#define  ll long long
#define vll vector<ll>

void solve(){
    ll n;
    string s;
    cin>>n>>s;

    int flag1=0,flag2=0;
    ll ans=0;
    for(ll i=0;i<n;i++){
        char ch=s[i];
        ll j=i;
        while(j<n && s[j]==ch){
            j++;
        }
        ll len=j-i;
        if(i>0 && i<n-1 && len==1){
            flag1=1;
            if(s[i-1]==s[i+1])
                flag2=1;
        }

        ans++;
        i=j-1;
    }

    cout<<ans-(flag1+flag2)<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
}