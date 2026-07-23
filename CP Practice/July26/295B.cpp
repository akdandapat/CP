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
    vector<vll> dist(n+1,vll(n+1));

    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>dist[i][j];

    vll order(n+1);
    for(ll i=1;i<=n;i++)
        cin>>order[i];

    vll ans(n+1);
    vector<bool> vis(n+1);

    for(ll k=n;k>=1;k--){
        ll curr=order[k];
        vis[curr]=true;

        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][curr]+dist[curr][j]);

        ll sum=0;
        for(ll i=1;i<=n;i++){
            if(!vis[i])
                continue;
            
            for(ll j=1;j<=n;j++){
                if(!vis[j])
                    continue;

                sum+=dist[i][j];
            }
        }
        ans[k]=sum;
    }

    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}