#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;
    
    vll a(n);
    for(ll &num:a) cin>>num;
    sort(a.begin(),a.end());
    
    ll i=0,j=n-1;
    ll ans=0;
    

    ll sum=0;
    while(i<j && sum<a[j]){
        
        if(j==i+1){
            ans+=(a[i]+a[j]+1)/2;
            a[i]=0;
            a[j]=0;
            break;
        }

        else if(sum+a[i]<a[j]){
            sum+=a[i];
            ans+=a[i];
            a[i]=0;
            i++;
        }
        
        else{
            
            ll add=a[j]-sum;
            ll more=a[i]-add;
            
            a[i]=more;
            if(more==0)
                i++;
                
            ans+=add;
            
            a[j]=0;
            ans++;
            
            j--;
        }
    }
    
    
    for(ll &num:a) ans+=num;

    cout<<ans<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    
    while(t--){
        solve();
    }
}