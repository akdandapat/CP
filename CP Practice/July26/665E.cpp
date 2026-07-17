#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
------------------------------------------------------------
int array && did bounds lesser...so take care of it
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

int child[30000005][2];
int freq[30000005];
int rows=1;

void insert(ll x){
    int row=1;

    for(ll i=29;i>=0;i--){
        int bit=(x>>i)&1;

        if(!child[row][bit])
            child[row][bit]=++rows;

        row=child[row][bit];
        freq[row]++;
    }
}

ll query(ll x,ll k){
    int row=1;
    ll ans=0;

    for(ll i=29;i>=0;i--){
        if(!row)
            break;

        int bit=(x>>i)&1;
        int flip=bit^1;
        int kbit=(k>>i)&1;

        if(kbit){
            row=child[row][flip];
        }else{
            ans+=freq[child[row][flip]];
            row=child[row][bit];
        }
    }

    if(row)
        ans+=freq[row];

    return ans;
}

void solve(){
    ll n,k;
    cin>>n>>k;

    ll pre=0;
    ll ans=0;

    insert(0);

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;

        pre^=x;
        ans+=query(pre,k);
        insert(pre);
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}