#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl '\n'

ll child[9000005][2];
ll freq[9000005];

ll rows=1;
void insert(ll x){
    ll row=1;

    for(ll i=29;i>=0;i--){
        ll bit=(x>>i)&1;

        if(!child[row][bit])
            child[row][bit]=++rows;

        row=child[row][bit];
        freq[row]++;
    }
}

ll getMin(ll x){
    ll node=1;
    ll ans=0;

    for(ll i=29;i>=0;i--){
        ll bit=(x>>i)&1;

        if(child[node][bit]&&freq[child[node][bit]])
            node=child[node][bit];
        else{
            ans|=(1LL<<i);
            node=child[node][bit^1];
        }

        freq[node]--;
    }

    return ans;
}

void solve(){
    ll n;
    cin>>n;

    vll nums(n),nums1(n);

    for(ll i=0;i<n;i++)
        cin>>nums[i];

    for(ll i=0;i<n;i++){
        cin>>nums1[i];
        insert(nums1[i]);
    }

    for(ll i=0;i<n;i++)
        cout<<getMin(nums[i])<<" ";

    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}