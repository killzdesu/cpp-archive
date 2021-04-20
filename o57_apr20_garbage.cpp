#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
pair<int, pii> e[100010];
int LN=14;
int t[15][10010];
int P[15][10010];
int H[10010];
int head[10010];
vector<pii> v[10010];
int root[10010];
int root_p[10010];

int fh(int x){
    if(head[x] != x) head[x] = fh(head[x]);
    return head[x];
}

void make_tree(int x, int D, int pt){
    int a;
    H[x] = D;
    root_p[x] = pt;
    REP(a, sz(v[x])){
        if(v[x][a].fi == root[x]){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        root[v[x][a].fi] = x;
        make_tree(v[x][a].fi, D+1, v[x][a].se);
    }
}

int LCA(int p, int q){
    int a, b, c;
    if(H[p] < H[q]) swap(p, q);
    for(a=LN;a>=0;a--){
        if(H[p]-(1<<a) >= H[q]){
            p = P[a][p];
        }
    }
    if(p == q) return p;
    for(a=LN;a>=0;a--){
        if(P[a][p]!=-1 and P[a][p] != P[a][q]){
            p = P[a][p];
            q = P[a][q];
        }
    }
    return P[0][p];
}

int max_path(int p, int q){
    if(p == q) return 0;
    int mx = 0;
    for(int a=LN;a>=0;a--){
        if(P[a][p] != q){
            mx = max(mx, t[a][p]);
            p = P[a][p];
        }
    }
    return max(mx, t[0][p]);
//    int k = (int)floor(log2(l));
//    int y=x;
//    for(int a=LN;a>=0;a--){
//        if(H[y]-(1<<a) >= H[x]-l+(1<<k)) y = P[a][y];
//    }
//    return max(t[k][x], t[k][y]);
}

int main(){
//freopen("in.in", "r", stdin);
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d %d", &e[a].se.fi, &e[a].se.se, &e[a].fi);
}
sort(e, e+M);
REPI(a, N) head[a] = a;
k = 0;
a = 0;
int x, y;
for(a=0;a<M;a++){
    x=e[a].se.fi;
    y=e[a].se.se;
    if(fh(x)==fh(y)){
        a++;
        continue;
    }
    k++;
    head[fh(x)] = fh(y);
    v[x].pb(mp(y, e[a].fi));
    v[y].pb(mp(x, e[a].fi));
    a++;
}
//return 0;
make_tree(1, 1, -2e9);
root[1] = -1;
REP(a, LN+1)REPI(b, N) P[a][b] = -1;
REPI(a, N) P[0][a] = root[a];
REPI(a, LN){
    REPI(b, N){
        if(P[a-1][b]!=-1){
            P[a][b] = P[a-1][P[a-1][b]];
        }
    }
}
REP(a, LN+1)REPI(b, N){
    t[a][b] = -2e9;
}
REPI(a, N) t[0][a] = root_p[a];
REPI(a, LN){
    REPI(b, N){
        if(P[a][b] != -1) t[a][b] = max(t[a-1][b], t[a-1][P[a-1][b]]);
    }
}
cin >> K;
while(K--){
    scanf("%d %d", &c, &d);
    b = LCA(c, d);
    a = max_path(c, H[c]-H[b]);
    a = max(a, max_path(d, H[d]-H[b]));
    printf("%d\n", a);
}

return 0;
}
