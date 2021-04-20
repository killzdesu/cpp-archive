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
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;

struct fenwick{
    ll m[30010];

    void update(int x, ll val){
        while(x <= N+5){
            m[x] += val;
            x += (x&-x);
        }
    }

    ll query(int x) {
        ll sum = 0;
        while (x > 0){
            sum += m[x];
            x -= (x & -x);
        }
        return sum;
    }

}F[15];

int chead[30010], cnum, cid[30010], cpos[30010];
vector<int> chain[30010];
int head[30010], stree[30010], h[30010];
int cnt[15][30010];
int GRP[30010];
ll co[30010];
vector<pii> v[30010];
ll sumg[15];

void dfs(int x, int par, int D){
    stree[x] = 1;
    h[x] = D;
    for(auto u: v[x]){
        if(u.fi == par) continue;
        dfs(u.fi, x, D+1);
        stree[x] += stree[x];
    }
}

void hld(int x, int par, int cost){
    cid[x] = cnum;
    if(chead[cnum] == -1) chead[cnum] = x;
    chain[cnum].pb(x);
    cpos[x] = ++i;
    co[x] = cost;

    int mx = -1, C;
    for(auto u: v[x]){
        if(u.fi == par) continue;
        if(mx == -1 or stree[mx] < stree[u.fi]){
            mx = u.fi;
            C = u.se;
        }
    }

    if(mx != -1) hld(mx, x, C+cost);

    for(auto u: v[x]){
        if(u.fi == par or u.fi == mx) continue;
        cnum++;
        hld(u.fi, x, cost+u.se);
    }
}

map<ll, int> m;

void add(int g, int x){
    //update in chain
    int beginc = cpos[chead[cid[x]]];
    int endc = beginc + chain[cid[x]].size() - 1;
    int lo=cpos[chead[cid[x]]], hi, mi;
    hi = lo + chain[cid[x]].size()-1;
    F[g].update(cpos[x], co[x]);
    cnt[g][cid[x]]++;
    if(cnt[g][cid[x]] < 2) goto NO_UPDATE;
    while(lo < hi){
        mi = (lo+hi)/2;
        if(F[g].query(mi) > F[g].query(beginc-1)) hi = mi;
        else lo = mi+1;
    }
    int first = lo;
    while(lo < hi){
        mi = (lo+hi+1)/2;
        if(F[g].query(mi) < F[g].query(endc)) lo = mi;
        else hi = mi-1;
    }
    int last = lo+1;

    NO_UPDATE:;


}

int main(){
freopen("avgdist.txt", "r", stdin);
int a, b, c, d;
int TT;
cin >> N >> M;
REPI(a, N){
    scanf("%d", &GRP[a]);
}
REPI(a, N-1){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb({d, b});
    v[d].pb({c, b});
}
dfs(1, -1, 1);
hld(1, -1, 0);
cpos[0] = N+1;

vector<ll> cp;
ll ori[30010];

REPI(a, N) cp.pb(co[a]);
compress(cp);
REP(a, cp.size()){
    m[cp[a]] = a+1;
    ori[a+1] = cp[a];
}



//REPI(a, N) printf("%2d ", a); EL;
//REPI(a, N) printf("%2d ", co[a]); EL;
//REPI(a, N) printf("%2d ", cid[a]); EL;
//REPI(a, N) printf("%2d ", cpos[a]); EL;



return 0;
}
