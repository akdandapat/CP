#include<bits/stdc++.h>
using namespace std;

/*
Name: ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll n,k;
    cin>>n>>k;

    if((n+1)%3!=0){
        cout<<-1<<endl;
        return;
    }

    vll ans(n);
    ans[0]=ans[1]=1;

    for(int i=2;i<n;i++){
        if((i+1)%3==0) ans[i]=0;
        else if((i+1)%6<3) ans[i]=1;
        else ans[i]=k-1;
    }

    for(ll &num:ans) cout<<num<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}