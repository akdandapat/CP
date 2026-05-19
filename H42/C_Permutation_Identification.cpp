#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl '\n'

ll f(ll c, ll d){
    if (c > d) swap(c, d); 
    
    cout << "? 1 " << c << " " << d << endl;
    cout.flush();
    ll cd;
    cin >> cd;
    return cd;
}

ll f_(ll i){
    cout << "? 2 " << i << endl;
    cout.flush();
    ll r;
    cin >> r;
    return r;
}

void solve (){
    ll n;
    cin >> n;
    vll perm(n + 1, -1);

    if(n == 2){
        ll num = f_(1);
        cout << "! ";
        cout << num << " ";
        cout << (num == 1 ? 2 : 1) << " ";
        cout << endl;
        cout.flush();
        return; 
    }

    ll c = 1, d = 2, e = 3;
    ll cd = f(c, d);
    ll ce = f(c, e);
    ll de = f(d, e);

    ll size = 2;

    while(size < n){
        size++;
        ll k = max({c, d, e});

        if(cd == de){
            perm[d] = de;
            d = k + 1;

            if(d == n + 1){
                perm[c] = f_(c);
                break; 
            }

            cd = f(c, d);
            de = f(d, e);
        }
        else if(ce == de){
            perm[e] = ce;
            e = k + 1;

            if(e == n + 1){
                perm[c] = f_(c);
                break;
            }

            ce = f(c, e);
            de = f(d, e);
        }
        else if(cd == ce){
            perm[c] = ce;
            c = k + 1;

            if(c == n + 1){
                perm[d] = f_(d);
                break;
            }

            cd = f(c, d);
            ce = f(c, e);
        }
    }

    vll test;
    test.pb(0);
    ll idx = -1;

    for(ll i = 1; i <= n; i++){
        if(perm[i] != -1)
            test.pb(perm[i]);
        else    
            idx = i;
    }

    sort(all(test));

    ll w = n;
    for(ll i = 1; i < n; i++){
        if(i != test[i]){ 
            w = i;
            break;
        }
    }

    perm[idx] = w;
    cout << "! ";
    for(ll i = 1; i <= n; i++) cout << perm[i] << " ";
    cout << endl;
    cout.flush();
}

int main() {
    fastio;
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}