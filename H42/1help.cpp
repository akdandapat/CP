//==================== 🔥 BIT MANIPULATION ====================//
/*
__builtin_popcount(x);        // count set bits (int)
__builtin_popcountll(x);      // count set bits (long long)

__builtin_clz(x);             // count leading zeros (int)
__builtin_clzll(x);           // count leading zeros (ll)

__builtin_ctz(x);             // count trailing zeros (int)
__builtin_ctzll(x);           // count trailing zeros (ll)

ll msb = 63 - __builtin_clzll(n);   // index of most significant set bit
ll lsb = __builtin_ctzll(n);        // index of least significant set bit

if(n && !(n & (n-1)));              // check if power of 2

n |= (1LL << i);    // set i-th bit
n &= ~(1LL << i);   // unset i-th bit
n ^= (1LL << i);    // toggle i-th bit

(n >> i) & 1;       // check if i-th bit is set (0 or 1)

n &= (n - 1);       // remove lowest set bit

n & (-n);           // get lowest set bit value

ll x = stoll(s, nullptr, 2);            // binary string → number
string s = bitset<32>(x).to_string();   // number → binary string

s = s.substr(s.find('1'));              // remove leading zeros


//==================== 🔥 SET ====================//
set<ll> s;

s.insert(x);
s.erase(x);
s.count(x);
s.find(x);

*s.begin();
*s.rbegin();

s.lower_bound(x);
s.upper_bound(x);

s.size();
s.empty();


//==================== 🔥 MULTISET ====================//
multiset<ll> ms;

ms.insert(x);
ms.erase(ms.find(x));
ms.erase(x);

ms.count(x);

*ms.begin();
*ms.rbegin();

ms.lower_bound(x);
ms.upper_bound(x);


//==================== 🔥 MAP (ORDERED) ====================//
map<ll,ll> mp;

mp[x] = val;
mp.insert({x,val});

mp.erase(x);
mp.count(x);
mp.find(x);

mp.size();
mp.empty();

mp.lower_bound(x);
mp.upper_bound(x);

for(auto &[k,v]: mp){}


//==================== 🔥 UNORDERED MAP ====================//
unordered_map<ll,ll> ump;

ump[x] = val;
ump.erase(x);
ump.count(x);
ump.find(x);

ump.size();
ump.empty();


//==================== 🔥 ORDERED SET (PBDS) ====================//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> os;

os.insert(x);
os.erase(x);

*os.find_by_order(k);
os.order_of_key(x);


//==================== 🔥 PRIORITY QUEUE ====================//
priority_queue<ll> pq;

pq.push(x);
pq.pop();
pq.top();
pq.size();
pq.empty();

priority_queue<ll, vector<ll>, greater<ll>> minpq;

priority_queue<pair<ll,ll>> pq2;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq3;


//==================== 🔥 VECTOR ====================//
vector<ll> v;

v.push_back(x);
v.pop_back();

v.size();
v.empty();

v.front();
v.back();

sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());

reverse(v.begin(), v.end());

*max_element(v.begin(), v.end());
*min_element(v.begin(), v.end());

accumulate(v.begin(), v.end(), 0LL);


//==================== 🔥 DEQUE ====================//
deque<ll> dq;

dq.push_back(x);
dq.push_front(x);

dq.pop_back();
dq.pop_front();

dq.front();
dq.back();


//==================== 🔥 STACK ====================//
stack<ll> st;

st.push(x);
st.pop();
st.top();
st.size();
st.empty();


//==================== 🔥 QUEUE ====================//
queue<ll> q;

q.push(x);
q.pop();
q.front();
q.back();
q.size();
q.empty();


//==================== 🔥 ALGORITHMS ====================//
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());

reverse(v.begin(), v.end());

binary_search(v.begin(), v.end(), x);

lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);

next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());

__gcd(a,b);
lcm(a,b);


//==================== 🔥 PAIRS ====================//
pair<ll,ll> p;

p.first;
p.second;

make_pair(a,b);

sort(v.begin(), v.end()); // works for vector<pair>


//==================== 🔥 STRING ====================//
s.size();
s.substr(l, len);

stoi(s);
stoll(s);

to_string(x);

reverse(s.begin(), s.end());


//======================================== 🔥 CUSTOM COMPARATOR ========================================//

//---------- 🔹 SORT (vector / array) ----------//

// ascending by default
sort(v.begin(), v.end());

// descending
sort(v.begin(), v.end(), greater<ll>());

// custom comparator (function)
bool cmp(ll a, ll b){
    return a > b;   // descending
}
sort(v.begin(), v.end(), cmp);

// custom comparator (lambda)
sort(v.begin(), v.end(), [](ll a, ll b){
    return a > b;
});

// pair sorting
vector<pair<ll,ll>> v;

// sort by first ascending, second descending
sort(v.begin(), v.end(), [](pll a, pll b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
});


//---------- 🔹 SET / MAP CUSTOM ORDER ----------//

// descending set
set<ll, greater<ll>> s;

// custom comparator struct
struct cmpSet{
    bool operator()(ll a, ll b) const{
        return a > b;   // descending
    }
};
set<ll, cmpSet> s2;


//---------- 🔹 PRIORITY QUEUE ----------//

// max heap (default)
priority_queue<ll> pq;

// min heap
priority_queue<ll, vector<ll>, greater<ll>> pq2;

// custom comparator (pair)
priority_queue<pll, vector<pll>, greater<pll>> pq3;

// custom struct comparator
struct cmpPQ{
    bool operator()(pll a, pll b){
        return a.second > b.second; // min by second
    }
};
priority_queue<pll, vector<pll>, cmpPQ> pq4;


//---------- 🔹 MULTISET CUSTOM ----------//

multiset<ll, greater<ll>> ms;


//---------- 🔹 IMPORTANT RULE ----------//

// comparator should return TRUE if a should come BEFORE b
// i.e., defines strict ordering

// WRONG ❌ (can cause TLE / crash)
// return a <= b;

// CORRECT ✅
// return a < b;
*/