#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>>grid(n,vector<char>(m));
    ll tot=0;
    ll sx=-1,sy=-1;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='.'){
                tot++;
                sx=i;
                sy=j;
            }
        }
    }

    ll rem=tot-k;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<array<ll,2>>q;

    ll dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

    if(rem>0){
        q.push({sx,sy});
        vis[sx][sy]=true;
        rem--;

        while(!q.empty() && rem){
            auto [x,y]=q.front();
            q.pop();

            for(auto&d:dir){
                ll nx=x+d[0];
                ll ny=y+d[1];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='.'){
                    vis[nx][ny]=true;
                    q.push({nx,ny});

                    rem--;

                    if(!rem){
                        break;
                    }
                }
            }
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){

            if(grid[i][j]=='.' && !vis[i][j]) grid[i][j]='X';
            cout<<grid[i][j];
            
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}