#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;
int fx, fy;

struct node{
    int x, y, id;
    bool operator < (const node &b) const{
        if(x!=b.x) return x < b.x;
        return y < b.y;
    }
};

pii p[100010];
set<pii> X[100010], Y[100010];
vector<int> cpx, cpy;
map<int, int> mx, my;
char di[100010];
vector<pair<int, pii> > Ex, Ey;

void solve(int x, int d){
    if(d == 0){
        auto it = X[mx[p[x].fi]].lower_bound({p[x].se, -1});
        it++;
        if(it->se == -1){
            Ey.pb({p[x].fi, {p[x].se, 1e9}});
            return;
        }
        if(di[it->se] == '/') d = 1;
        else d = 3;
        solve(it->se, d);
        return;
    }
    if(d == 2){
        auto it = X[mx[p[x].fi]].lower_bound({p[x].se, -1});
        it--;
        if(it->se == -1){
            Ey.pb({p[x].fi, {p[x].se, -1e9}});
            return;
        }
        if(di[it->se] == '/') d = 3;
        else d = 1;
        solve(it->se, d);
        return;
    }
    if(d == 1){
        auto it = Y[my[p[x].se]].lower_bound({p[x].fi, -1});
        it++;
        if(it->se == -1){
            Ex.pb({p[x].se, {p[x].fi, 1e9}});
            return;
        }
        if(di[it->se] == '/') d = 0;
        else d = 2;
        Ex.pb({p[x].se, {p[x].fi, p[it->se].fi}});
        solve(it->se, d);
        return;
    }
    if(d == 3){
        auto it = Y[my[p[x].se]].lower_bound({p[x].fi, -1});
        it--;
        if(it->se == -1){
            Ex.pb({p[x].se, {-1e9, p[x].fi}});
            return;
        }
        if(di[it->se] == '/') d = 2;
        else d = 0;
        Ex.pb({p[x].se, {p[it->se].fi, p[x].fi}});
        solve(it->se, d);
        return;
    }
}

int main(){
//freopen("optics/2.in", "r", stdin);
int a, b, c, d;
char ss[10];
cin >> N >> fx >> fy;
cpx.pb(fx);
cpy.pb(fy);
p[0] = {fx, fy};
REPI(a, N){
    scanf("%d %d %s", &p[a].fi, &p[a].se, ss);
    di[a] = ss[0];
    cpx.pb(p[a].fi);
    cpy.pb(p[a].se);
}
compress(cpx);
compress(cpy);
REP(a, cpx.size()){
    X[a].insert({-1e9-10, -1});
    X[a].insert({1e9+10, -1});
    mx[cpx[a]] = a;
}
REP(a, cpy.size()){
    Y[a].insert({-1e9-10, -1});
    Y[a].insert({1e9+10, -1});
    my[cpy[a]] = a;
}
X[mx[fx]].insert({fy, 0});
Y[my[fy]].insert({fx, 0});
REPI(a, N){
    X[mx[p[a].fi]].insert(mp(p[a].se, a));
    Y[my[p[a].se]].insert(mp(p[a].fi, a));
}
solve(0, 0);
solve(0, 1);
solve(0, 2);
solve(0, 3);
compress(Ex);
//for(auto p: E){
//    printf("%d %d %d\n", p.fi, p.se.fi, p.se.se);
//}
k = 0;
REP(a, Ex.size()){
    if(Ex[a].se.fi < 0 and 0 < Ex[a].se.se and Ex[a].fi > 0) k++;
}
cout << k;
return 0;
}
