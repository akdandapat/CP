#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    ll n,q;
    cin>>n>>q;
    
    vll v(n+1,0);
    vll cnt(q+2,0);
    map<ll,ll>mp;
    
    cnt[0]=n;
    ll k=0;
    
    for(ll i=0;i<q;i++){
        ll a;
        cin>>a;
        
        if(a==1){
            ll x;
            cin>>x;
            
            ll val=v[x];
            cnt[val]--;
            v[x]++;
            cnt[v[x]]++;
            mp[v[x]]++;
            
            if(cnt[k]==0){
                k++;
            }
        }

        else{
            ll y;
            cin>>y;
            
            if(y+k>q){
                cout<<0<<endl;
            }
            else{
                cout<<mp[y+k]<<endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;

    while(t--)
        solve();
}
