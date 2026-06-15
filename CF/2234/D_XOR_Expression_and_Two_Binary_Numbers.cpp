#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN 
----------------------
2234
*/
// void f(ll f,ll l,vll &a){
//     ll idx=(f+l)/2;

//     if(a[idx-1]==-1){
//         a[idx-1]=a[f-1]^a[l-1];
//         f(f,idx,a);
//         f(idx,l,a);
//     }
// }

// void solve(){
//     ll n,k;
//     cin>>n>>k;
    
//     ll s=pow(2,k)+1;
//     vll a(s,-1);
    
//     string f,l;
//     cin>>f>>l;
//     a[0]=stoll(f,nullptr,2);
//     a[s-1]=stoll(l,nullptr,2);

//     a[(s+1ll)/2-1]=a[0]^a[s-1];

//     f(1,(s+1ll)/2,a);
//     f((s+1ll)/2,s,a);

//     ll ans=0;
//     for(ll i=0;i<s;i++){
//         ll set=__builtin_popcountll(a[i]);
//         ans+=set*(n-set);
//     }

//     cout<<ans<<endl;
// }


void solve(){
    ll n,k;
    cin>>n>>k;

    string s1,s2;
    cin>>s1>>s2;

    ll f1=0,l1=0;
    for(char ch:s1) if(ch=='1') f1++;
    for(char ch:s2) if(ch=='1') l1++;

    ll diff=0;
    for(ll i=0;i<n;i++) 
        if(s1[i]!=s2[i])
            diff++;

    ll s=(ll)pow(2,k+1);
    ll adj=(k%2 ? -1 : 1);

    ll num1=(s/2-adj)/3;
    ll num2=(s+3+adj)/6;

    cout<<((num1*diff*(n-diff))+(num2*(f1*(n-f1)+l1*(n-l1))))<<endl;

    
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