#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

ll dp[1<<15];
void solve(){
    ll n,m;
    cin>>n>>m;

    ll inf=1e15;
    ll sum=0;

    vll deg(n+1);
    vector<vll> dist(n+1,vll(n+1,inf));

    for(ll i=1;i<=n;i++)
        dist[i][i]=0;

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        sum+=w;
        deg[u]++;
        deg[v]++;

        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }

    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            
    vll odd;
    for(ll i=1;i<=n;i++)
        if(deg[i]&1)
            odd.push_back(i);

    ll sz=odd.size();
    ll lim=1LL<<sz;

    for(ll i=0;i<lim;i++)
        dp[i]=inf;

    dp[0]=0;
    for(ll mask=0;mask<lim;mask++){
        if(dp[mask]==inf)
            continue;

        ll first=-1;
        for(ll i=0;i<sz;i++){
            if(!(mask&(1LL<<i))){
                first=i;
                break;
            }
        }

        if(first==-1)
            continue;

        for(ll i=first+1;i<sz;i++){
            if(mask&(1LL<<i))
                continue;

            ll nextm=mask|(1LL<<first)|(1LL<<i);
            dp[nextm]=min(dp[nextm],dp[mask]+dist[odd[first]][odd[i]]);
        }
    }

    if(m==0)
        cout<<0<<endl;
    else
        cout<<sum+dp[lim-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}