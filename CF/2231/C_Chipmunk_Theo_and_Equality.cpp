#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;

    vll a(n);
    for(ll &num:a) cin>>num;

    vector<map<ll,ll>>v(n);
    for(ll i=0;i<n;i++){
        ll num=a[i];
        ll cnt=0;

        v[i][num]=cnt;
        if(num==1) v[i][2]=1;
        while(num!=1){
            if(num%2==0){
                num/=2;
            }
            else{
                num++;
            }

            cnt++;
            v[i][num]=cnt;
        }
    }

    ll anss=2e17;
    for(auto &p:v[0]){
        ll num=p.first;
        ll ans=p.second;

        bool flag=1;
        for(ll i=1;i<n;i++){
            if(v[i].count(num)){
                ans+=v[i][num];
            }
            else
                flag=0;
        }

        if(flag==1){
            anss=min(anss,ans);
        }
    }

    cout<<anss<<endl;
}

int main(){
    
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
