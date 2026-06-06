#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

/* 
Author:ARPANN
 */

struct Usr{
    bool act;
    ll bud;
    ll nrg;
};

struct Res{
    ll sat=-1;
    ll cst=-1;
    vll ids;
};

ll fnd(const string& nm,const Inp& in){
    for(ll i=0;i<in.N;i++){
        if(in.usr[i].nm==nm)return i;
    }
    return -1;
}

void dfs(ll idx,ll cst,ll nrg,ll dur,ll sat,vll& cur,const vector<Act>& elg,ll mb,ll me,ll h,const vll& val,Res& bst){
    bool btr=false;
    if(sat>bst.sat){
        btr=true;
    } 
    else if(sat==bst.sat){
        if(cst<bst.cst){
            btr=true;
        } 
        else if(cst==bst.cst){
            if(cur<bst.ids){
                btr=true;
            }
        }
    }
    
    if(btr){
        bst.sat=sat;
        bst.cst=cst;
        bst.ids=cur;
    }
    
    for(ll i=idx;i<(ll)elg.size();i++){
        if(cst+elg[i].cst<=mb && nrg+elg[i].nrg<=me && dur+elg[i].dur<=h){
            cur.push_back(elg[i].id);
            dfs(i+1,cst+elg[i].cst,nrg+elg[i].nrg,dur+elg[i].dur,sat+val[i],cur,elg,mb,me,h,val,bst);
            cur.pop_back();
        }
    }
}

Res pln(ll d,const vector<vector<Usr>>& uds,const vector<set<string>>& blk,const set<ll>& usd,const Inp& in){
    ll mb=2e9;
    ll me=2e9;
    vll au;
    
    for(ll u=0;u<in.N;u++){
        if(uds[u][d].act){
            au.push_back(u);
            mb=min(mb,uds[u][d].bud);
            me=min(me,uds[u][d].nrg);
        }
    }
    
    if(au.empty()){
        return Res{0,0,{}};
    }
    
    vector<Act> elg;
    for(auto const& [id,act]:in.act){
        if(usd.count(id)==0 && blk[d].count(act.tag)==0){
            elg.push_back(act);
        }
    }
    
    vll val(elg.size(),0);
    for(size_t i=0;i<elg.size();i++){
        ll s=0;
        for(ll u:au){
            if(in.usr[u].tag.count(elg[i].tag)){
                s++;
            }
        }
        val[i]=s;
    }
    
    Res bst;
    vll cur;
    dfs(0,0,0,0,0,cur,elg,mb,me,in.H,val,bst);
    
    return bst;
}

static string slv(Inp in){
    string out;
    out+="=== PLAN ===\n";
    
    vector<vector<Usr>> uds(in.N,vector<Usr>(in.D+1));
    vector<set<string>> blk(in.D+1);
    
    for(ll u=0;u<in.N;u++){
        for(ll d=1;d<=in.D;d++){
            uds[u][d].act=in.usr[u].act;
            uds[u][d].bud=in.usr[u].bud;
            uds[u][d].nrg=in.usr[u].nrg;
        }
    }
    
    vector<Res> res(in.D+1);
    set<ll> usd;
    
    for(ll d=1;d<=in.D;d++){
        res[d]=pln(d,uds,blk,usd,in);
        for(ll id:res[d].ids){
            usd.insert(id);
        }
        out+=fmt(d,res[d].ids,res[d].cst,res[d].sat)+"\n";
    }
    
    for(ll i=0;i<(ll)in.evt.size();i++){
        stringstream ss(in.evt[i]);
        string typ;
        ss>>typ;
        ll ed;
        ss>>ed;
        
        if(typ=="WEATHER"){
            string tag;
            ss>>tag;
            if(ed>=1 && ed<=in.D){
                blk[ed].insert(tag);
            }
        } 
        else if(typ=="DROP"){
            string nm;
            ss>>nm;
            ll u=fnd(nm,in);
            if(u!=-1){
                for(ll d=max(1LL,ed);d<=in.D;d++) uds[u][d].act=false;
            }
        } 
        else if(typ=="FATIGUE"){
            string nm;
            ll nrg;
            ss>>nm>>nrg;
            ll u=fnd(nm,in);
            if(u!=-1){
                for(ll d=max(1LL,ed);d<=in.D;d++) uds[u][d].nrg=nrg;
            }
        } 
        else if(typ=="BUDGET"){
            string nm;
            ll bud;
            ss>>nm>>bud;
            ll u=fnd(nm,in);
            if(u!=-1){
                for(ll d=max(1LL,ed);d<=in.D;d++) uds[u][d].bud=bud;
            }
        }
        
        usd.clear();
        for(ll d=1;d<ed;d++){
            if(d<=in.D){
                for(ll id:res[d].ids){
                    usd.insert(id);
                }
            }
        }
        
        for(ll d=max(1LL,ed);d<=in.D;d++){
            res[d]=pln(d,uds,blk,usd,in);
            for(ll id:res[d].ids){
                usd.insert(id);
            }
        }
        
        out+="=== EVENT "+to_string(i+1)+": "+in.evt[i]+" ===\n";
        for(ll d=max(1LL,ed);d<=in.D;d++){
            out+=fmt(d,res[d].ids,res[d].cst,res[d].sat)+"\n";
        }
    }
    
    return out;
}

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--)
        solve();
        
    return 0;
}