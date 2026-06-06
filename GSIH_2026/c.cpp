#include <bits/stdc++.h>
using namespace std;

/* Author:ARPANN
*/

#define ll long long
#define vll vector<ll>
#define endl '\n'

struct Ond;
struct Tnd {
    bool hs=0, hn=0, hb=0, hl=0;
    Ond* ond = nullptr;
    Tnd* arr = nullptr;
    ~Tnd();
};

struct Ond {
    string inm;
    int nom=0;
    map<string,int> fpc;
    map<string,Tnd*> fld;
    ~Ond() {
        for(auto& kv:fld) delete kv.second;
    }
};

Tnd::~Tnd() {
    delete ond;
    delete arr;
}

struct Jvl {
    enum Typ {NUL,STR,NUM,BOL,ARR,OBJ} typ;
    vector<Jvl> avl;
    vector<pair<string,Jvl>> ovl;
};

class Jpr {
    const string& str;
    size_t pos;
    void skp() {
        while(pos<str.length() && isspace(str[pos])) pos++;
    }
public:
    Jpr(const string& s) : str(s), pos(0) {}
    Jvl prs() {
        skp();
        if(pos>=str.length()) return {Jvl::NUL};
        char c=str[pos];
        if(c=='n') {
            pos+=4;
            return {Jvl::NUL};
        } else if(c=='t') {
            pos+=4;
            return {Jvl::BOL};
        } else if(c=='f') {
            pos+=5;
            return {Jvl::BOL};
        } else if(c=='"') {
            pos++;
            while(pos<str.length()) {
                if(str[pos]=='\\') pos+=2;
                else if(str[pos]=='"') {pos++;break;}
                else pos++;
            }
            return {Jvl::STR};
        } else if(c=='-' || isdigit(c)) {
            while(pos<str.length() && (isdigit(str[pos]) || str[pos]=='.' || str[pos]=='-' || str[pos]=='+' || str[pos]=='e' || str[pos]=='E')) pos++;
            return {Jvl::NUM};
        } else if(c=='[') {
            pos++;
            Jvl val;
            val.typ=Jvl::ARR;
            skp();
            if(pos<str.length() && str[pos]==']') {
                pos++;
                return val;
            }
            while(pos<str.length()) {
                val.avl.push_back(prs());
                skp();
                if(pos<str.length() && str[pos]==']') {pos++;break;}
                if(pos<str.length() && str[pos]==',') pos++;
            }
            return val;
        } else if(c=='{') {
            pos++;
            Jvl val;
            val.typ=Jvl::OBJ;
            skp();
            if(pos<str.length() && str[pos]=='}') {
                pos++;
                return val;
            }
            while(pos<str.length()) {
                skp();
                string key="";
                if(pos<str.length() && str[pos]=='"') {
                    pos++;
                    size_t st=pos;
                    while(pos<str.length() && str[pos]!='"') pos++;
                    key=str.substr(st, pos-st);
                    pos++;
                }
                skp();
                if(pos<str.length() && str[pos]==':') pos++;
                val.ovl.push_back({key, prs()});
                skp();
                if(pos<str.length() && str[pos]=='}') {pos++;break;}
                if(pos<str.length() && str[pos]==',') pos++;
            }
            return val;
        }
        return {Jvl::NUL};
    }
};

void mrg(const Jvl& v, Tnd* t) {
    if(v.typ==Jvl::NUL) t->hl=1;
    else if(v.typ==Jvl::STR) t->hs=1;
    else if(v.typ==Jvl::NUM) t->hn=1;
    else if(v.typ==Jvl::BOL) t->hb=1;
    else if(v.typ==Jvl::ARR) {
        if(!t->arr) t->arr=new Tnd();
        for(const auto& e:v.avl) mrg(e, t->arr);
    } else if(v.typ==Jvl::OBJ) {
        if(!t->ond) t->ond=new Ond();
        t->ond->nom++;
        for(const auto& kv:v.ovl) {
            t->ond->fpc[kv.first]++;
            if(t->ond->fld.find(kv.first)==t->ond->fld.end()) t->ond->fld[kv.first]=new Tnd();
            mrg(kv.second, t->ond->fld[kv.first]);
        }
    }
}

string gts(const Tnd& t) {
    vector<string> cmp;
    if(t.hb) cmp.push_back("boolean");
    if(t.hl) cmp.push_back("null");
    if(t.hn) cmp.push_back("number");
    if(t.hs) cmp.push_back("string");
    if(t.ond) cmp.push_back(t.ond->inm);
    if(t.arr) {
        vector<string> ec;
        if(t.arr->hb) ec.push_back("boolean");
        if(t.arr->hl) ec.push_back("null");
        if(t.arr->hn) ec.push_back("number");
        if(t.arr->hs) ec.push_back("string");
        if(t.arr->ond) ec.push_back(t.arr->ond->inm);
        if(ec.empty()) {
            cmp.push_back("unknown[]");
        } else if(ec.size()==1) {
            cmp.push_back(ec[0]+"[]");
        } else {
            sort(ec.begin(), ec.end());
            string un="";
            for(size_t i=0; i<ec.size(); ++i) {
                if(i>0) un+=" | ";
                un+=ec[i];
            }
            cmp.push_back("(" + un + ")[]");
        }
    }
    if(cmp.empty()) return "unknown";
    sort(cmp.begin(), cmp.end());
    string res="";
    for(size_t i=0; i<cmp.size(); ++i) {
        if(i>0) res+=" | ";
        res+=cmp[i];
    }
    return res;
}

string gun(const string& bas, unordered_set<string>& usn) {
    if(usn.find(bas)==usn.end()) {
        usn.insert(bas);
        return bas;
    }
    int suf=2;
    while(1) {
        string cnd=bas+to_string(suf);
        if(usn.find(cnd)==usn.end()) {
            usn.insert(cnd);
            return cnd;
        }
        suf++;
    }
}

string gen(const string& rnm, const string& jst) {
    Jpr prs(jst);
    Jvl rvl=prs.prs();
    Ond* rob=new Ond();
    unordered_set<string> usn;
    usn.insert(rnm);
    if(rvl.typ==Jvl::ARR) {
        for(const auto& e:rvl.avl) {
            rob->nom++;
            if(e.typ==Jvl::OBJ) {
                for(const auto& kv:e.ovl) {
                    rob->fpc[kv.first]++;
                    if(rob->fld.find(kv.first)==rob->fld.end()) rob->fld[kv.first]=new Tnd();
                    mrg(kv.second, rob->fld[kv.first]);
                }
            }
        }
    }
    auto asn=[&](auto& slf, Ond* obj, const string& nm)->void {
        obj->inm=nm;
        for(auto& kv:obj->fld) {
            string key=kv.first;
            Tnd* tnd=kv.second;
            if(tnd->ond) {
                string bas=key;
                bas[0]=toupper(bas[0]);
                string fnm=gun(bas, usn);
                slf(slf, tnd->ond, fnm);
            }
            if(tnd->arr && tnd->arr->ond) {
                string bas=key;
                bas[0]=toupper(bas[0]);
                string fnm=gun(bas, usn);
                slf(slf, tnd->arr->ond, fnm);
            }
        }
    };
    asn(asn, rob, rnm);
    vector<Ond*> alo;
    auto clc=[&](auto& slf, Ond* obj)->void {
        alo.push_back(obj);
        for(auto& kv:obj->fld) {
            if(kv.second->ond) slf(slf, kv.second->ond);
            if(kv.second->arr && kv.second->arr->ond) slf(slf, kv.second->arr->ond);
        }
    };
    clc(clc, rob);
    sort(alo.begin(), alo.end(), [](Ond* a, Ond* b) {
        return a->inm < b->inm;
    });
    string res="";
    for(size_t i=0; i<alo.size(); ++i) {
        if(i>0) res+="\n\n";
        Ond* obj=alo[i];
        if(obj->fld.empty()) {
            res+="export interface " + obj->inm + " {}";
        } else {
            res+="export interface " + obj->inm + " {\n";
            for(auto& kv:obj->fld) {
                string key=kv.first;
                Tnd* tnd=kv.second;
                bool opt=(obj->fpc[key] < obj->nom);
                string ots=opt?"?":"";
                string ts=gts(*tnd);
                res+="  " + key + ots + ": " + ts + ";\n";
            }
            res+="}";
        }
    }
    delete rob;
    return res;
}

bool fst=1;
void solve() {
    string rnm, jst;
    getline(cin, rnm);
    if(!rnm.empty() && rnm.back()=='\r') rnm.pop_back();
    getline(cin, jst);
    if(!jst.empty() && jst.back()=='\r') jst.pop_back();
    if(!fst) cout<<"\n---\n";
    fst=0;
    cout<<gen(rnm, jst);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string ln;
    if(!getline(cin, ln)) return 0;
    
    ll t=0;
    try {t=stoi(ln);} catch(...) {return 0;}
    
    while(t--) solve();
    cout<<'\n';
    
    return 0;
}