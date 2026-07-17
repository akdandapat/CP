#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

ll child[4000005][2];
ll freq[4000005];
ll rows=1;

void insert(ll x){
    ll row=1;

    for(ll i=39;i>=0;i--){
        ll bit=(x>>i)&1;

        if(!child[row][bit])
            child[row][bit]=++rows;

        row=child[row][bit];
        freq[row]++;
    }
}

void erase(ll x){
    ll row=1;

    for(ll i=39;i>=0;i--){
        ll bit=(x>>i)&1;
        row=child[row][bit];
        freq[row]--;
    }
}

ll query(ll x){
    ll row=1;
    ll ans=0;

    for(ll i=39;i>=0;i--){
        ll bit=(x>>i)&1;
        ll flip=bit^1;

        if(child[row][flip]&&freq[child[row][flip]]){
            ans|=(1LL<<i);
            row=child[row][flip];
        }
        else
            row=child[row][bit];
    }

    return ans;
}

void solve(){
    ll n;
    cin>>n;

    vll nums(n+1),suf(n+2);

    for(ll i=1;i<=n;i++)
        cin>>nums[i];

    insert(0);

    for(ll i=n;i>=1;i--){
        suf[i]=suf[i+1]^nums[i];
        insert(suf[i]);
    }

    ll pre=0;
    ll ans=0;

    for(ll i=0;i<=n;i++){
        if(i)
            pre^=nums[i];

        ans=max(ans,query(pre));

        if(i<n)
            erase(suf[i+1]);
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}