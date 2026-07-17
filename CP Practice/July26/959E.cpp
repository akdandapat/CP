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

    ll ans=0;
    ll curr=1;
    ll rem=n-1;

    while(rem>0){
        ans+=((rem+1)/2)*curr;
        rem/=2;
        curr*=2;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}