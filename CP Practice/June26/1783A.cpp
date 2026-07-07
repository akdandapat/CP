#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vll a(n);

    for(ll &num:a) cin>>num;

    if(n>=2){
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        swap(a[1],a.back());

        if(a[0]==a[1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    for(ll &num:a) cout<<num<<" ";
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