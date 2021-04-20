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

const int LN = 19;
int i, n, k, N, M, K;
vector<int> v[100010];
int cnum, cid[100010], cpos[100010], chead[100010];
int H[100010], P[LN][100010], stree[100010];

struct fenwick{
    int m[2*100010], N;

    void init(int n){
        N = n;
    }

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

int dfs(int x, int prev, int d){
    int a;
    H[x] = d;
    stree[x] = 1;
    P[0][x] = prev;
    REP(a, sz(v[x])){
        if(v[x][a] == prev) continue;
        dfs(v[x][a], x, d+1);
        stree[x] += stree[v[x][a]];
    }
}

void action(int x, int prev, int cost){
    if(chead[cnum] == -1) chead[cnum] = x;
    cid[x] = cnum;
    cpos[x] = i++;

    int a, mxi=-1, C;
    REP(a, v[x].size()){
        if(v[x][a] == prev) continue;
        if(mxi == -1 or stree[mxi] < stree[v[x][a]]){
            mxi = v[x][a];
        }
    }

    if(mxi != -1) action(mxi, x, 0);

    REP(a, v[x].size()){
        if(v[x][a] == prev or v[x][a] == mxi) continue;
        cnum++;
        action(v[x][a], x, 0);
    }
}

int find(int p, int q){
    int a;
    if(H[p] < H[q]) swap(p, q);
    for(a=LN-1;a>=0;a--){
        if(H[p]-(1<<a) >= H[q]) p = P[a][p];
    }
    if(p==q) return p;
    for(a=LN-1;a>=0;a--){
        if(P[a][p]!=-1 and P[a][p] != P[a][q]){
            p = P[a][p];
            q = P[a][q];
        }
    }
    return P[0][p];
}

pii road[100010];

void upd(int p, int q){
    if(p == q) return;
    int a, cp, cq;
    cq = cid[q];
    while(1){
//        printf("> %d\n", p);
        cp = cid[p];
        if(cp == cq){
            if(p == q) break;
            F.update(cpos[q]+2, 1);
            F.update(cpos[p]+2, -1);
            break;
        }
        F.update(cpos[chead[cp]]+1, 1);
        F.update(cpos[p]+2, -1);
        p = P[0][chead[cp]];
    }
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
    road[a] = mp(c, d);
}
REP(a, N+2){
    chead[a] = -1;
    REP(b, LN) P[b][a] = -1;
}
dfs(1, -1, 0);
action(1, 0, 0);

REPI(a, LN-1){
    REPI(b, N){
        if(P[a-1][b] != -1){
            P[a][b] = P[a-1][P[a-1][b]];
        }
    }
}
F.init(100005);
REP(a, N-1){
    if(road[a].fi != P[0][road[a].se]){
        swap(road[a].fi, road[a].se);
    }
}
cin >> M;
while(M--){
    scanf("%d %d", &c, &d);
    b = find(c, d);
    upd(c, b);
    upd(d, b);
}
//REPI(a, N) printf("%2d ", a);EL;
//REPI(a, N) printf("%2d ", cid[a]);EL;
//REPI(a, N) printf("%2d ", cpos[a]);EL;
REP(a, N-1){
    printf("%d ", F.query(cpos[road[a].se]+1));
}
return 0;
}
