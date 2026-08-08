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

    string s;
    cin>>s;

    vll nums(n),cost(n);

    for(ll &num:nums){
        cin>>num;
    }

    for(ll &num:cost){
        cin>>num;
    }

    ll inf=2e18;

    vll pref(n,inf);
    pref[0]=cost[0];

    for(ll i=1;i<n;i++){
        if(cost[i]>cost[i-1]){
            pref[i]=cost[i];
        }
    }

    ll left=0;
    bool ok=true;

    while(left<n){
        ll right=left;

        while(right+1<n&&s[right+1]=='1'){
            right++;
        }

        vll prefsum(right-left+1);

        for(ll i=1;i<=right-left;i++){
            prefsum[i]=prefsum[i-1]+nums[left+i];
        }

        ll base=inf;

        for(ll i=0;i<=right-left;i++){
            if(pref[left+i]!=inf){
                ll curr=pref[left+i]-prefsum[i];
                if(base!=inf&&base!=curr){
                    ok=false;
                }
                base=curr;
            }
        }

        if(base==inf){
            for(ll i=0;i<=right-left;i++){
                base=min(base,cost[left+i]-prefsum[i]);
            }
        }

        for(ll i=0;i<=right-left;i++){
            pref[left+i]=base+prefsum[i];
        }

        left=right+1;
    }

    if(!ok){
        cout<<"No"<<endl;
        return;
    }

    ll curr=pref[0];

    for(ll i=1;i<n;i++){
        curr=max(curr,pref[i]);
        if(curr!=cost[i]){
            ok=false;
        }
    }

    vll ans(n);
    ans[0]=pref[0];

    for(ll i=1;i<n;i++){
        ans[i]=pref[i]-pref[i-1];
    }

    for(ll i=0;i<n;i++){
        if(s[i]=='1'&&ans[i]!=nums[i]){
            ok=false;
        }
    }

    if(!ok){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
        for(ll num:ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}