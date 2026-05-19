#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
*/

void solve(){
    ll h,w;

    cin>>h>>w;

    // if(h==1 && w==1){
    //     cout<<0<<endl;
    //     return;
    // }

    // if(h==1 && w==2){
    //     cout<<1<<" "<<1<<endl;
    //     return;
    // }

    // if(h==2 && w==1){
    //     cout<<1<<endl;
    //     cout<<1<<endl;
    //     return;
    // }

    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){

    //         ll num=4;
    //         if(i==0 || i==h-1) num--;
    //         if(j==0 || j==w-1) num--;
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int cnt=0;
            if(i-1>=0) cnt++;
            if(i+1<h) cnt++;
            if(j-1>=0) cnt++;
            if(j+1<w) cnt++;
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}