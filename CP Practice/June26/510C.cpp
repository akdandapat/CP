#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl "\n"

/*
just topo sort ig
*/
void solve(){
    ll n;
    cin>>n;

    vector<vll>adj(26,vll(26));
    vll indeg(26);
    vector<string>v(n);

    for(string &s:v) cin>>s;

    vll present(26);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<v[i].size();j++)
            present[v[i][j]-'a']=1;

    for(ll i=0;i<n-1;i++){
        string a=v[i];
        for(ll j=i+1;j<n;j++){

            string b=v[j];
            ll k=0;
            ll s1=a.size();
            ll s2=b.size();

            while(k<s1 && k<s2 && a[k]==b[k]){
                k++;
            }

            if(k==s1) continue;
            else if(k==s2){
                cout<<"Impossible"<<endl;
                return;
            }
            else{
                if(adj[a[k]-'a'][b[k]-'a']!=1)
                    indeg[b[k]-'a']++;

                adj[a[k]-'a'][b[k]-'a']=1;
            }
        }
    }

    queue<ll>q;
    for(ll i=0;i<26;i++) if(indeg[i]==0) q.push(i);

    string ans;

    while(!q.empty()){
        ll idx=q.front();
        q.pop();
        ans+=('a'+idx);

        for(ll i=0;i<26;i++){
            if(adj[idx][i]){
                indeg[i]--;
                if(indeg[i]==0)
                    q.push(i);
            }
        }
    }

    if(ans.size()==26){
        cout<<ans<<endl;
        return;
    }

    cout<<"Impossible"<<endl;

}

int main(){
    ll t=1;
    while(t--) solve();
}