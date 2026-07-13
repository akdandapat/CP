#include<bits/stdc++.h>
using namespace std;

/*
Author:ARPANN
2246
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<-1<<endl;
        return;
    }

    vll nums(n);
    if(n==3){
        nums[0]=3;
        nums[1]=6;
        nums[2]=9;
    }
    else{
        nums[0]=2;
        nums[1]=3;
        nums[2]=10;
        nums[3]=15;

        ll tot=30;
        for(ll i=4;i<n;i++){
            nums[i]=tot;
            tot*=2;
        }
    }

    for(ll &num:nums) cout<<num<<" ";
    cout<<endl;
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