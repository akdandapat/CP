#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/
ll ans=0;
set<string>se;

void f(ll a,ll b,ll c,ll last){
    if(a<0 || b<0 || c<0)
        return;

    if(a==0 && b==0 && c==0){
        ans++;
        ans=ans%998244353;
        return;
    }

    // string s;
    // s+=to_string(a)+"#"+to_string(b)+"#"+to_string(c)+"#"+to_string(last);

    // if(se.count(s))
    //     return;
    // se.insert(s);

    if(last==2){
        f(a-1,b,c,1);
        f(a,b,c-1,3);
        f(a,b-1,c,2);
    }

    else if(last==1){
        f(a-1,b,c,1);
        f(a,b-1,c,2);
    }

    else if(last==3){
        f(a,b,c-1,3);
        f(a,b-1,c,2);
    }
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    f(a,b,c,2);
    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}