#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define vll vector<ll>
#define endl "\n"


void solve(){
    string s;
    cin>>s;

    ll n=s.size();

    vll cnt(26, 0);
    ll max_f=0;
    for(ll i=0;i<n;i++){
        cnt[s[i]-'a']++;
        max_f=max(max_f,cnt[s[i]-'a']);
    }
    
    if(max_f>(n+1)/2){
        cout<<"No"<<endl;
        return;
    }

    sort(s.begin(),s.end(),[&](char a,char b){
        if(cnt[a-'a']!=cnt[b-'a']) 
            return cnt[a-'a']>cnt[b-'a'];
        return a<b;
    });
    
    string ans="";
    for(ll t=0,j=n/2;t<2;t++,j++){
        if(j>n) break;

        ll ff=0;
        ll ss=j;

        string temp;
        temp.reserve(n);
        
        while(ff<j || ss<n){
            if(ff<j){
                temp+=s[ff];
                ff++;
            }
            if(ss<n){
                temp+=s[ss];
                ss++;
            }
        }

        ll m=temp.size();
        bool flag=1;
        for(ll i=1;i<m;i++){
            if(temp[i]==temp[i-1]){
                flag=0;
                break;
            }
        }

        if(flag && m==n){
            ans=temp;
            break;
        }
    }

    if(ans==""){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    cin>>t;

    while(t--)
        solve();
}
