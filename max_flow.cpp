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
int vs[100010];
vector<int> v[1010];
int G[1010][1010];
int rG[1010][1010];


int dfs(int x, int T, int flow){
    if(vs[x]) return 0;
    vs[x] = true;
    if(x == T) return flow;
    int F;
    for(int a=0; a<N; a++){
        int u = a;
        if(rG[x][u] == 0) continue;
        F = dfs(u, T, min(flow, rG[x][u]));
        if(F){
            rG[x][u] -= F;
            rG[u][x] += F;
            return F;
        }
    }
    return 0;
}

int dfs_cap(int x, int T, int flow, int cap){
    if(vs[x]) return 0;
    vs[x] = true;
    if(x == T) return flow;
    int F;
    for(int a=0; a<N; a++){
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

int maxflow(int s, int t){
    int a, b;
    REP(a, N) REP(b, N) {
        rG[a][b] = G[a][b];
    }
    int flow, max_flow=0;
    while(flow = dfs(s, t, (int)2e9)){
        max_flow += flow;
        fill(vs, vs+N+1, 0);
    }
    return max_flow;
}

int maxflow_cap(int s, int t){
    int a, b;
    REP(a, N) REP(b, N) {
        rG[a][b] = G[a][b];
    }
    int cap=32, flow=32, max_flow=0;
    while(cap > 0){
        fill(vs, vs+N+1, 0);
        while(flow = dfs_cap(s, t, (int)2e9, cap)){
            max_flow += flow;
            fill(vs, vs+N+1, 0);
        }
        cap/=2;
    }
    return max_flow;
}


int main(){
int a, b, c, d;
int graph[6][6] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
N = 6;
REP(a, N) REP(b, N){
    G[a][b] = graph[a][b];
    if(G[a][b] !=0) v[a].pb(b);
}
//cout << maxflow(0, 5);
//EL;
cout << maxflow_cap(0, 5);
//EL;
//cout << fordFulkerson(graph, 0, 5);

return 0;
}
