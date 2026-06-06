#include <bits/stdc++.h>
#include <json/json.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

struct Pnt { double x, y; };

double dst(Pnt a, Pnt b) { 
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); 
}

struct Pkg {
    string id; double x, y, wt, dl; bool del;
};

struct Drn {
    string id; double mpl, ct;
};

struct Nfz { 
    Pnt c; double r, ts, te; 
};

void slv() {
    string in((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    if(in.empty()) { cout<<"{\"flight_manifest\":[]}\n"; return; }

    Json::Value dat;
    Json::CharReaderBuilder rb;
    string err;
    istringstream ss(in);
    
    if(!Json::parseFromStream(rb, ss, &dat, &err)) {
        cout<<"{\"flight_manifest\":[]}\n";
        return;
    }

    try {
        double mw=dat["map_size"][0].asDouble();
        double mh=dat["map_size"][1].asDouble();
        Pnt wh={mw/2.0, mh/2.0};

        Json::Value drs=dat["drones"];
        Json::Value dlv=dat["deliveries"];
        Json::Value fm(Json::arrayValue);

        vector<Pkg> pk;
        for(int i=0; i<(int)dlv.size(); ++i) {
            pk.push_back({
                dlv[i]["id"].asString(), dlv[i]["x"].asDouble(),
                dlv[i]["y"].asDouble(), dlv[i]["weight"].asDouble(),
                dlv[i]["deadline"].asDouble(), 0
            });
        }

        vector<Drn> fl;
        for(int i=0; i<(int)drs.size(); ++i) {
            fl.push_back({
                drs[i]["id"].asString(), drs[i]["max_payload"].asDouble(), 0.0 
            });
        }

        vector<Nfz> nz;
        Json::Value nf=dat.isMember("no_fly_zones")?dat["no_fly_zones"]:Json::Value(Json::arrayValue);
        for(int i=0; i<(int)nf.size(); ++i) {
            Nfz n;
            n.ts=nf[i]["T_start"].asDouble();
            n.te=nf[i]["T_end"].asDouble();
            if(nf[i]["shape"].asString()=="circle") {
                n.c.x=nf[i]["center"][0].asDouble();
                n.c.y=nf[i]["center"][1].asDouble();
                n.r=nf[i]["radius"].asDouble();
            } else {
                double x1=nf[i]["corners"][0][0].asDouble();
                double y1=nf[i]["corners"][0][1].asDouble();
                double x2=nf[i]["corners"][1][0].asDouble();
                double y2=nf[i]["corners"][1][1].asDouble();
                n.c.x=(x1+x2)/2.0; n.c.y=(y1+y2)/2.0;
                n.r=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))/2.0;
            }
            n.r+=1.0;
            nz.push_back(n);
        }

        auto hit=[&](Pnt a, Pnt b, double t, Pnt &wp)->bool {
            for(auto &n:nz) {
                double l=dst(a,b);
                if(t+l<n.ts || t>n.te) continue;
                double l2=l*l, u=0;
                if(l2>0) u=max(0.0, min(1.0, ((n.c.x-a.x)*(b.x-a.x) + (n.c.y-a.y)*(b.y-a.y))/l2));
                Pnt e={a.x+u*(b.x-a.x), a.y+u*(b.y-a.y)};
                if(dst(n.c, e)<=n.r) {
                    double cx=e.x-n.c.x, cy=e.y-n.c.y, cl=sqrt(cx*cx+cy*cy);
                    if(cl<0.001) {
                        cx=-(b.y-a.y); cy=(b.x-a.x);
                        cl=sqrt(cx*cx+cy*cy);
                    }
                    wp={n.c.x+(cx/cl)*(n.r), n.c.y+(cy/cl)*(n.r)};
                    return 1;
                }
            }
            return 0;
        };

        sort(pk.begin(), pk.end(), [](const Pkg& a, const Pkg& b) {
            if(a.dl!=b.dl) return a.dl<b.dl;
            return a.wt>b.wt;
        });

        for(auto& dr:fl) {
            Json::Value pth(Json::arrayValue);
            for(auto& p:pk) {
                if(p.del) continue; 
                if(p.wt>dr.mpl) continue; 
                
                Pnt dt={p.x, p.y}, w1={0,0}, w2={0,0};
                bool h1=hit(wh, dt, dr.ct, w1);
                double d1=h1?(dst(wh, w1)+dst(w1, dt)):dst(wh, dt);
                
                bool h2=hit(dt, wh, dr.ct+d1, w2);
                double d2=h2?(dst(dt, w2)+dst(w2, wh)):dst(dt, wh);
                
                double eo=d1*(1.0+p.wt), er=d2*1.0; 
                if(eo+er>500.0) continue; 
                if(dr.ct+d1>p.dl) continue; 
                
                Json::Value pkp;
                pkp["x"]=wh.x; pkp["y"]=wh.y; pkp["t"]=dr.ct;
                pkp["action"]="PICKUP";
                Json::Value ar(Json::arrayValue); ar.append(p.id);
                pkp["delivery_ids"]=ar;
                pth.append(pkp);
                
                if(h1) {
                    dr.ct+=dst(wh, w1);
                    Json::Value pw1;
                    pw1["x"]=w1.x; pw1["y"]=w1.y; pw1["t"]=dr.ct;
                    pw1["action"]="WAYPOINT";
                    pth.append(pw1);
                    dr.ct+=dst(w1, dt);
                } else dr.ct+=d1;

                Json::Value pdl;
                pdl["x"]=dt.x; pdl["y"]=dt.y; pdl["t"]=dr.ct;
                pdl["action"]="DELIVER";
                pdl["delivery_id"]=p.id;
                pth.append(pdl);
                
                if(h2) {
                    dr.ct+=dst(dt, w2);
                    Json::Value pw2;
                    pw2["x"]=w2.x; pw2["y"]=w2.y; pw2["t"]=dr.ct;
                    pw2["action"]="WAYPOINT";
                    pth.append(pw2);
                    dr.ct+=dst(w2, wh);
                } else dr.ct+=d2;

                Json::Value prt;
                prt["x"]=wh.x; prt["y"]=wh.y; prt["t"]=dr.ct;
                prt["action"]="RETURN";
                pth.append(prt);
                
                p.del=1;
            }
            if(pth.size()>0) {
                Json::Value me;
                me["drone_id"]=dr.id;
                me["path"]=pth;
                fm.append(me);
            }
        }

        Json::Value out;
        out["flight_manifest"]=fm;
        Json::StreamWriterBuilder wb;
        wb["indentation"]="";
        cout<<Json::writeString(wb, out)<<endl;

    } catch(...) {
        cout<<"{\"flight_manifest\":[]}\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    slv();
    return 0;
}