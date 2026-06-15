#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
-----------------------------------
2236
*/

void solve(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    vll cnt(n+1);
    
    for(ll &num:a){
        cin>>num;
        cnt[num]++;
    }

    vector<bool> lose(n+1,false);
    ll c=0;
    bool flag=0;
    
    for(ll i=n;i>=1;i--){
        
        if(cnt[i]>0){
            bool win;
            if(c) win=1;
            else win=(cnt[i]%2==0);

            win ? flag=1 : lose[i]=1;
        }

        if(cnt[i]>0 && lose[i]) c++;
        if(i+k<=n && cnt[i+k]>0 && lose[i+k]) c--;
    }

    cout<<(flag ? "YES" : "NO")<<endl;
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