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
    string text;
    cin>>n>>text;

    if(n%2){
        cout<<0<<endl;
        return;
    }

    ll sum=0,minm=0;
    vll pref(n);

    for(ll i=0;i<n;i++){
        sum+=text[i]=='(' ? 1 : -1;
        pref[i]=sum;
        minm=min(minm,sum);
    }

    if(sum==2){
        if(minm<0){
            cout<<0<<endl;
            return;
        }

        ll idx=-1;
        for(ll i=n-1;i>=0;i--){
            if(pref[i]<2){
                idx=i;
                break;
            }
        }

        ll ans=0;
        for(ll i=idx+1;i<n;i++)
            ans+=text[i]=='(';

        cout<<ans<<endl;
        return;
    }

    if(sum==-2){
        if(minm<-2){
            cout<<0<<endl;
            return;
        }

        ll idx=n-1;
        for(ll i=0;i<n;i++){
            if(pref[i]<0){
                idx=i;
                break;
            }
        }

        ll ans=0;
        for(ll i=0;i<=idx;i++)
            ans+=text[i]==')';

        cout<<ans<<endl;
        return;
    }

    cout<<0<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}