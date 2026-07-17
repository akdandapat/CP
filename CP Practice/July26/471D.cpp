#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,w;
    cin>>n>>w;

    vll towerA(n),towerB(w);
    for(ll i=0;i<n;i++) cin>>towerA[i];
    for(ll i=0;i<w;i++) cin>>towerB[i];

    if(w==1){
        cout<<n<<endl;
        return;
    }

    ll lenA=n-1;
    ll lenB=w-1;

    vll combo;
    for(ll i=0;i<lenB;i++)
        combo.push_back(towerB[i+1]-towerB[i]);

    combo.push_back(1e9+1);//impurity so that never overlaps

    for(ll i=0;i<lenA;i++)
        combo.push_back(towerA[i+1]-towerA[i]);

    ll sz=combo.size();
    vll pi(sz);
    ll ans=0;

    for(ll i=1;i<sz;i++){
        ll cur=pi[i-1];

        while(cur>0&&combo[i]!=combo[cur])
            cur=pi[cur-1];

        if(combo[i]==combo[cur])
            cur++;

        pi[i]=cur;
        if(pi[i]==lenB)
            ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}