#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll base1=313;
const ll base2=317;
const ll mod1=1000000007;
const ll mod2=1000000009;

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<string> mat(n);
    for(ll i=0;i<n;i++)
        cin>>mat[i];

    vll pow1(26,1),pow2(26,1);
    for(ll i=1;i<26;i++){
        pow1[i]=(pow1[i-1]*base1)%mod1;
        pow2[i]=(pow2[i-1]*base2)%mod2;
    }

    ll ans=0;
    for(ll l=0;l<m;l++){
        vector<vll> freq(n,vll(26));
        vll odd(n);

        for(ll r=l;r<m;r++){

            vll hash(n);
            vector<bool> good(n);

            for(ll row=0;row<n;row++){
                ll ch=mat[row][r]-'a';
                freq[row][ch]++;

                if(freq[row][ch]&1)
                    odd[row]++;
                else
                    odd[row]--;
            
                if(odd[row]<=1){
                    good[row]=1;
                    ll h1=0,h2=0;

                    for(ll i=0;i<26;i++){
                        h1=(h1+freq[row][i]*pow1[i])%mod1;
                        h2=(h2+freq[row][i]*pow2[i])%mod2;
                    }
                    hash[row]=h1*mod2+h2;
                }
            }

            ll st=0;
            while(st<n){
                if(!good[st]){
                    st++;
                    continue;
                }
                ll en=st;
                while(en<n&&good[en])
                    en++;

                ll len=en-st;
                vll temp(2*len+1,-1);
                for(ll i=0;i<len;i++)
                    temp[2*i+1]=hash[st+i];
                
                vll rad(2*len+1);
                ll cen=0,r=0;
                for(ll i=0;i<2*len+1;i++){
                    if(i<r)
                        rad[i]=min(r-i,rad[2*cen-i]);

                    while(i-rad[i]-1>=0&&i+rad[i]+1<2*len+1&&temp[i-rad[i]-1]==temp[i+rad[i]+1])
                        rad[i]++;
                    
                    if(i+rad[i]>r){
                        cen=i;
                        r=i+rad[i];
                    }
                    ans+=(rad[i]+1)/2;
                }
                st=en;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
