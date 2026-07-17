#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/
#define ll long long
#define vll vector<ll>
#define endl "\n"

const ll mod=51123987;

void solve(){
    ll n;
    cin>>n;

    string str;
    cin>>str;

    string temp(2*n+1,'#');
    for(ll i=0;i<n;i++)
        temp[2*i+1]=str[i];
    
    vll rad(2*n+1);
    ll cen=0,r=0;

    for(ll i=0;i<2*n+1;i++){
        if(i<r)
            rad[i]=min(r-i,rad[2*cen-i]);

        while(i-rad[i]-1>=0&&i+rad[i]+1<2*n+1&&temp[i-rad[i]-1]==temp[i+rad[i]+1])
            rad[i]++;
        
        if(i+rad[i]>r){
            cen=i;
            r=i+rad[i];
        }
    }

    vll startDiff(n+2),endDiff(n+2);

    for(ll i=0;i<2*n+1;i++){
        if(rad[i]==0)
            continue;

        ll lmin=(i-rad[i])/2;
        ll lmax=(i-1)/2;
        ll rmin=i/2;
        ll rmax=(i+rad[i])/2-1;

        startDiff[lmin]++;
        startDiff[lmax+1]--;

        endDiff[rmin]++;
        endDiff[rmax+1]--;
    }

    vll start(n+1),end(n+1);

    ll currStart=0,currEnd=0;
    for(ll i=0;i<n;i++){
        currStart+=startDiff[i];
        currEnd+=endDiff[i];
        start[i]=currStart;
        end[i]=currEnd;
    }

    vll suff(n+1);
    for(ll i=n-1;i>=0;i--)
        suff[i]=(suff[i+1]+start[i])%mod;

    ll tot=accumulate(start.begin(),start.end(),0ll);

    ll ans=(tot%mod)*((tot-1)%mod)%mod;
    ans=(ans*25561994)%mod;

    ll non=0;
    for(ll i=0;i<n;i++)
        non=(non+(end[i]%mod)*suff[i+1])%mod;

    ans=(ans-non+mod)%mod;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}