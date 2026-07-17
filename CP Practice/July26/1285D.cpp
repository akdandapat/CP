#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

int child[3000005][2];
int rows=1;

void insert(ll x){
    int row=1;

    for(ll i=29;i>=0;i--){
        int bit=(x>>i)&1;

        if(!child[row][bit])
            child[row][bit]=++rows;

        row=child[row][bit];
    }
}

ll dfs(int row,ll bit){
    if(bit<0)
        return 0;

    int left=child[row][0];
    int right=child[row][1];
/*i got it now u mean if i have both the val whether bit i chose for one of them it will be generate 1 at xor..and that will be max so i had to take that
*/
    if(left&&right)
        return (1LL<<bit)+min(dfs(left,bit-1),dfs(right,bit-1));

    if(left)
        return dfs(left,bit-1);

    if(right)
        return dfs(right,bit-1);

    return 0;
}

void solve(){
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        insert(x);
    }

    cout<<dfs(1,29)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}