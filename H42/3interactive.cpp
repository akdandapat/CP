//==================== 🔥 CF INTERACTIVE STYLE PRACTICE ====================//
// NOTE: These are SIMULATED interactive-style problems.
// In real CF interactive problems, you must flush using: cout.flush();

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//==============================================================//
// Q1: Guess the Number (Binary Search Interactive)
// Judge has a number in [1, n]. You can ask "? x"
// Response: -1 (hidden < x), 1 (hidden > x), 0 (equal)
// Print "! ans"
//==============================================================//

void guess_number(ll n){
    ll l=1,r=n;
    while(l<=r){
        ll m=(l+r)/2;
        cout<<"? "<<m<<endl;
        cout.flush();
        ll res; cin>>res;
        if(res==0){
            cout<<"! "<<m<<endl;
            cout.flush();
            return;
        }
        else if(res==-1) r=m-1;
        else l=m+1;
    }
}

//==============================================================//
// Q2: Find Maximum Element Index
// Query "? i j" → returns index of max element between i and j
// Goal: find index of global maximum
//==============================================================//

ll find_max_index(ll n){
    ll l=1,r=n;
    while(l<r){
        ll m=(l+r)/2;
        cout<<"? "<<l<<" "<<m<<endl;
        cout.flush();
        ll idx; cin>>idx;
        if(idx<=m) r=m;
        else l=m+1;
    }
    cout<<"! "<<l<<endl;
    return l;
}

//==============================================================//
// Q3: Find Position of Zero
// Array has all 1s except one 0
// Query "? l r" → returns sum in range
//==============================================================//

ll find_zero(ll n){
    ll l=1,r=n;
    while(l<r){
        ll m=(l+r)/2;
        cout<<"? "<<l<<" "<<m<<endl;
        cout.flush();
        ll sum; cin>>sum;
        if(sum==(m-l+1)) l=m+1; // no zero here
        else r=m;
    }
    cout<<"! "<<l<<endl;
    return l;
}

//==============================================================//
// Q4: Find First Bad Version
// Query "? x" → returns 0 (good) or 1 (bad)
// Find first bad
//==============================================================//

ll first_bad(ll n){
    ll l=1,r=n,ans=n;
    while(l<=r){
        ll m=(l+r)/2;
        cout<<"? "<<m<<endl;
        cout.flush();
        ll res; cin>>res;
        if(res==1) ans=m,r=m-1;
        else l=m+1;
    }
    cout<<"! "<<ans<<endl;
    return ans;
}

//==============================================================//
// Q5: Find Hidden Permutation (small n)
// Query "? i j" → returns a[i] % a[j]
//==============================================================//

vector<ll> find_perm(ll n){
    vector<ll> a(n+1);
    vector<ll> val(n+1);

    for(ll i=1;i<n;i++){
        cout<<"? "<<i<<" "<<i+1<<endl;
        cout.flush();
        ll x; cin>>x;

        cout<<"? "<<i+1<<" "<<i<<endl;
        cout.flush();
        ll y; cin>>y;

        if(x>y){
            a[i]=x;
        } else{
            a[i+1]=y;
        }
    }

    ll used=0;
    for(ll i=1;i<=n;i++) if(a[i]) used=max(used,a[i]);
    for(ll i=1;i<=n;i++) if(!a[i]) a[i]=n;

    cout<<"! ";
    for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

    return a;
}

//==============================================================//
// Q6: Find Minimum with Queries
// Query "? i j" → returns min(a[i], a[j])
//==============================================================//

ll find_min_idx(ll n){
    ll idx=1;
    for(ll i=2;i<=n;i++){
        cout<<"? "<<idx<<" "<<i<<endl;
        cout.flush();
        ll val; cin>>val;
        if(val==i) idx=i;
    }
    cout<<"! "<<idx<<endl;
    return idx;
}

//==============================================================//
// Q7: Find Peak Element
// Query "? i" → returns value at i
// Find i such that a[i] is peak
//==============================================================//

ll find_peak(ll n){
    ll l=1,r=n;
    while(l<r){
        ll m=(l+r)/2;

        cout<<"? "<<m<<endl;
        cout.flush();
        ll x; cin>>x;

        cout<<"? "<<m+1<<endl;
        cout.flush();
        ll y; cin>>y;

        if(x<y) l=m+1;
        else r=m;
    }
    cout<<"! "<<l<<endl;
    return l;
}

//==============================================================//
// Q8: Find Hidden Number with XOR Queries
// Query "? i j" → returns a[i] XOR a[j]
//==============================================================//

ll find_xor_base(ll n){
    ll base=0;
    for(ll i=2;i<=n;i++){
        cout<<"? "<<1<<" "<<i<<endl;
        cout.flush();
        ll x; cin>>x;
        base ^= x;
    }
    cout<<"! "<<base<<endl;
    return base;
}

//==============================================================//

int main(){
    // choose function based on problem
    return 0;
}