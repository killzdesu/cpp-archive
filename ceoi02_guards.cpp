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
vector<pii> E;
vector<int> ER;
int R[1200][1200];
int G[1200][1200];
int vs[1200];
vector<int> v[1200];

int dfs(int x, int T, int flow){
    if(vs[x]) return 0;
    int u;
    vs[x] = 1;
//    printf("%d -- %d\n", x, flow);
    if(x == T) return flow;
    int a, c;
    REP(u, K){
//        int u = v[x][a];
        if(R[x][u] <= 0) continue;
        c = dfs(u, T, min(flow, R[x][u]));
        if(c){
            R[x][u] -= c;
            R[u][x] += c;
            return c;
        }
    }
    return 0;
}

int maxflow(int s, int t){
    int a, b;
    REP(a, K) REP(b, K){
        R[a][b] = G[a][b];
    }
    int max_flow = 0, flow;
    while(flow = dfs(s, t, 2e9)){
        max_flow += flow;
        fill(vs, vs+K+1, 0);
    }
    return max_flow;
}

int ta[230][230];
int X[230][230], Y[230][230], xx[1200], yy[1200];

int main(){
//freopen("guards\\guards.in2", "r", stdin);
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    REP(b, M) cin >> ta[a][b];
}
int k = 0;
REP(a, N) REP(b, M){
    if(ta[a][b] == 2) continue;
    if(b == 0 or ta[a][b-1] == 2){
        k++;
    }
    X[a][b] = k;
    xx[k] = a;
}
REPI(a, k){
    G[0][a] = 1;
}
i = k;
K = k;
REP(b, M) REP(a, N){
    if(ta[a][b] == 2) continue;
    if(a == 0 or ta[a-1][b] == 2){
        k++;
    }
    Y[a][b] = k;
    yy[k] = b;
}
k++;
for(a=K+1;a<k;a++){
    G[a][k] = 1;
}
K = k+1;
REP(a, N) REP(b, M){
    if(ta[a][b] == 0){
        G[X[a][b]][Y[a][b]] = 1;
    }
}
//cout << K;
//return 0;
REP(a, K) for(b=a+1;b<K;b++){
    if(G[a][b] or G[b][a]){
        v[a].pb(b);
        v[b].pb(a);
    }
}
//return 0;
cout << maxflow(0, k);
return 0;
printf("\n");
REP(a, sz(v[0])){
    int u = v[0][a];
    if(R[0][u] != 0) continue;
    REP(b, sz(v[u])){
        int w = v[u][b];
        if(G[u][w] == 1 and R[u][w] == 0){
            printf("%d %d\n", xx[u]+1, yy[v[u][b]]+1);
        }
    }
}


return 0;
}
