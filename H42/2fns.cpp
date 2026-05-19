//==================== 🔥 1. BINARY SEARCH TEMPLATES ====================//
/*

// first index i such that v[i] >= x
ll first_ge(vll &v, ll x){
    ll l=0,r=v.size()-1,ans=v.size();
    while(l<=r){
        ll m=(l+r)/2;
        if(v[m]>=x) ans=m,r=m-1;
        else l=m+1;
    }
    return ans;
}

// first index i such that v[i] > x
ll first_gt(vll &v, ll x){
    ll l=0,r=v.size()-1,ans=v.size();
    while(l<=r){
        ll m=(l+r)/2;
        if(v[m]>x) ans=m,r=m-1;
        else l=m+1;
    }
    return ans;
}

// last index i such that v[i] <= x
ll last_le(vll &v, ll x){
    ll l=0,r=v.size()-1,ans=-1;
    while(l<=r){
        ll m=(l+r)/2;
        if(v[m]<=x) ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}

// last index i such that v[i] < x
ll last_lt(vll &v, ll x){
    ll l=0,r=v.size()-1,ans=-1;
    while(l<=r){
        ll m=(l+r)/2;
        if(v[m]<x) ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}

// binary search on answer
ll bs_answer(ll l, ll r){
    while(l<=r){
        ll m=(l+r)/2;
        if(check(m)) r=m-1;
        else l=m+1;
    }
    return l;
}


//==================== 🔥 2. DP TEMPLATES ====================//

// 1D DP
vll dp(n+1,0);
for(ll i=1;i<=n;i++){
    dp[i]=dp[i-1]+a[i];
}

// 2D DP
vector<vll> dp(n+1,vll(m+1,0));
for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
}

// 3D DP
vector<vector<vll>> dp(n+1,vector<vll>(m+1,vll(k+1,0)));

// memoization
ll dp[N];
ll f(ll i){
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=f(i-1);
}

// knapsack
for(ll i=0;i<n;i++){
    for(ll j=W;j>=wt[i];j--){
        dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
    }
}


//==================== 🔥 3. GRAPH TEMPLATES ====================//

// adjacency list
vector<vll> adj(n+1);

// DFS
void dfs(ll u, ll p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}

// BFS
void bfs(ll src){
    queue<ll> q;
    vector<ll> vis(n+1,0);
    q.push(src); vis[src]=1;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

// Dijkstra
vector<ll> dijkstra(ll src){
    vll dist(n+1,1e18);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]:adj[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

// DSU
vll parent,sz;
ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unite(ll a,ll b){
    a=find(a); b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}


//==================== 🔥 4. IMPORTANT ALGORITHMS ====================//

// Kadane
ll kadane(vll &a){
    ll sum=0,ans=-1e18;
    for(auto x:a){
        sum=max(x,sum+x);
        ans=max(ans,sum);
    }
    return ans;
}

// prefix sum
vll pref(n+1,0);
for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];

// factorial + nCr
const ll MOD=1e9+7;
vll fact(N),invfact(N);

ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void init(){
    fact[0]=1;
    for(ll i=1;i<N;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[N-1]=power(fact[N-1],MOD-2);
    for(ll i=N-2;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;
}

ll ncr(ll n,ll r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

// SPF (smallest prime factor)
vll spf(N);

void sieve(){
    for(ll i=1;i<N;i++) spf[i]=i;
    for(ll i=2;i*i<N;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<N;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

// factorization using spf
vector<ll> getFactors(ll x){
    vector<ll> f;
    while(x>1){
        f.push_back(spf[x]);
        x/=spf[x];
    }
    return f;
}

// gcd / lcm

ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

// fast exponentiation
ll binpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
*/