#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
12:45
----------------------
will get 3 val from 2 qr...
*/

ll qu(ll a,ll b){
    cout<<'?'<<" "<<a<<" "<<b<<endl;
    cout.flush();

    ll val;cin>>val;
    return val;
}

void f(vll &nums,vll &ans, ll mul,ll p,ll q,ll r){
    ll a=qu(p,q);
    ll b=qu(q,r);

    for(ll i=0;i<6;i++){
        for(ll j=0;j<6;j++){
            ll x=((nums[i]*mul)/nums[j]);
            if(x==(a*mul)/b){
                if(a%nums[i]==0 && count(nums.begin(),nums.end(),a/nums[i])){
                    if(nums[i]!=a/nums[i] && a/nums[i]!=nums[j]){
                        ans[p-1]=nums[i];
                        ans[q-1]=a/nums[i];
                        ans[r-1]=nums[j];
                    }
                }
            }
        }
    }
}

void solve(){
    vll temp={4,8,15,16,23,42};
    ll mul=4ll*8*15*16*23*42;

    vll ans(6);
    f(temp,ans,mul,1,2,3);

    f(temp,ans,mul,4,5,6);

    cout<<'!'<<" ";
    for(ll &num:ans) cout<<num<<" ";
    cout<<endl;
    cout.flush();

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