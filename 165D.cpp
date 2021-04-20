#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define All(x) (x).begin(),(x).end()
#define compress(x) {sort(All(x));(x).resize(distance((x).begin, unique(All(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
const int LN = 18;
vector<pii> v[100010];
pii E[100010];
int cid[100010], cpos[100010], cnum, chead[100010];
int H[100010], P[LN][100010], stree[100100], s[100010];

void dfs(int x, int prev, int d){
    stree[x] = 1;
    H[x] = d;
    P[0][x] = prev;
    int a;
    REP(a, sz(v[x])){
        if(v[x][a].fi == prev) continue;
        dfs(v[x][a].fi, x, d+1);
        stree[x] += stree[v[x][a].fi];
    }
}

struct fenwick{
    int m[2*100010];
    int N;
    fenwick(){N = 100005;}

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
}F;

void HLD(int x, int prev){
    int a, b;
    if(chead[cnum] == -1) chead[cnum] = x;
    cid[x] = cnum;
//    F.update(i+1, 1);
    s[i] = 1;
    cpos[x] = i++;

    int mxi=-1, C;
    REP(a, sz(v[x])){
        if(v[x][a].fi == prev) continue;
        if(mxi == -1 or stree[mxi] < stree[v[x][a].fi]){
            mxi = v[x][a].fi;
        }
    }
    if(mxi != -1) HLD(mxi, x);

    REP(a, sz(v[x])){
        if(v[x][a].fi == prev or v[x][a].fi == mxi) continue;
        cnum++;
        HLD(v[x][a].fi, x);
    }
}

int LCA(int p, int q){
    if(H[p] < H[q]) swap(p, q);
    int a;
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

int query(int p, int q){
    if(p == q) return 0;
    int a, b, cp, cq = cid[q];
    int sum = 0;
    while(1){
        cp = cid[p];
        if(cp == cq){
            if(p == q) break;
            sum += F.query(cpos[p]+1)-F.query(cpos[q]+1);
            break;
        }
        sum += F.query(cpos[p]+1)-F.query(cpos[chead[cp]]);
        p = P[0][chead[cp]];
    }
    return sum;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    E[a+1] = mp(c, d);
    v[c].pb(mp(d, 1));
    v[d].pb(mp(c, 1));
}
REP(a, LN) REP(b, N+2) P[a][b] = -1;
REPI(a, N) chead[a] = -1;

dfs(1, -1, 1);
HLD(1, -1);

REPI(a, N-1){
    if(E[a].fi != P[0][E[a].se]) swap(E[a].fi, E[a].se);
}

REPI(a, LN-1){
    REPI(b, N){
        if(P[a-1][b] != -1) P[a][b] = P[a-1][P[a-1][b]];
    }
}

//REPI(a, N) printf("%2d ", a);EL;
//REPI(a, N) printf("%2d ", cid[a]);EL;
//REPI(a, N) printf("%2d ", cpos[a]);EL;

cin >> M;
while(M--){
    scanf("%d", &b);
    if(b == 1){
        scanf("%d", &c);
        F.update(cpos[E[c].se]+1, -1);
    }
    else if(b == 2){
        scanf("%d", &c);
        F.update(cpos[E[c].se]+1, 1);
    }
    else {
        scanf("%d %d", &c, &d);
        b = LCA(c, d);
        int t = query(c, b)+query(d, b);
        printf("%d\n", t>0?-1:H[c]+H[d]-2*H[b]);
    }
}

return 0;
}
