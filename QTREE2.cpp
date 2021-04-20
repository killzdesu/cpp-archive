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

struct fenwick{
    int m[2*10010], N;

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

const int LN = 15;
int i, n, k, N, M, K;
char qt[10];
int s[10010];
int P[LN][10010];
int H[10010], stree[10010];
vector<pii> v[10010];
int cid[10010], cnum, chead[10010], cpos[10010];

void reset(){
    int a, b;
    i = 0;
    cnum = 0;
    REP(a, N+4){
        REP(b, LN) P[b][a] = -1;
        v[a].clear();
        chead[a] = -1;
        F.m[a] = 0;
    }
}

void dfs(int x, int prev, int d){
    int a;
    H[x] = d;
    P[0][x] = prev;
    stree[x] = 1;
    REP(a, sz(v[x])){
        if(v[x][a].fi == prev){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        dfs(v[x][a].fi, x, d+1);
        stree[x] += stree[v[x][a].fi];
    }
}

void HLD(int x, int cost){
    cid[x] = cnum;
    if(chead[cnum] == -1) chead[cnum] = x;
    cpos[x] = i;
//    s[i++] = cost;
    F.update(i+1, cost);
    i++;

    int a, mxi=-1, C;
    REP(a, sz(v[x])){
        if(mxi == -1 or stree[mxi] < stree[v[x][a].fi]){
            mxi = v[x][a].fi;
            C = v[x][a].se;
        }
    }
    if(mxi != -1) HLD(mxi, C);

    REP(a, sz(v[x])){
        if(mxi == v[x][a].fi) continue;
        cnum++;
        HLD(v[x][a].fi, v[x][a].se);
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

int sum_path(int p, int q){
    if(p == q) return 0;
    int cp = cid[p], cq = cid[q];
    int sm = 0;
    while(1){
        cp = cid[p];
        if(cp == cq){
            if(p == q) break;
            sm += F.query(cpos[p]+1)-F.query(cpos[q]+1);
            break;
        }
        sm += F.query(cpos[p]+1)-F.query(cpos[chead[cp]]);
        p = P[0][chead[cp]];
    }
    return sm;
}

int find_p(int p, int k){
    int a;
    k--;
    for(a=LN-1;a>=0;a--){
        if(k >= (1<<a)){
            k -= (1<<a);
            p = P[a][p];
        }
    }
    return p;
}

int main(){
//freopen("QTREE2.txt", "r", stdin);
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> N;
    reset();
    REP(a, N-1){
        scanf("%d %d %d", &c, &d, &b);
        v[c].pb(mp(d, b));
        v[d].pb(mp(c, b));
    }
    dfs(1, -1, 0);
    F.init(N+3);
    HLD(1, -1);

    REPI(a, LN){
        REPI(b, N){
            if(P[a-1][b] != -1) P[a][b] = P[a-1][P[a-1][b]];
        }
    }

//    REPI(a, N)printf("%2d ", a);EL;
//    REPI(a, N)printf("%2d ", cpos[a]);printf("\t cpos");EL;
//    REPI(a, N)printf("%2d ", cid[a]);printf("\t cid");EL;

    while(1){
        scanf("%s", qt);
        if(qt[1] == 'O') break;
        if(qt[0] == 'D'){
            scanf("%d %d", &c, &d);
            b = LCA(c, d);
            printf("%d\n", sum_path(c, b)+sum_path(d, b));
        }
        if(qt[0] == 'K'){
            scanf("%d %d %d", &c, &d, &k);
            b = LCA(c, d);
            if(H[c]-H[b]+1 == k){
                printf("%d\n", b);
            }
            else if(H[c]-H[b]+1 > k){
                b = find_p(c, k);
                printf("%d\n", b);
            }
            else {
                b = find_p(d, H[c]+H[d]-2*H[b]+2-k);
                printf("%d\n", b);
            }
        }
    }
}



return 0;
}
