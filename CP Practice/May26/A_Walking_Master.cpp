#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll y_diff=d-b;
    if(y_diff<0){
        cout<<-1<<endl;
        return;
    }

    if(y_diff==0){
        cout<<((c-a<=0) ? a-c : -1)<<endl;
        return;
    }

    ll a_=c-y_diff;
    if(a<a_){
        cout<<-1<<endl;
        return;
    }
    cout<<(a-a_+y_diff)<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;

    while(t--)
        solve();
}