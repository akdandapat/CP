#include<bits/stdc++.h>
using namespace std;
/*
Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl "\n"

void solve(){
    string text;
    cin>>text;

    ll n=text.size();
    stack<ll>st;
    st.push(-1);//-1--> last idx for extra )...

    ll maxm=0;
    ll cnt=1;
    ll tot=0;
    for(ll i=0;i<n;i++){
        if(text[i]=='('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){//new wxtra back idx updation
                st.push(i);
            }else{
                ll cur=i-st.top();

                if(cur>maxm){
                    maxm=cur;
                    cnt=1;
                }else if(cur==maxm){
                    cnt++;
                }
            }
        }
    }

    if(maxm==0){
        cout<<0<<" "<<1<<endl;
    }else{
        cout<<maxm<<" "<<cnt<<endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}