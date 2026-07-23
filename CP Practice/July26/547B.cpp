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

    vll nums(n);
    for(ll &num:nums) cin>>num;

    vll left(n),right(n);
    stack<ll> st;

    for(ll i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();
        
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(ll i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();
        
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }

    vll ans(n+1);
    for(ll i=0;i<n;i++){
        ll win=right[i]-left[i]-1;
        ans[win]=max(ans[win],nums[i]);
    }

    for(ll i=n-1;i>=1;i--)
        ans[i]=max(ans[i],ans[i+1]);

    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}