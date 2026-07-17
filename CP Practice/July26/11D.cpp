#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vector<bool>> graph(n,vector<bool>(n));
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;

        graph[u][v]=true;
        graph[v][u]=true;
    }

    vector<vll> dp(1LL<<n,vll(n,0));
    for(ll i=0;i<n;i++)
        dp[1LL<<i][i]=1;
    
    ll ans=0;

    for(ll mask=1;mask<(1LL<<n);mask++){
        ll start=__builtin_ctzll(mask);//lowest set bit

        for(ll curr=start;curr<n;curr++){
            if(!(mask&(1LL<<curr)))//not in the subset
                continue;

            if(dp[mask][curr]==0)//no path exists
                continue;
            
            for(ll next=start;next<n;next++){
                if(!graph[curr][next])
                    continue;
                
                if(next==start){
                    if(__builtin_popcountll(mask)>=3)
                        ans+=dp[mask][curr]; 
                }
                else if(!(mask&(1LL<<next)))
                    dp[mask|(1LL<<next)][next]+=dp[mask][curr];
                
            }
        }
    }

    cout<<ans/2<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}