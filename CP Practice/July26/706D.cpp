#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
-----------------------------
nodes ≤ [1 + 30 × (200000 + 1) = 6000031]
*/

#define ll long long
#define endl '\n'

ll child[6400005][2];
ll freq[6400005];
ll row=2;

void insert(ll x){
    ll node=1;

    for(ll i=29;i>=0;i--){
        ll bit=(x>>i)&1;

        if(!child[node][bit])
            child[node][bit]=row++;

        node=child[node][bit];
        freq[node]++;
    }
}

void erase(ll x){
    ll node=1;

    for(ll i=29;i>=0;i--){
        ll bit=(x>>i)&1;
        node=child[node][bit];
        freq[node]--;
    }
}

ll query(ll x){
    ll node=1;
    ll ans=0;

    for(ll i=29;i>=0;i--){
        ll bit=(x>>i)&1;
        ll flip=bit^1;

        if(child[node][flip]&&freq[child[node][flip]]){
            ans|=(1LL<<i);
            node=child[node][flip];
        }else{
            node=child[node][bit];
        }
    }

    return ans;
}

void solve(){
    ll q;
    cin>>q;

    insert(0);

    while(q--){
        char ch;
        ll x;
        cin>>ch>>x;

        if(ch=='+')
            insert(x);
        else if(ch=='-')
            erase(x);
        else
            cout<<query(x)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}