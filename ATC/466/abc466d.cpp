#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
466d
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<array<ll,2>> queries(m);
    for(ll i=0;i<m;i++){
        cin>>queries[i][0]>>queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
    }

    vector<bool> row(n),col(n);
    ll ans=0;
    for(ll i=m-1;i>=0;i--){
        if(!row[queries[i][0]]&&!col[queries[i][1]])
            ans++;

        row[queries[i][0]]=1;
        col[queries[i][1]]=1;
    }
    cout<<ans<<endl;
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