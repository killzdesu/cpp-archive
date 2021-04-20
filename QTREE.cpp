#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

const int LN = 15;
vector<pii> v[10010], e[10010];
int P[LN][10010];
char qtype[10];
int cnum, chead[10010], cpos[10010], cid[10010], csize[10010];
int H[10010], child[10010], s[10010];
pii E[10010];

void reset(){
    int a, b;
    cnum = 0;
    i = 0;
    REPI(a, N){
        REP(b, LN){
            P[b][a] = -1;
        }
        H[a] = 0;
        v[a].clear();
        child[a] = 0;
        chead[a] = -1;
    }
}

void get_input(){
    int a, b, c, d;
    REP(a, N-1){
        scanf("%d %d %d", &c, &d, &b);
        v[c].pb(mp(d, b));
        v[d].pb(mp(c, b));
        E[a] = mp(c, d);
    }
}

int LCA(int p, int q){
    int a;
    if(H[p] < H[q]) swap(p, q);
    for(a=LN-1;a>=0;a--){
        if(H[p]-(1<<a) >= H[q]) p = P[a][p];
    }
    if(p == q) return p;
    for(a=LN-1;a>=0;a--){
        if(P[a][p] != -1 and P[a][p] != P[a][q]){
            p = P[a][p];
            q = P[a][q];
        }
    }
    return P[0][p];
}

void dfs(int x, int prev, int d){
    P[0][x] = prev;
    H[x] = d;
    child[x] = 1;
    for(int a=0;a<sz(v[x]);a++){
        if(v[x][a].fi == prev){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        dfs(v[x][a].fi, x, d+1);
        child[x] += child[v[x][a].fi];
    }
}

void HLD(int p, int cost){
    if(chead[cnum] == -1){
        chead[cnum] = p;
    }
    cid[p] = cnum;
    cpos[p] = i;
    s[i++] = cost;

    int mxi=-1, C, a;
    REP(a, sz(v[p])){
        if(mxi == -1 or child[v[p][a].fi] > child[mxi]){
            mxi = v[p][a].fi;
            C = v[p][a].se;
        }
    }
    if(mxi != -1){
        HLD(mxi, C);
    }
    REP(a, sz(v[p])){
        if(v[p][a].fi != mxi){
            cnum++;
            HLD(v[p][a].fi, v[p][a].se);
        }
    }
}

struct tree{
    int val, lo, hi;
}m[10010*6];

void make_tree(int key, int lo, int hi){
    m[key].lo = lo;
    m[key].hi = hi;
    if(lo == hi-1){
        m[key].val = s[lo];
        return;
    }
    make_tree(key*2, lo, (lo+hi)/2);
    make_tree(key*2+1, (lo+hi)/2, hi);
    m[key].val = m[key*2].val > m[key*2+1].val ? m[key*2].val : m[key*2+1].val;
}


int query_tree(int key, int lo, int hi){
    if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
    if(lo >= m[key].hi or hi <= m[key].lo) return -2e9;
    return max(query_tree(key*2, lo, hi), query_tree(key*2+1, lo, hi));
}

void update_tree(int key, int t, int val){
    if(m[key].lo > t or t >= m[key].hi) return;
    if(m[key].lo == m[key].hi-1){
        m[key].val = val;
        return;
    }
    update_tree(key*2, t, val);
    update_tree(key*2+1, t, val);
    m[key].val = max(m[key*2].val, m[key*2+1].val);
}

int query(int u, int v){
    if(u == v) return 0;
    int uc, vc, a, ans=-1;
    vc = cid[v];
    while(true){
        uc = cid[u];
        if(uc == vc){
            if(u == v) break;
//            printf("q[%d-%d] from %d to %d\n", u, v, cpos[v], cpos[u]);
            ans = max(ans, query_tree(1, cpos[v]+1, cpos[u]+1));
            break;
        }
        ans = max(ans, query_tree(1, cpos[chead[uc]], cpos[u]+1));
        u = P[0][chead[uc]];
    }
    return ans;
}

int main(){
//freopen("QTREE.txt", "r", stdin);
int a, b, c, d;
int R;
cin >> R;
while(R--){
    cin >> N;
    reset();
    get_input();
    dfs(1, -1, 0);
    REPI(a, LN-1){
        REPI(b, N){
            if(P[a-1][b] != -1){
                P[a][b] = P[a-1][P[a-1][b]];
            }
        }
    }
    HLD(1, -1);
    make_tree(1, 0, i);

    REP(a, N-1){
        if(E[a].fi != P[0][E[a].se]) swap(E[a].fi, E[a].se);
    }

//    REPI(a, N)printf("%2d ", a);EL;
//    REPI(a, N)printf("%2d ", cpos[a]);printf("\t cpos");EL;
//    REPI(a, N)printf("%2d ", cid[a]);printf("\t cid");EL;

    while(true){
        scanf("%s", qtype);
        if(qtype[0] == 'D') break;
        scanf("%d %d", &c, &d);
        if(qtype[0] == 'Q'){
            b = LCA(c, d);
//            printf("%d: ", b);
            printf("%d\n", max(query(c, b), query(d, b)));
        }
        else {
            update_tree(1, cpos[E[c-1].se], d);
        }
    }
}



return 0;
}
