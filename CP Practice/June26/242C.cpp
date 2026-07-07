#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

/*
---------------
this is actually pretty easy at first i thought total length of seg>1e9 :)))
---------------
*/
void solve(){
    ll sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;

    ll n;
    cin>>n;
    
    set<array<ll,2>>s;
    for(ll i=0;i<n;i++){
        ll r,a,b;
        cin>>r>>a>>b;
        
        for(ll j=a;j<=b;j++){
            s.insert({r,j});
        }
    }

    queue<array<ll,3>>q;
    q.push({sx,sy,0});

    while(!q.empty()){
        auto a=q.front();
        q.pop();

        ll ux=a[0];
        ll uy=a[1];
        ll udist=a[2];

        if(ux==ex && uy==ey){
            cout<<udist<<endl;
            return;
        }

        for(ll i=-1;i<2;i++){
            for(ll j=-1;j<2;j++){
                ll nx=ux+i;
                ll ny=uy+j;

                if(s.count({nx,ny})){
                    q.push({nx,ny,udist+1});
                    s.erase({nx,ny});
                }
            }
        }
    }

    cout<<-1<<endl;
}

int main(){
    ll t=1;
    while(t--) solve();
}