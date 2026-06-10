#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
12:00
---------------------- 
two pointer ig....will try to take down largests in one shot...
no then i get it doesnt need simulation can be done in one shot with prefix sum...
*/

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    sort(a.begin(),a.end());
    vll pref=a;
    for(ll i=1;i<n;i++) pref[i]+=pref[i-1];

    ll mid=(pref[n-1]+1)/2;

    ll ans;
    for(ll i=0;i<n;i++){
        if(pref[i]>mid){
            ans=n-i+mid;
            break;
        }
        else if(pref[i]==mid){
            ans=n-i-1+mid;
            break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;
    while(t--)
        solve();

    return 0;
}