#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using vll = vector<ll>;
using pii = pair<int, int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    ll sum = 0;
    int lastSecondQuery = 0;
    ll lastSecondQueryValue = 0;
    
    vector<int> lastFirstQuery(n + 1, 0);
    vector<ll> lastFirstQueryValue(n + 1, 0);
    
    // Read initial array and compute initial sum
    for (int i = 1; i <= n; i++) {
        cin >> lastFirstQueryValue[i];
        sum += lastFirstQueryValue[i];
        lastFirstQuery[i] = 0; // Initialize with time 0
    }
    
    // Process queries
    for (int q_idx = 1; q_idx <= q; q_idx++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int i;
            ll x;
            cin >> i >> x;
            
            // Determine current actual value of a[i]
            ll current_a_i;
            if (lastSecondQuery > lastFirstQuery[i]) {
                current_a_i = lastSecondQueryValue;
            } else {
                current_a_i = lastFirstQueryValue[i];
            }
            
            // Subtract old value, update records, add new value
            sum -= current_a_i;
            lastFirstQuery[i] = q_idx;
            lastFirstQueryValue[i] = x;
            sum += x;
            
        } else if (type == 2) {
            ll x;
            cin >> x;
            
            // Update global query trackers and the total sum
            lastSecondQuery = q_idx;
            lastSecondQueryValue = x;
            sum = (ll)n * lastSecondQueryValue;
        }
        
        cout << sum << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}