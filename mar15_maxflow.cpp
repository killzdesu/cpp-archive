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

#include "maxflow.h"

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
int vs[1010];
vector<int> v[1010];
int G[1010][1010];
int rG[1010][1010];

int dfs_cap(int x, int T, int flow, int cap){
    if(vs[x]==k) return 0;
    vs[x] = k;
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

int maxflow_cap(int s, int t){
    int a, b;
    REP(a, N) REP(b, N) {
        rG[a][b] = G[a][b];
    }
    k = 1;
    int cap=32, flow=32, max_flow=0;
    while(cap > 0){
        k++;
        while(flow = dfs_cap(s, t, (int)2e9, cap)){
            max_flow += flow;
            k++;
        }
        cap/=2;
    }
    return max_flow;
}

int maxflow(int n, int m, int s, int t, Edge *e, int *f){
    int a, b;
    N = n;
    M = m;
    REP(a, N) REP(b, N) rG[a][b] = 0;
    REP(a, M){
        G[e[a].v][e[a].w] = e[a].u;
    }
    b = maxflow_cap(s, t);
    REP(a, M){
        f[a] = G[e[a].v][e[a].w]-rG[e[a].v][e[a].w];
    }
    return b;
}

//
//int main(){
//int a, b, c, d;
//
//
//return 0;
//}
