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

int ma[40][40];
char chk[40][40];
int G[1000][1000];
int rG[1000][1000];
vector<int> v[1000];
pii p[1000];
int vs[1010];

int dfs_cap(int x, int T, int flow, int cap){
    if(vs[x]==1) return 0;
    vs[x] = 1;
    if(x == T) return flow;
    int F;
    for(int a=0; a<k; a++){
        int u = a;
        if(rG[x][u] < cap) continue;
        F = dfs_cap(u, T, min(flow, rG[x][u]), cap);
        if(F){
            rG[x][u] -= F;
            rG[u][x] += F;
            return F;
        }
    }
    return 0;
}

int maxflow_cap(int s, int t){
    int a, b;
    REP(a, k) REP(b, k) {
        rG[a][b] = G[a][b];
    }
    int cap=2e8, flow, max_flow=0;
    while(cap > 0){
        fill(vs, vs+k+1, 0);
        while(flow = dfs_cap(s, t, (int)2e9, cap)){
            max_flow += flow;
            fill(vs, vs+k+1, 0);
        }
        cap/=2;
    }
    return max_flow;
}

int main(){
int a, b, c, d;
cin >> N;
k = 1;
int cnt = 0;
REP(a, N) scanf("%s", chk[a]);
REP(a, N){
    REP(b, N){
        if(chk[a][b] == '#') cnt++;
        p[k] = mp(a, b);
        ma[a][b] = k++;
    }
}
REP(a, N) REP(b, N){
    if(chk[a][b] == '.' or (a+b)%2==1) continue;
//    printf("%d %d << \n", a, b);
    if(a!=0 and chk[a-1][b]!='.') v[ma[a][b]].pb(ma[a-1][b]);
    if(a!=N-1 and chk[a+1][b]!='.') v[ma[a][b]].pb(ma[a+1][b]);
    if(b!=0 and chk[a][b-1]!='.') v[ma[a][b]].pb(ma[a][b-1]);
    if(b!=N-1 and chk[a][b+1]!='.') v[ma[a][b]].pb(ma[a][b+1]);
}
for(a=1;a<k;a++){
    if((p[a].fi+p[a].se)%2 == 0){
        v[0].pb(a);
//        v[a].pb(0);
    }
    else {
        v[a].pb(k);
//        v[k].pb(a);
    }
}
k++;
REP(a, k){
    REP(b, sz(v[a])){
//        if(a!=0 and a%2==0 and v[a][b]!=k-1) continue;
//        printf("%d -> %d\n", a, v[a][b]);
        G[a][v[a][b]] = 1;
    }
}
c = maxflow_cap(0, k-1);
if(c < cnt/2) {
    cout << "no solution";
    return 0;
}
REP(a, v[0].size()){
    int u = v[0][a];
    REP(b, v[u].size()){
        int w = v[u][b];
        if(G[u][w] == 1 and rG[u][w] == 0){
            printf("%d %d %d %d\n", p[u].fi+1, p[u].se+1, p[w].fi+1, p[w].se+1);
        }
    }
}
return 0;
}
