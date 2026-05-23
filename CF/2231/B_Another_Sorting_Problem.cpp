#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;

    //multiset<ll>mn,mx;
    vll a(n);
    for(ll &num:a){
        cin>>num;
        //mn.insert(num);
    }

    // mx.insert(a[0]);
    // mn.erase(mn.find(a[0]));

    // for(ll i=1;i<n;i++){
    //     if(*mx.rbegin()>a[i] && a[i]>*mn.begin()){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    //     mx.insert(a[i]);
    //     mn.erase(mn.find(a[i]));
    // }

    // ll k=0;
    // for(ll i=1;i<n;i++){
    //     if(a[i-1]>a[i]){
    //         if(k==0){
    //             k=(a[i-1]-a[i]);
    //             if(i<n-1 ) k=max(k,a[i+1]-a[i]);
    //         }
    //         a[i]+=k;
    //         if(a[i-1]>a[i]){
    //             cout<<"NO"<<endl;
    //             return;
    //         }
    //     }
    // }
    // cout<<"YES"<<endl;

    ll L=0;
    bool sorted_arr=true;
    for(ll i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            sorted_arr=false;
            L=max(L,a[i]-a[i+1]);
        }
    }

    if(sorted_arr){
        cout<<"YES"<<endl;
        return;
    }

    ll k=L;
    ll prev=0;

    for(ll i=0;i<n;i++){
        if(a[i]>=prev){
            prev=a[i];
        } 
        else if(a[i]+k>=prev){
            prev=a[i]+k;
        } 
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
