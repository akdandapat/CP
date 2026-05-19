#include<bits/stdc++.h>
using namespace std;

/*
Name: ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll x;
    cin>>x;

    if(x<=20){
        cout<<x*10<<endl;
    }
    else{
        cout<<200+((x-20)/2)*5<<endl;
    }
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