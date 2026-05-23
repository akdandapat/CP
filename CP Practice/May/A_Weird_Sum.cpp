#include<bits/stdc++.h>
using namespace std;

/*
Author: ARPANN
09:07
-------
loll
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vll> nums(n,vll(m));
    ll maxc=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>nums[i][j];
            maxc=max(maxc,nums[i][j]);
        }
    }

    //cout<<maxc<<endl;return;

    vector<vector<pll>> div(maxc+2);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            div[nums[i][j]].push_back({i,j});
        }
    }

    ll ans=0;
    vll x_idx,y_idx;

    for(ll i=0;i<maxc+2;i++){
        
        if(div[i].size()==0)
            continue;
        //cout<<1<<endl;

        ll tot_x=0,tot_y=0;
        x_idx.clear();
        y_idx.clear();
        for(ll j=0;j<div[i].size();j++){
            x_idx.push_back(div[i][j].first);
            y_idx.push_back(div[i][j].second);

            tot_x+=div[i][j].first;
            tot_y+=div[i][j].second;
        }

        sort(x_idx.begin(),x_idx.end());
        sort(y_idx.begin(),y_idx.end());

        ll curr_x=0,curr_y=0;
        //for(ll &num:x_idx) cout<<num<<endl; //0 1
        // for(ll &num:y_idx) cout<<num<<endl; 0 2
        //cout<<tot_x<<" "<<tot_y<<endl;  okk
        //cout<<x_idx.size()<<" "<<div[i].size()<<endl; //okk
        // return;

        
//--------------------------------------------------------//
        /* o fukk actually backward proyojon nei coz dubar gona hye jachhe....
        looper bhetor x_idx[i] niye niyechilam... */
//-------------------------------------------------------//

        for(ll j=0;j<div[i].size();j++){

            ll x_=((tot_x-curr_x)-(div[i].size()-j)*x_idx[j]);
            // ans+=((j*x_idx[i]-curr_x)+(tot_x-curr_x-(div[i].size()-j)*x_idx[i]));
            curr_x+=x_idx[j];

            ll y_=((tot_y-curr_y)-(div[i].size()-j)*y_idx[j]);
            // ans+=((j*y_idx[i]-curr_y)+(tot_y-curr_y-(div[i].size()-j)*y_idx[i]));
            curr_y+=y_idx[j];

            //cout<<x_<<" "<<y_<<endl;
            ans+=(x_+y_);
            // cout<<ans<<endl;
            
        }
        //return;

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
}