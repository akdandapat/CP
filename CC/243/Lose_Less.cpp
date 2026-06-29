#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
-------------
243
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll m,n;
    cin>>m>>n;

    ll und=0;
    while(n>m){
        und++;
        m--;
        n-=3;
    }

    und+=n;

    cout<<m-n<<endl;
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