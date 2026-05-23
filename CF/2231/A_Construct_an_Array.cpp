#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;

    set<ll>s;
    vll a(n);
    a[0]=1;
    if(n>1) a[1]=2;
    s.insert(3);

    int num=3;
    for(int i=2;i<n;i++){
        while(s.count(num))
            num++;
        a[i]=num;
        num++;
        s.insert(a[i]+a[i-1]);
    }

    for(ll &num:a) cout<<num<<" ";
    cout<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}