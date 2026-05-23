#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
using namespace std;
// using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pqll priority_queue<ll>
#define qll queue<ll>
#define sll stack<ll>
#define npqll priority_queue<ll, vll, greater<ll>>
#define vpll vector<pair<ll,ll>>
#define usll unordered_set<ll>
#define msll multiset<ll>
#define uss unordered_set<string>
#define uspll unordered_set<pll>
#define umll unordered_map<ll,ll>
#define sort_(v) sort(all(v), greater<>())
#define mll map<ll,ll>
#define mcl map<char,ll>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl

const ll mod = 1e9 + 7;
const ll MOD=998'244'353;
const int MAXN=200005;

//------Bit_Manipulation------*/
// __builtin_popcountll(num);
//ll msb = 63 - __builtin_clzll(n);
//ll d = __builtin_ctzll(n); power of 2
//string s = "10101"; ll x = stoll(s, nullptr, 2); cout << x;   // 21
//int x = 13;string s = bitset<32>(x).to_string();
//Removing trailing zero: s = s.substr(s.find('1'));

/*------Multiset------*/
// auto mx = *s.rbegin();
// auto mn = *s.begin();

/*-----SIEVE-----*/
int spf[MAXN];
void sieve(){iota(spf,spf+MAXN,0);for(int i=2;i*i<MAXN;i++){if(spf[i]==i){for(int j=i*i;j<MAXN;j+=i)if(spf[j]==j) spf[j]=i;}}}
vll get_fac(ll x){vll fac;while(x>1){ll p=spf[x];fac.pb(p);while(x%p==0) x/=p;}return fac;}

/* ---- Dense Utilities ---- */
ll gcd_ll(ll a,ll b){return __gcd(a,b);}
ll gcd_arr(const vll& nums){ll g=0;for(ll x:nums)g=__gcd(g,x);return g;}
ll lcm_ll(ll a,ll b){return a/gcd_ll(a,b)*b;}
bool isPrime(int x){if(x<2) return 0; for(int i=2;i*i<=x;i++) if(x%i==0) return 0; return 1;}
bool isPalindrome(string s){string r=s; reverse(all(r)); return s==r;}
string toUpperCase(string s){transform(all(s),s.begin(),::toupper); return s;}
string toLowerCase(string s){transform(all(s),s.begin(),::tolower); return s;}

/* ---- Modular ---- */
ll power(ll x,ll y){ll r=1; for(x%=MOD;y;y>>=1,x=x*x%MOD) if(y&1) r=r*x%MOD; return r;}

/* ---- nCr ---- */
vll fact(MAXN+1),invfact(MAXN+1);
void init_ncr(){fact[0]=1; for(int i=1;i<=MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXN]=power(fact[MAXN],MOD-2);
    for(int i=MAXN;i;i--) invfact[i-1]=invfact[i]*i%MOD;}
ll mod_ncr(int n,int r){return (r<0||r>n)?0:fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;}

/* ---- TO_STRING ---- */
string toBin(string n){  if(n=="0") return "0"; string b=""; while(n!="0"){
   string t=""; int c=0;for(char x:n){ int v=c*10+(x-'0');  t+=char(v/2+'0'); c=v%2;}b+=char(c+'0');
        n=t.substr(t.find_first_not_of('0')); if(n=="") n="0"; } reverse(b.begin(),b.end()); return b;}

/* ---- POW ---- */
long long modpow(long long b, long long e, long long m) {
    long long r = 1; b %= m; while(e) { if(e & 1) r = r * b % m;b = b * b % m;  e >>= 1; }
    return r;}
/* ---- PERM ---- */
vvll perm_arr(vll a) {sort(all(a));vvll perms;
do { perms.push_back(a);} while (next_permutation(all(a)));return perms;}

vll perm_str(string s) {vll perms;sort(all(s));do {perms.pb(stoll(s));} while (next_permutation(all(s)));return perms;}

/* ---- BS ---- */
ll first_occurrence(const vll&a,ll l,ll r,ll x){ ll ans=-1; for(;l<=r;){ ll m=(l+r)>>1; if(a[m]>=x){ if(a[m]==x) ans=m; r=m-1; } else l=m+1; } return ans; }

ll last_occurrence(const vll&a,ll l,ll r,ll x){ ll ans=-1; for(;l<=r;){ ll m=(l+r)>>1; if(a[m]<=x){ if(a[m]==x) ans=m; l=m+1; } else r=m-1; } return ans; }

/* ---- YOO---- */
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void input(vector<ll>& v , ll n) {for(ll i=0;i<n;i++) cin>>v[i]; }

void solve() {
    ll n;
    cin>>n;

    map<ll,ll>mp;
    vvll store;

    for(ll i=0;i<n;i++){
        ll m;
        cin>>m;
        vll temp;

        for(ll j=0;j<m;j++){
            ll idx;
            cin>>idx;

            temp.pb(idx);
            mp[idx]++;
        }
        store.pb(temp);
    }

    for(ll i=0;i<n;i++){
        bool flag=1;
        for(ll j=0;j<store[i].size();j++){
            
            if(mp[store[i][j]]==1){
                flag=0;
                break;
            }

        }
        if(flag){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}